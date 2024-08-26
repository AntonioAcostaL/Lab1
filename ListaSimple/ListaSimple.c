#include <stdio.h>
#include <stdlib.h>
#include "./ListaSimpleL1.h"
#include <string.h>
#include <time.h>


// Función para inicializar la lista
void InicializarLista(ListaSimple *lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

// Inserción en Head (PushFront)
void PushFront(ListaSimple* lista, Alumno *nuevoAlumno) {
    // 1. Crear Nodo nuevo
    Nodo* nuevoNodo = (Nodo*)calloc(1,sizeof(Nodo));
    // 2. Asignar dato al Nodo
    nuevoNodo->nodoAlumno = nuevoAlumno;
    // 3. Si lista->Head es NULL
    if (lista->head == NULL) {
        // 3.1 la lista->Tail es igual al nodo nuevo
        lista->tail = nuevoNodo;
        // 3.2 el nodo nuevo->siguiente es igual a nulo
        nuevoNodo->siguiente = NULL;
    } else {
        // 3.3 el nodo nuevo->siguiente es igual a la lista->Head
        nuevoNodo->siguiente = lista->head;
    }
    // 4. Cambiar la dirección de lista->Head al nodo nuevo
    lista->head = nuevoNodo;
    // 5. Incrementar el contador size
    lista->size++;
}

void PushBack(ListaSimple* lista, Alumno *nuevoAlumno) {
    // 1. Crear Nodo nuevo
    Nodo* nuevoNodo = (Nodo*)calloc(1,sizeof(Nodo));
    // 2. Asignar dato al Nodo
    nuevoNodo->nodoAlumno = nuevoAlumno;
    nuevoNodo->siguiente = NULL;
    
    // 3. Si lista->Tail es NULL
    if (lista->tail == NULL) {
        // 3.1 lista->Head es igual al nuevo nodo
        lista->head = nuevoNodo;
    } else {
        // 3.3 lista->Tail->siguiente es igual al nodo nuevo
        lista->tail->siguiente = nuevoNodo;
    }
    // 4. Cambiar la dirección de la cola (lista->Tail) al nodo nuevo
    lista->tail = nuevoNodo;
    // 5. Incrementar el contador size
    lista->size++;
}

// Inserción al medio (PushPos)
void PushPos(ListaSimple* lista, Alumno *nuevoAlumno, int pos) {
    if (pos == 0) {
        // 1.1 Si corresponde entonces PushFront(lista, dato)
        PushFront(lista, nuevoAlumno);
        return;
    }
    if (pos == lista->size) {
        // 2.1 Si corresponde entonces PushBack(lista, dato)
        PushBack(lista, nuevoAlumno);
        return;
    }
    // 3. Crear el nodo nuevo
    Nodo* nuevoNodo = (Nodo*)calloc(1,sizeof(Nodo));
    // 3.2 Asignar dato al nodo nuevo
    nuevoNodo->nodoAlumno = nuevoAlumno;

    // 3.3 Buscar nodo ANT (pos-1)
    Nodo* anterior = lista->head;
    for (int i = 0; i < pos - 1; i++) {
        anterior = anterior->siguiente;
    }
    
    // 3.4 Asignar nuevoNodo->siguiente igual a anterior->siguiente
    nuevoNodo->siguiente = anterior->siguiente;
    // 3.5 Asignar anterior->siguiente igual a nuevoNodo
    anterior->siguiente = nuevoNodo;
    
    // 3.6 Incrementar el contador size
    lista->size++;
}

// Borrar Nodo en una posición específica (BorrarPos)
int BorrarPos(ListaSimple *lista, int pos) {
 if (pos == 0) {
        // 1.1 Crear nodo temporal que guarde lista->Head->siguiente
        Nodo* temp = lista->head->siguiente;
        // 1.2 Borrar lista->Head
        free(lista->head);
        // 1.3 Asignar lista->Head igual al nodo temporal
        lista->head = temp;
        // 1.4 Decrementar el contador lista->size en 1
        lista->size--;
        // 1.5 Regresamos 1
        return 1;
    }
    
    // 2. Buscar el nodo en pos-1 y lo guardamos en un temporal
    Nodo* anterior = lista->head;
    for (int i = 0; i < pos - 1; i++) {
        anterior = anterior->siguiente;
    }
    
    // 3. Buscar el nodo en pos y lo guardamos en una variable (borrar)
    Nodo* borrar = anterior->siguiente;
    
    // 4. Asignar anterior->siguiente igual a borrar->siguiente
    anterior->siguiente = borrar->siguiente;
    
    // 5. Borrar el nodo borrar
    free(borrar);
    
    // 6. Verificamos si pos es igual a lista->size - 1
    if (pos == lista->size - 1) {
        // 6.1 Si lo es, entonces lista->Tail es igual a anterior
        lista->tail = anterior;
    }
    
    // 7. Decrementar el contador lista->size en 1
    lista->size--;
    
    // 8. Regresamos 1
    return 1;
}

// Imprimir Nodo
void PrintNodo(Nodo *nodo) {
    printf("Alumno: %s %s, Matricula: %d -> ", nodo->nodoAlumno->nombre,nodo->nodoAlumno->apellido,nodo->nodoAlumno->matricula);
}

// Mostrar Lista Enlazada (MostrarLista)
void MostrarLista(ListaSimple lista) {
    lista.curr = lista.head;
    while (lista.curr != NULL) {
        PrintNodo(lista.curr);
        lista.curr = lista.curr->siguiente;
    }
}


// Función para generar un alumno aleatorio

Alumno* GenerarAlumnoAleatorio() {
    Alumno* alumno = (Alumno*)malloc(sizeof(Alumno));

    // Letras de la 'a' a la 'j' (10 letras)
    char letras[] = "abcdefghij";
    
    for (int i = 0; i < 19; i++) {
        alumno->nombre[i] = letras[rand() % 10];
        alumno->apellido[i] = letras[rand() % 10];
    }
    alumno->nombre[19] = '\0';  // Asegura que el nombre esté terminado en null
    alumno->apellido[19] = '\0';  // Asegura que el apellido esté terminado en null
    alumno->matricula = 1000 + rand() % 9000;

    return alumno;
}

void LiberarLista(ListaSimple* lista) {
    Nodo* actual = lista->head;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual->nodoAlumno);  // Liberar la memoria del alumno
        free(actual);              // Liberar la memoria del nodo
        actual = siguiente;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

// Función para realizar altas de alumnos
void RealizarAltas(ListaSimple* lista, int num_altas) {
    for (int i = 0; i < num_altas; i++) {
        Alumno* alumno = GenerarAlumnoAleatorio();
        int metodo = rand() % 3;
        if (metodo == 0) {
            PushFront(lista, alumno);
        } else if (metodo == 1) {
            PushBack(lista, alumno);
        } else {
            PushPos(lista, alumno, rand() % lista->size);
        }
    }
}

// Función para realizar bajas de alumnos
void RealizarBajas(ListaSimple* lista, int num_bajas) {
    for (int i = 0; i < num_bajas && lista->size > 0; i++) {
        BorrarPos(lista, rand() % lista->size);
    }
}

int ContarAlumnos(const ListaSimple *lista) {
    int contador = 0;
    Nodo *actual = lista->head;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}