#include <iostream>
#include <omp.h>

using namespace std;

#define N 1000
#define chunk 100
#define mostrar 10

void arreglo(int* arreglo);

int main() {

    int i;
    int a[N], b[N], c[N];

    for (i = 0; i < N; i++) {
        a[i] = i * 2;
        b[i] = i * 3;
    }

#pragma omp parallel for shared(a, b, c) private(i) schedule(static, chunk)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    cout << "Arreglo A:\n";
    arreglo(a);

    cout << "\nArreglo B:\n";
    arreglo(b);

    cout << "\nArreglo C (A+B):\n";
    arreglo(c);

    return 0;
}

void arreglo(int* arreglo) {
    for (int i = 0; i < mostrar; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
