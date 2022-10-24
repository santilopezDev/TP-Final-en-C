#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Consumo.h"
#include "lista.h"

typedef struct _nodoArbol{
    stCliente dato;
    nodo* listaDeConsumos;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
} nodoArbol;

nodoArbol* inicArbol ();
nodoArbol* crearNodoArbol (stCliente dato);
nodoArbol* agregarArbol (nodoArbol* arbol, stCliente dato);
void preorder (nodoArbol* arbol);
void enorder(nodoArbol*arbol);
nodoArbol* buscarDatoArbol (nodoArbol* arbol, stCliente dato);
nodoArbol* alta (nodoArbol* arbol, nodo* nuevoConsumo, stCliente dato);
int cuentaNodos (nodoArbol* arbol);
nodoArbol* nodoMasDerecha(nodoArbol *arbol);
nodoArbol* nodoMasIzquierda(nodoArbol *arbol);
nodoArbol* borrarNodoArbol(nodoArbol *arbol, stCliente dato);
void mostrarNodoArbol(nodoArbol* arbol);
void liquidacionClienteMes (nodoArbol* arbol, float precio, int mes, int anio);
void liquidacionClienteAnio (nodoArbol* arbol, float precio, int anio);
nodoArbol* buscaNodoArbolCliente(nodoArbol* arbol, int nro);
nodoArbol* buscaNodoArbolPorNombre(nodoArbol* arbol, char nombre[], char apellido[]);

#endif // ARBOL_H_INCLUDED
