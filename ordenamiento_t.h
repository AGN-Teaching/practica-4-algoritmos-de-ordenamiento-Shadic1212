#ifndef ORDENAMIENTO_T_H
#define ORDENAMIENTO_T_H

void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

void insertion_sort(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int k = A[j];
        int i = j - 1;
 
        while (i >= 0 && A[i] > k) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = k;
    }
}

void selection_sort(int A[], int n) {
    for (int j = 0; j < n-1; j++) {
        int menor = j;
 
        for (int i = j+1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
            }
        }
        intercambiar(A, j, menor);
    }
}

void bubblesort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                intercambiar(A, j, j-1);
            }
        }
    }
}

#endif /* ORDENAMIENTO_T_H */
