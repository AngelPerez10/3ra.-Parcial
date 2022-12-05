/******************************************************************************
Adolfo Angel Perez Salado
3°D
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

struct Nodo {
	int dato; 
	struct Nodo* izquierda;
	struct Nodo* derecha;
	int nivel_Arbol;
};



struct Nodo* nuevoNodo(int dato);
void eliminar_dato(struct Nodo* arbol_binario);
void insertar(struct Nodo* raiz_arbol, struct Nodo* Nodo);
int buscar_dato(struct Nodo* arbol_binario, int dato);

int main() {

    printf("EXAMEN PARCIAL 3\n");
    printf("*** ARBOL BINARIO *** \n");

    
	int n = 0, nivel_Arbol = 0;
	struct Nodo* raiz = nuevoNodo(6);
	insertar(raiz, nuevoNodo(5));
	insertar(raiz, nuevoNodo(11));
	insertar(raiz, nuevoNodo(4));
	insertar(raiz, nuevoNodo(3));
	insertar(raiz, nuevoNodo(8));
	insertar(raiz, nuevoNodo(12));
	insertar(raiz, nuevoNodo(9));
	insertar(raiz, nuevoNodo(21));
	
	printf("¿QUE NUMERO DESEAS BUSCAR? ");
	scanf("%d", &n);
	nivel_Arbol = buscar_dato(raiz, n);
	if (nivel_Arbol > 0)
		printf("EL NUMERO ESTA EN EL NIVEL : %d\n", nivel_Arbol);
	else 
		printf("LO LAMEENTO EL NUMERO NO SE ENCUENTRA EN EL ARBOL :( \n");

	return 0;
}


struct Nodo* nuevoNodo(int dato) {
	struct Nodo* Nodo = NULL;
	Nodo = malloc(sizeof(struct Nodo));
	Nodo->izquierda = Nodo->derecha = NULL;
	Nodo->nivel_Arbol = 1;
	Nodo->dato = dato;
	return Nodo;
}

void insertar(struct Nodo* raiz_arbol, struct Nodo* Nodo) {
	if (raiz_arbol != NULL && Nodo != NULL) {
		Nodo->nivel_Arbol = raiz_arbol->nivel_Arbol + 1;
		if (Nodo->dato > raiz_arbol->dato) {
			if (raiz_arbol->derecha == NULL)
				raiz_arbol->derecha = Nodo;
			else
				insertar(raiz_arbol->derecha, Nodo);
		} else {
			if (raiz_arbol->izquierda == NULL)
				raiz_arbol->izquierda = Nodo;
			else
				insertar(raiz_arbol->izquierda, Nodo);
		}
	}
}

int buscar_dato(struct Nodo* raiz, int dato) {
	int l = 0;
	if (raiz == NULL)
		return 0;
	if (raiz->dato == dato)
		return raiz->nivel_Arbol;
	l = buscar_dato(raiz->izquierda, dato);
	if (l > 0)
		return l;
	l = buscar_dato(raiz->derecha, dato);
	if (l > 0)
		return l;
	return 0;
}
