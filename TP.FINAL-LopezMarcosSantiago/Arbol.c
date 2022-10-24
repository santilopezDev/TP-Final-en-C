#include "Arbol.h"
#include <string.h>



nodoArbol* inicArbol (){
    return NULL;
}



nodoArbol* crearNodoArbol (stCliente dato){
    nodoArbol* aux = (nodoArbol*) malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->listaDeConsumos = inicLista();
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}



nodoArbol* agregarArbol (nodoArbol* arbol, stCliente dato){
    if (arbol == NULL){
        arbol = crearNodoArbol(dato);
    } else if (dato.nroCliente > arbol->dato.nroCliente) {
            arbol->der = agregarArbol(arbol->der, dato);
        } else {
            arbol->izq = agregarArbol(arbol->izq, dato);
        }
    return arbol;
}



void preorder (nodoArbol* arbol){
    if(arbol!=NULL){
        mostrarNodoArbol(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}
void enorder(nodoArbol* arbol)
{
    if(arbol!= NULL)
    {
        preorder(arbol->izq);
        mostrarNodoArbol(arbol);
        preorder(arbol->der);
    }
}



nodoArbol* buscarDatoArbol (nodoArbol* arbol, stCliente dato){
    nodoArbol* rta = NULL;
    if (arbol){
        if (dato.nroCliente == arbol->dato.nroCliente){
            rta = arbol;
        } else if (dato.nroCliente > arbol->dato.nroCliente){
            rta = buscarDatoArbol(arbol->der, dato);
        } else {
            rta = buscarDatoArbol(arbol->izq, dato);
        }
    }
    return rta;
}



nodoArbol* alta (nodoArbol* arbol, nodo* nuevoConsumo, stCliente dato){
    nodoArbol* arbolEncontrado = inicArbol();
    arbolEncontrado = buscarDatoArbol(arbol, dato);

    if (arbolEncontrado==NULL){
        arbol = agregarArbol(arbol, dato);
        arbolEncontrado = buscarDatoArbol(arbol, dato);
        arbolEncontrado->listaDeConsumos= agregarAlFinal(arbolEncontrado->listaDeConsumos, nuevoConsumo);
    } else {
        if (dato.nroCliente == arbol->dato.nroCliente){
            arbolEncontrado->listaDeConsumos = agregarAlFinal(arbolEncontrado->listaDeConsumos, nuevoConsumo);
        } else if (dato.nroCliente > arbol->dato.nroCliente) {
            arbol->der = alta(arbol->der, nuevoConsumo, dato);
        } else {
            arbol->izq = alta(arbol->izq, nuevoConsumo, dato);
        }
    }
    return arbol;
}


int cuentaNodos (nodoArbol* arbol){
    int cont=0;
    if (arbol){
        cont = 1 + cuentaNodos(arbol->der) + cuentaNodos(arbol->izq);
    }
    return cont;
}





nodoArbol* nodoMasDerecha(nodoArbol *arbol){
   nodoArbol *aux;
   if(arbol->der==NULL){
      aux=arbol;
   }else{
      aux=nodoMasDerecha(arbol->der);
   }
   return aux;
}



nodoArbol* nodoMasIzquierda(nodoArbol *arbol){
   nodoArbol *aux;
   if(arbol->izq==NULL){
      aux=arbol;
   }else{
      aux=nodoMasIzquierda(arbol->izq);
   }
   return aux;
}



nodoArbol* borrarNodoArbol(nodoArbol *arbol, stCliente dato)
{
   if(arbol!=NULL){
      if(dato.nroCliente > arbol->dato.nroCliente){
         arbol->der=borrarNodoArbol(arbol->der,dato);
      }else if(dato.nroCliente < arbol->dato.nroCliente){
         arbol->izq=borrarNodoArbol(arbol->izq,dato);
      }else{
         if(arbol->izq!=NULL){
            arbol->dato=(nodoMasDerecha(arbol->izq)->dato);
            arbol->izq=borrarNodoArbol(arbol->izq,arbol->dato);
         }else if(arbol->der!=NULL){
            arbol->dato=(nodoMasIzquierda(arbol->der)->dato);
            arbol->der=borrarNodoArbol(arbol->der,arbol->dato);
         }else{
            free(arbol);
            arbol=NULL;
         }
      }
   }
   return arbol;
}



void mostrarNodoArbol (nodoArbol* arbol){
    if(arbol){
        lineaHSup();
        printf("\n\t\t CLIENTE\n");
        printf("\n\t\t NRO CLIENTE...: %d ", arbol->dato.nroCliente);
        printf("\n\t\t NOMBRE........: %s ", arbol->dato.nombre);
        printf("\n\t\t APELLIDO......: %s ", arbol->dato.apellido);
        printf("\n\t\t DNI...........: %d ", arbol->dato.dni);
        printf("\n\t\t EMAIL...........: %s ", arbol->dato.email);
        printf("\n\t\t DOMICILIO...........: %s ", arbol->dato.domicilio);
        printf("\n\t\t TELEFONO...........: %d ", arbol->dato.movil);
        lineaHInf();
        printf("\n\t\t CONSUMOS DEL CLIENTE:\n");
        muestraLista(arbol->listaDeConsumos);
        }
}



void liquidacionClienteMes (nodoArbol* arbol, float precio, int mes, int anio){


    printf("\t LIQUIDACION MENSUAL DEL CLIENTE                      ");

    printf("\n NOMBRE...................: %s                ",arbol->dato.nombre);

    printf("\n APELLIDO.................: %s               ",arbol->dato.apellido);

    printf("\n DNI......................: %d               ",arbol->dato.dni);

    printf("\n CANTIDAD CONSUMOS........: %d               ",cuentaListaMes(arbol->listaDeConsumos, mes, anio));

    printf("\n TOTAL MB CONSUMIDOS......: %d               ",sumaConsumosMes(arbol->listaDeConsumos, mes, anio));

    printf("\n PRECIO DEL MB............: $ %.2f             ",precio);

    printf("\n TOTAL A PAGAR............: $ %.2f             ",sumaConsumosMes(arbol->listaDeConsumos, mes, anio)*precio);

    printf("\n");

}
void liquidacionClienteAnio (nodoArbol* arbol, float precio, int anio){


    printf("\t LIQUIDACION ANUAL DEL CLIENTE                      ");

    printf("\n NOMBRE...................: %s                ",arbol->dato.nombre);

    printf("\n APELLIDO.................: %s               ",arbol->dato.apellido);

    printf("\n DNI......................: %d               ",arbol->dato.dni);

    printf("\n CANTIDAD CONSUMOS........: %d               ",cuentaListaAnio(arbol->listaDeConsumos, anio));

    printf("\n TOTAL MB CONSUMIDOS......: %d               ",sumaConsumosAnio(arbol->listaDeConsumos, anio));

    printf("\n PRECIO DEL MB............: $ %.2f             ",precio);

    printf("\n TOTAL A PAGAR............: $ %.2f             ",sumaConsumosAnio(arbol->listaDeConsumos, anio)*precio);

    printf("\n");}



nodoArbol* buscaNodoArbolCliente(nodoArbol* arbol, int nro){
    nodoArbol* respuesta = NULL;
    if(arbol){
        if(arbol->dato.nroCliente == nro){
            respuesta = arbol;
        }else{
            if(nro < arbol->dato.nroCliente){
                respuesta = buscaNodoArbolCliente(arbol->izq, nro);
            }else{
                respuesta = buscaNodoArbolCliente(arbol->der, nro);
            }
        }
    }

    return respuesta;
}


nodoArbol* buscaNodoArbolPorNombre(nodoArbol* arbol, char nombre[], char apellido[]){
    nodoArbol* respuesta = NULL;
    if(arbol){
        if(strcmpi(nombre, arbol->dato.nombre)==0 && strcmpi(apellido, arbol->dato.apellido)== 0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolPorNombre(arbol->izq, nombre, apellido);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolPorNombre(arbol->der, nombre, apellido);
            }
        }
    }

    return respuesta;
}
