#include <ListaSimpleL1.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main() {
    srand((int)time(NULL));
    ListaSimple lista;
    InicializarLista(&lista);

    // Altas
    const int max_alumnos = 40;
    const int min_alumnos = 5;
    int num_altas = rand() % (max_alumnos - min_alumnos + 1) + min_alumnos;
    RealizarAltas(&lista, num_altas);

    printf("\nNumero de alumnos despues de altas: %d\n", ContarAlumnos(&lista));

    printf("Lista de alumnos despues de altas:\n");
    MostrarLista(lista);

    // Bajas
    const int min_bajas = 3;
    const int max_bajas = 15;
    int num_bajas = rand() % (max_bajas - min_bajas + 1) + min_bajas;
    RealizarBajas(&lista, num_bajas);

    printf("\nNumero de alumnos despues de bajas: %d\n", ContarAlumnos(&lista));

    printf("\nLista de alumnos despues de bajas:\n");
    MostrarLista(lista);

    LiberarLista(&lista);
    
    return 0;
}