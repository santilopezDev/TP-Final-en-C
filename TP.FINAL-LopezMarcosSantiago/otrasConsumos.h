#ifndef OTRASCONSUMOS_H_INCLUDED
#define OTRASCONSUMOS_H_INCLUDED
#include "Consumo.h"
#include "menu.h"

int buscaUltimoIdConsumo();
stConsumos buscaUnConsumoFechaArchivo(int year, int mounth, int day);
void bajaConsumo ();
stConsumos consumoModificado (stConsumos C);
int buscaPosConsumo(int id);
void modificacionConsumo ();
void modificaRegistroCosumo(stConsumos C);
void muestraConsumos (stConsumos c[], int v);
int buscaPosMenorFecha(stConsumos c[], int v, int inicio);
void intercambiaConsumos(stConsumos *a, stConsumos *b);
void ordPorSelFecha (stConsumos c[], int v);
stConsumos buscarMaximo (stConsumos A[], int validos);
stConsumos buscarMinimo (stConsumos A[], int validos);
stConsumos buscaConsumoPorID(int idConsumo);

#endif // OTRASCONSUMOS_H_INCLUDED
