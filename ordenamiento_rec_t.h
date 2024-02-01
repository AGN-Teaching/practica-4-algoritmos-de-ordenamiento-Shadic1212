#ifndef ORDENAMIENTO_REC_T_H
#define ORDENAMIENTO_REC_T_H

#include "ordenamiento_t.h"

void merge(int A[], int inicio, int medio, int fin) {
    int *aux = new int[fin - inicio + 1];
    int i = inicio;
    int j = medio + 1;
    int h = 0;

    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
    
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete [] aux;
}

void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(A, inicio, medio);
        merge_sort(A, medio + 1, fin);
        merge(A, inicio, medio, fin);
    }
}

int partition(int A[], int p, int r) {
    int pivote = A[r];
    int ultimo = p - 1;

    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

#endif /* ORDENAMIENTO_REC_T_H */
