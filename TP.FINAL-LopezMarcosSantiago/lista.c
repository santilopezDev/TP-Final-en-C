#include "lista.h"


nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stConsumos dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}


nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void muestraNodo(nodo *nodo){
    printf("\n");
    muestraUnConsumo(nodo->dato);
}


void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){
        muestraNodo(seg);
        seg = seg->sig;
    }
}


nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->sig!=NULL){
        seg = seg->sig;
    }
    return seg;
}


nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}


stConsumos verPrimero(nodo* lista){
    return lista->dato;
}


int cuentaListaMes(nodo* lista, int mes, int anio){
    nodo* seg=lista;
    int cont=0;
    while(seg){
        if(seg->dato.mes == mes && seg->dato.anio == anio)
        {cont++;

        }
        seg = seg->sig;
    }
    return cont;
}

int cuentaListaAnio(nodo* lista, int anio){
    nodo* seg=lista;
    int cont=0;
    while(seg){
        if(seg->dato.anio == anio)
        {cont++;

        }
        seg = seg->sig;
    }
    return cont;
}


int sumaConsumosMes(nodo* lista, int mes, int anio){

    int suma=0;

    if(lista == NULL)
    {
        suma = suma;
    }
    else
    {
        if(lista->dato.mes == mes && lista->dato.anio == anio)
        {
            suma = lista->dato.datosConsumidos + sumaConsumosMes(lista->sig, mes, anio);
        }
        else{
            suma = sumaConsumosMes(lista->sig, mes, anio);
        }
    }
    return suma;
}
int sumaConsumosAnio(nodo* lista, int anio){
    nodo* seg=lista;
    int suma=0;
    while(seg){
        if(lista->dato.anio == anio){
        suma = suma + lista->dato.datosConsumidos;
        }
        seg = seg->sig;
    }
    return suma;
}



