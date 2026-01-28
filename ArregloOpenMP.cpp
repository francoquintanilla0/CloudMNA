#include <iostream>
#include <omp.h>
#include <cstdlib>

using namespace std;

/* Constantes de precompilación */
#define N 1000        // Tamaño de los arreglos
#define chunk 100     // Tamaño de los pedazos
#define mostrar 10    // Cantidad de elementos a imprimir

/* Prototipo de la función */
void imprimeArreglo(int *arreglo);

int main() {

    int i;

    // Declaración de los arreglos
    int a[N], b[N], c[N];

    // Asignación de valores a los arreglos a y b
    for (i = 0; i < N; i++) {
        a[i] = i * 2;
        b[i] = i * 3;
    }

    // Suma paralela de arreglos con OpenMP
    #pragma omp parallel for shared(a, b, c) private(i) schedule(static, chunk)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Impresión de resultados
    cout << "Arreglo A:" << endl;
    imprimeArreglo(a);

    cout << "\nArreglo B:" << endl;
    imprimeArreglo(b);

    cout << "\nArreglo C (A + B):" << endl;
    imprimeArreglo(c);

    return 0;
}

/* Implementación de la función imprimeArreglo */
void imprimeArreglo(int *arreglo) {
    for (int i = 0; i < mostrar; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
