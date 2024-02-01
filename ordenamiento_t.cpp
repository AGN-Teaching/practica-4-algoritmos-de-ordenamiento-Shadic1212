#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

// Función para ejecutar un algoritmo de ordenamiento y medir su tiempo
void ejecutar_algoritmo(std::vector<int>& A, std::vector<int>& B, char algoritmo, double& tiempo) {
    // Usamos high_resolution_clock para medir el tiempo con mayor precisión
    auto inicio = std::chrono::high_resolution_clock::now();

    // Seleccionamos el algoritmo de ordenamiento según la opción proporcionada
    switch (algoritmo) {
        case 'i':
            insertion_sort(&B[0], B.size());
            break;
        case 's':
            selection_sort(&B[0], B.size());
            break;
        case 'b':
            bubblesort(&B[0], B.size());
            break;
        case 'm':
            merge_sort(&B[0], 0, B.size() - 1);
            break;
        case 'q':
            quicksort(&B[0], 0, B.size() - 1);
            break;
        default:
            std::cerr << "Opción de algoritmo no válida.\n";
            return;
    }

    auto fin = std::chrono::high_resolution_clock::now();
    // Calculamos el tiempo transcurrido en segundos
    tiempo = std::chrono::duration<double>(fin - inicio).count();
}

int main(int argc, char *argv[]) {
    // Verificamos que se proporcionen los argumentos correctos
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <n> <m>\n";
        return 1;
    }

    // Convertimos los argumentos a enteros
    int n = std::stoi(argv[1]);  // Tamaño del arreglo
    int m = std::stoi(argv[2]);  // Número de repeticiones

    // Configuramos el generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10 * n);

    // Variables para almacenar los tiempos
    double total_time_insertion = 0, total_time_selection = 0, total_time_bubble = 0,
           total_time_merge = 0, total_time_quick = 0;
    double total_time_insertion_sq = 0, total_time_selection_sq = 0, total_time_bubble_sq = 0,
           total_time_merge_sq = 0, total_time_quick_sq = 0;

    // Imprimimos información sobre el tamaño del arreglo y el número de repeticiones
    std::cout << "Tamaño del arreglo: " << n << "\n";
    std::cout << "Número de repeticiones: " << m << "\n";

    // Bucle para ejecutar los algoritmos m veces
    for (int i = 0; i < m; i++) {
        // Crear un nuevo arreglo aleatorio
        std::vector<int> A(n);
        for (int &a : A) {
            a = dis(gen);
        }

        // Variables para almacenar el tiempo de cada algoritmo en esta ejecución
        double tiempo_insertion, tiempo_selection, tiempo_bubble, tiempo_merge, tiempo_quick;

        // Copiar el arreglo original para que todos los algoritmos ordenen el mismo conjunto
        std::vector<int> B(A);

        // Ejecutar cada algoritmo y medir el tiempo
        ejecutar_algoritmo(A, B, 'i', tiempo_insertion);
        ejecutar_algoritmo(A, B, 's', tiempo_selection);
        ejecutar_algoritmo(A, B, 'b', tiempo_bubble);
        ejecutar_algoritmo(A, B, 'm', tiempo_merge);
        ejecutar_algoritmo(A, B, 'q', tiempo_quick);

        // Acumular los tiempos para calcular el promedio y la desviación estándar después
        total_time_insertion += tiempo_insertion;
        total_time_insertion_sq += tiempo_insertion * tiempo_insertion;

        total_time_selection += tiempo_selection;
        total_time_selection_sq += tiempo_selection * tiempo_selection;

        total_time_bubble += tiempo_bubble;
        total_time_bubble_sq += tiempo_bubble * tiempo_bubble;

        total_time_merge += tiempo_merge;
        total_time_merge_sq += tiempo_merge * tiempo_merge;

        total_time_quick += tiempo_quick;
        total_time_quick_sq += tiempo_quick * tiempo_quick;

        // Imprimir información sobre la ejecución actual
        std::cout << "** Arreglo No. " << i + 1 << " **\n";
        std::cout << "Creando arreglo de tamaño " << n << "\n";

        // Imprimir información sobre cada algoritmo
        std::cout << "Iniciando ordenamiento con INSERTION SORT... Ordenando... Tiempo: " << tiempo_insertion << " segundos\n";
        std::cout << "Iniciando ordenamiento con SELECTION SORT... Ordenando... Tiempo: " << tiempo_selection << " segundos\n";
        std::cout << "Iniciando ordenamiento con BUBBLE SORT... Ordenando... Tiempo: " << tiempo_bubble << " segundos\n";
        std::cout << "Iniciando ordenamiento con MERGE SORT... Ordenando... Tiempo: " << tiempo_merge << " segundos\n";
        std::cout << "Iniciando ordenamiento con QUICKSORT... Ordenando... Tiempo: " << tiempo_quick << " segundos\n";
    }

    // Calcular promedio y desviación estándar para cada algoritmo
    double avg_time_insertion = total_time_insertion / m;
    double stddev_time_insertion = std::sqrt(total_time_insertion_sq / m - avg_time_insertion * avg_time_insertion);

    double avg_time_selection = total_time_selection / m;
    double stddev_time_selection = std::sqrt(total_time_selection_sq / m - avg_time_selection * avg_time_selection);

    double avg_time_bubble = total_time_bubble / m;
    double stddev_time_bubble = std::sqrt(total_time_bubble_sq / m - avg_time_bubble * avg_time_bubble);

    double avg_time_merge = total_time_merge / m;
    double stddev_time_merge = std::sqrt(total_time_merge_sq / m - avg_time_merge * avg_time_merge);

    double avg_time_quick = total_time_quick / m;
    double stddev_time_quick = std::sqrt(total_time_quick_sq / m - avg_time_quick * avg_time_quick);

    // Imprimir información sobre promedio y desviación estándar
    std::cout << "\nPromedio de tiempos:\n";
    std::cout << "Insertion sort: " << avg_time_insertion << " segundos\n";
    std::cout << "Selection sort: " << avg_time_selection << " segundos\n";
    std::cout << "Bubble sort: " << avg_time_bubble << " segundos\n";
    std::cout << "Merge sort: " << avg_time_merge << " segundos\n";
    std::cout << "Quick sort: " << avg_time_quick << " segundos\n";

    std::cout << "\nDesviación estándar de tiempos:\n";
    std::cout << "Insertion sort: " << stddev_time_insertion << " segundos\n";
    std::cout << "Selection sort: " << stddev_time_selection << " segundos\n";
    std::cout << "Bubble sort: " << stddev_time_bubble << " segundos\n";
    std::cout << "Merge sort: " << stddev_time_merge << " segundos\n";
    std::cout << "Quick sort: " << stddev_time_quick << " segundos\n";

    return 0;
}

