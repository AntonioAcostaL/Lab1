
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura alumnos
typedef struct _Alumno
{
    char nombre[20];
    char apellido[20];
    int matricula;
}Alumno;

//Nodo
typedef struct _Nodo
{
    int data;
    Alumno *nodoAlumno;
    struct _Nodo *siguiente;
    
}Nodo;

//Lista
typedef struct _ListaSimple
{
    Nodo *head;
    Nodo *tail;
    Nodo *curr;
    int size;
}ListaSimple;


void InicializarLista(ListaSimple *lista);
void PushFront(ListaSimple* lista, Alumno *nuevoAlumno);
void PushBack(ListaSimple* lista, Alumno *nuevoAlumno);
void PushPos(ListaSimple* lista, Alumno *nuevoAlumno, int pos);

void PrintNodo(Nodo *nodo);
int BorrarPos(ListaSimple *lista,int pos);
void MostrarLista(ListaSimple lista);

void GenerarAlumno(Alumno *alumno);
int GenerarNumeroAleatorio(int min, int max);

void AltaBajaAlumnos(ListaSimple *salon);
Alumno* GenerarAlumnoAleatorio();
void LiberarLista(ListaSimple* lista);
void RealizarAltas(ListaSimple* lista, int num_altas);
void RealizarBajas(ListaSimple* lista, int num_bajas);
int ContarAlumnos(const ListaSimple *lista);