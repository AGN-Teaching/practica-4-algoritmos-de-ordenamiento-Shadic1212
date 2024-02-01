#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include <fstream>  // Incluimos la biblioteca para trabajar con archivos
#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

int main(int argc, char* argv[]) {
    // Agregamos la declaración de la variable start_program
    auto start_program = std::chrono::steady_clock::now();

    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <n> <m>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10 * n);

    std::ofstream archivo_salida("resultados.txt");  // Abrimos el archivo para escritura
    archivo_salida << "#Ejec.\tis_t\tss_t\tbs_t\tms_t\tqs_t\n";  // Encabezado del archivo

    std::vector<double> tiempos_insertion;
    std::vector<double> tiempos_selection;
    std::vector<double> tiempos_bubble;
    std::vector<double> tiempos_merge;
    std::vector<double> tiempos_quicksort;

    for (int i = 0; i < m; i++) {
        std::vector<int> A(n);
        for (int &a : A) {
            a = dis(gen);
        }

        std::vector<int> B(n);
        std::chrono::steady_clock::time_point start, end;
        std::chrono::duration<double> elapsed_seconds;

        // Insertion Sort
        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        insertion_sort(&B[0], B.size());
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        archivo_salida << i + 1 << '\t' << elapsed_seconds.count() << '\t';
        tiempos_insertion.push_back(elapsed_seconds.count());

        // Selection Sort
        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        selection_sort(&B[0], B.size());
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        archivo_salida << elapsed_seconds.count() << '\t';
        tiempos_selection.push_back(elapsed_seconds.count());

        // Bubble Sort
        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        bubblesort(&B[0], B.size());
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        archivo_salida << elapsed_seconds.count() << '\t';
        tiempos_bubble.push_back(elapsed_seconds.count());

        // Merge Sort
        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        merge_sort(&B[0], 0, B.size() - 1);
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        archivo_salida << elapsed_seconds.count() << '\t';
        tiempos_merge.push_back(elapsed_seconds.count());

        // Quick Sort
        std::copy(A.begin(), A.end(), B.begin());
        start = std::chrono::steady_clock::now();
        quicksort(&B[0], 0, B.size() - 1);
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        archivo_salida << elapsed_seconds.count() << '\n';
        tiempos_quicksort.push_back(elapsed_seconds.count());
    }

    // Calcular promedio y desviación estándar
    auto calcular_promedio = [](const std::vector<double>& tiempos) {
        double suma = std::accumulate(tiempos.begin(), tiempos.end(), 0.0);
        return suma / tiempos.size();
    };

    auto calcular_desviacion_estandar = [&calcular_promedio](const std::vector<double>& tiempos, double promedio) {
        double suma_cuadrados = std::accumulate(tiempos.begin(), tiempos.end(), 0.0, [promedio](double acum, double tiempo) {
            return acum + std::pow(tiempo - promedio, 2);
        });
        return std::sqrt(suma_cuadrados / tiempos.size());
    };

    double promedio_insertion = calcular_promedio(tiempos_insertion);
    double desviacion_insertion = calcular_desviacion_estandar(tiempos_insertion, promedio_insertion);
    std::cout << "Promedio de Insertion sort: " << promedio_insertion << " segundos\n";
    std::cout << "Desviación estándar de Insertion sort: " << desviacion_insertion << " segundos\n";

    double promedio_selection = calcular_promedio(tiempos_selection);
    double desviacion_selection = calcular_desviacion_estandar(tiempos_selection, promedio_selection);
    std::cout << "Promedio de Selection sort: " << promedio_selection << " segundos\n";
    std::cout << "Desviación estándar de Selection sort: " << desviacion_selection << " segundos\n";

    double promedio_bubble = calcular_promedio(tiempos_bubble);
    double desviacion_bubble = calcular_desviacion_estandar(tiempos_bubble, promedio_bubble);
    std::cout << "Promedio de Bubble sort: " << promedio_bubble << " segundos\n";
    std::cout << "Desviación estándar de Bubble sort: " << desviacion_bubble << " segundos\n";

    double promedio_merge = calcular_promedio(tiempos_merge);
    double desviacion_merge = calcular_desviacion_estandar(tiempos_merge, promedio_merge);
    std::cout << "Promedio de Merge sort: " << promedio_merge << " segundos\n";
    std::cout << "Desviación estándar de Merge sort: " << desviacion_merge << " segundos\n";

    double promedio_quicksort = calcular_promedio(tiempos_quicksort);
    double desviacion_quicksort = calcular_desviacion_estandar(tiempos_quicksort, promedio_quicksort);
    std::cout << "Promedio de Quick sort: " << promedio_quicksort << " segundos\n";
    std::cout << "Desviación estándar de Quick sort: " << desviacion_quicksort << " segundos\n";

    // Agregamos la declaración de la variable end_program y calculamos el tiempo total del programa
    auto end_program = std::chrono::steady_clock::now();
    auto elapsed_program_seconds = std::chrono::duration_cast<std::chrono::seconds>(end_program - start_program);

    // Imprimimos el tiempo total del programa
    std::cout << "Tiempo total de ejecucion del programa: " << elapsed_program_seconds.count() << " segundos\n";

    return 0;
}
