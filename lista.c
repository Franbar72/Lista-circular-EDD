#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Nodo* nuevo;

int main ()
{

Lista* lista = (Lista*) malloc (sizeof(Lista));
lista->cabeza = NULL;
lista->cola = NULL;
lista->size = 0;

int n, op;
	
	printf ("\n\tLISTAS ENLAZADAS\n");
	printf ("\nDigite la cantidad de datos que desea ingresar: "); scanf ("%d",&n);
	
	while (n != 0){
	    nuevo = crearNodo();
	    printf ("\n(1) Agregar dato al inicio.\n(2) Agregar dato al final.\n");
	    printf ("\nSeleccione opcion a realizar: "); scanf ("%d", &op);
	    
	    if (op == 1)
	    {
	        inicioNodo(lista, nuevo);
	    }
	    else if (op == 2)
	    {
	        finalNodo(lista, nuevo);
	    }
	    
	    n--;
	} 
	
	
	printf ("\n(3) Imprimir Lista.\n(4) Comprobar si esta vacia.\n(5) Finalizar.\n\n");
	scanf ("%d", &op);
	
	switch (op)
	{
		case 3: printf ("\n\tIMPRIMIR LISTA\n\n");
				imprimirL(lista);
				break;
		
		case 4: if (vacio(lista) == 1)
		          { printf("\nLa lista esta vacia.\n"); }
		        else
		          { printf("\nLa lista no esta vacia.\n");}
			break;
				
		case 5: printf ("\n\tFINALIZADO.\n");		
			break;
						
	}  
  return 0;
}


//Funciones:
Nodo* crearNodo (){
	
	int input;
	Nodo* nuevo = NULL;
	nuevo = (Nodo*) malloc (sizeof(Nodo));
	nuevo->dato = malloc(sizeof(int));
	
	printf ("\nIngrese un dato: "); scanf("%d", &input);
	
	if (nuevo != NULL){
	        memcpy(nuevo->dato, &input, sizeof(int));
		nuevo->siguiente = NULL; 
	}
	return nuevo;
}


void inicioNodo (Lista* lista, Nodo* nuevo){
	
	if (nuevo != NULL && lista->size == 0){
	        lista->cabeza = nuevo;
		lista->cola = nuevo;
	}
	else
        {
                nuevo->siguiente = lista->cabeza;
                lista->cabeza->anterior = nuevo;
                lista->cabeza = nuevo;
                lista->cola->siguiente = lista->cabeza;
        }
        
        lista->size = lista->size + 1;
}


void imprimirL (Lista* lista){
	Nodo* aux = lista->cabeza;
	while (aux != NULL){
		printf ("%d ", *(aux->dato));
		aux = aux->siguiente;
	}
	printf("\n");
}


void finalNodo (Lista* lista, Nodo* nuevo){

	if (nuevo != NULL && lista->size == 0){
	        lista->cabeza = nuevo;
		lista->cola = nuevo;
	}
	else
        {
                lista->cola->siguiente = nuevo;
                nuevo->anterior = lista->cola;
                lista->cola = nuevo;
                lista->cola->siguiente = lista->cabeza;
        }
        
        lista->size = lista->size + 1;
}


int vacio (Lista* lista){
	
	if (lista->size == 0){
		return 1;
	} else {
		return 0;
	}
}

