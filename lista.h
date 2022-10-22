#ifndef LISTA_H
#define LISTA_H

typedef struct nodo {
	
    int* dato;
    struct nodo* siguiente;
    struct nodo* anterior;
	
} Nodo;

typedef struct lista
{
    Nodo* cabeza;
    Nodo* cola;
    int size;

} Lista;

//Creamos el nodo.
Nodo* crearNodo ();

//Agregar Nodos al inicio.
void inicioNodo (Lista* lista, Nodo* nuevo);

//Agregar Nodos al final.
void finalNodo (Lista* lista, Nodo* nuevo);		

//Imprimir lista.
void imprimirL (Lista* lista);

//Comprobar si esta vacia.
int vacio (Lista* lista);

#endif
