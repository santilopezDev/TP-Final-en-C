#include "archivo.h"


int arch2Arreglo(stCliente c[], int dimension){
    stCliente cl;
    int i=0;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes){
        while(fread(&cl, sizeof(stCliente), 1, pArchClientes) > 0){
            if(cl.baja==0){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchClientes);
    }
    return i;
}


int archInactivos2Arreglo(stCliente c[], int dimension)
{
    stCliente cl;
    int i=0;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes){
        while(fread(&cl, sizeof(stCliente), 1, pArchClientes) > 0){
            if(cl.baja==1){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchClientes);
    }
    return i;
}


int arch2ArregloConsumos(stConsumos c[], int dimension)
{
    stConsumos cl;
    int i=0;
    FILE *pArchConsumos = fopen(AR_CONSUMO, "rb");
    if(pArchConsumos){
        while(fread(&cl, sizeof(stConsumos), 1, pArchConsumos) > 0){
            if(cl.baja==0){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchConsumos);
    }
    return i;
}


int arch2ArregloConsumosSegunID(stConsumos c[], int dimension, int nroCl)
{
    stConsumos cl;
    int i=0;
    FILE *pArchConsumos = fopen(AR_CONSUMO, "rb");
    if(pArchConsumos){
        while(fread(&cl, sizeof(stConsumos), 1, pArchConsumos) > 0){
            if(cl.idCliente==nroCl){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchConsumos);
    }
    return i;
}



int arch2ArregloConsumosBaja(stConsumos c[], int dimension)
{
    stConsumos cl;
    int i=0;
    FILE *pArchConsumos = fopen(AR_CONSUMO, "rb");
    if(pArchConsumos){
        while(fread(&cl, sizeof(stConsumos), 1, pArchConsumos) > 0){
            if(cl.baja==1){
                c[i] = cl;
                i++;
            }
        }
        fclose(pArchConsumos);
    }
    return i;
}



 void registroToRegistro ()
 {
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    FILE *pArchCliActivos = fopen(AR_ACTIVOS, "wb");
    FILE *pArchCliBaja = fopen(AR_INACTIVOS, "wb");
    if(pArchClientes && pArchCliActivos && pArchCliBaja){
        while(fread(&c, sizeof(stCliente), 1, pArchClientes) > 0){
            if(c.baja == 1){
                fwrite(&c, sizeof(stCliente), 1, pArchCliBaja);
            }
            else{
                fwrite(&c, sizeof(stCliente), 1, pArchCliActivos);
            }
        }
        fclose(pArchClientes);
        fclose(pArchCliActivos);
        fclose(pArchCliBaja);
    }
 }



 nodoArbol* pasarArchConsumosToArbol (char archivo[], nodoArbol* arbol){
    FILE *pArchConsumos = fopen(archivo, "rb");
    stConsumos aux;
    stCliente clienteAux;
    if (pArchConsumos){
        while (fread(&aux, sizeof(stConsumos), 1, pArchConsumos)>0){
            clienteAux = buscaUnClientePorID(aux.idCliente);
            nodo* cons = crearNodo(aux);
            arbol = alta(arbol, cons, clienteAux);
        }
        fclose(pArchConsumos);
    }
    return arbol;
}

