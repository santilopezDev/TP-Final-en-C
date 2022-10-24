#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include "Cliente.h"
#include "Consumo.h"
#include "Arbol.h"

int arch2Arreglo(stCliente c[], int dimension);
int archInactivos2Arreglo(stCliente c[], int dimension);
int arch2ArregloConsumos(stConsumos c[], int dimension);
int arch2ArregloConsumosSegunID(stConsumos c[], int dimension, int nroCl);
int arch2ArregloConsumosBaja(stConsumos c[], int dimension);
void registroToRegistro();
nodoArbol* pasarArchConsumosToArbol (char archivo[], nodoArbol* arbol);


#endif // ARCHIVO_H_INCLUDED
