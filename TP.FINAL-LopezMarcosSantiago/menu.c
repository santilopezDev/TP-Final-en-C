#include "menu.h"



void menu() {

    lineaHSup();
    printf("\n\t\t\t MENU PRINCIPAL\n                                       ");
    printf("\n\t\t%c 1 %c - CLIENTES.                                    ",254,254);
    printf("\n\t\t%c 2 %c - CONSUMO.                                     ",254,254);
    printf("\n\t\t%c 3 %c - CARGAR CLIENTES A ARBOL DE LISTAS.                                     ",254,254);
    lineaHInf();

}

void menuClientes() {

    lineaHSup();
    printf("\n\t\t\t MENU DE CLIENTES\n                                     ");
    printf("\n\t\t% c1 %c] - Alta.                                        ",254,254);
    printf("\n\t\t%c 2 %c - Baja.                                        ",254,254);
    printf("\n\t\t%c 3 %c - Modificacion.                                ",254,254);
    printf("\n\t\t%c 4 %c - Lista de clientes activos.                   ",254,254);
    printf("\n\t\t%c 5 %c - Listas de clientes inactivos.                ",254,254);
    lineaHInf();
}


void menuAltaCliente(){
    system("cls");
    lineaHSup();
    printf("\n\t\t%c 1 %c - Carga un cliente manual                      ",254,254);
    printf("\n\t\t%c 2 %c - Carga clientes random                        ",254,254);
    printf("\n\t\t%c 3 %c - Muestra archivo de clientes                  ",254,254);
    lineaHInf();
}



void menuOrden() {

    lineaHSup();
    printf("\n\t\t\tMENU DE ORDENAMIENTO ACTIVOS\n                         ");
    printf("\n\t\t%c 1 %c - Ordenar por DNI.                             ",254,254);
    printf("\n\t\t%c 2 %c - Ordenar por Apellido.                        ",254,254);
    printf("\n\t\t%c 3 %c - Buscar cliente en particular y mostrarlo.    ",254,254);
    lineaHInf();
}


void menuConsumo() {

    lineaHSup();
    printf("\n\t\t\tMENU DE CONSUMO\n                                    ");
    printf("\n\t\t%c 1 %c - Alta de consumo.                             ",254,254);
    printf("\n\t\t%c 2 %c - Baja de consumo.                             ",254,254);
    printf("\n\t\t%c 3 %c - Modificacion de consumo.                     ",254,254);
    printf("\n\t\t%c 4 %c - Lista de consumo.                            ",254,254);
    lineaHInf();

}



void menuCargaConsumo ()
{
    system("cls");

    lineaHSup();
    printf("\n\t\t%c 1 %c - Carga un Consumo                             ",254,254);
    printf("\n\t\t%c 2 %c] - Muestra archivo de Consumo                   ",254,254);
    lineaHInf();
}


void menuListarConsumos ()
{
    lineaHSup();
    printf("\n\t\t 1)Listar consumos por fecha                 ");
    printf("\n\t\t 2)Listar consumos por Cliente               ");
    printf("\n\t\t 3) Listar consumos dados de baja             ");
    printf("\n\t\t 4) Buscar el mayor consumo                   " );
    lineaHInf();


}


void menuClienteAModificar ()
{
    lineaHSup();
   printf("\n\t\t\tSeleccione el campo que desea modificar:     ");
   printf("\n\t\t%c 1 %c - Numero de cliente                    ",254,254);
   printf("\n\t\t%c 2 %c - Nombre                               ",254,254);
   printf("\n\t\t%c 3 %c - Apellido                             ",254,254);
   printf("\n\t\t%c 4 %c - DNI                                  ",254,254);
   printf("\n\t\t%c 5 %c - Email                                ",254,254);
   printf("\n\t\t%c 6 %c - Domicilio                            ",254,254);
   printf("\n\t\t%c 7 %c - Movil                                ",254,254);
    lineaHInf();
   printf("\n");
}


void menuConsumosAModificar ()
{
    lineaHSup();
   printf("\n\t\t\tSeleccione el campo que desea modificar:     ");
   printf("\n\t\t%c 1 %c - Anio                                ",254,254);
   printf("\n\t\t%c 2 %c - Mes                                  ",254,254);
   printf("\n\t\t%c 3 %c - Dia                                  ",254,254);
   printf("\n\t\t%c 4 %c - Datos Consumidos                     ",254,254);
    lineaHInf();
   printf("\n");
}


void menuArbolDeListas ()
{
    lineaHSup();
   printf("\n\t\t\t MENU ARBOL DE LISTAS\n    ");
   printf("\n\t\t%c 1 %c - Ver arbol de clientes                               ",254,254);
   printf("\n\t\t%c 2 %c - Borrar cliente del arbol                                 ",254,254);
   printf("\n\t\t%c 3 %c - Liquidacion de consumos                                 ",254,254);
    lineaHInf();
   printf("\n");
}

void menuLiquidacion ()
{
    lineaHSup();
   printf("\n\t\t\t MENU DE LIQUIDACION DE CONSUMOS\n     ");
   printf("\n\t\t%c 1 %c - Liquidacion mensual                              ",254,254);
   printf("\n\t\t%c 2 %c - Liquidacion anual                                 ",254,254);
   lineaHInf();
   }



void lineaHSup ()
{
    int i;

    printf("\n\t%c", 201);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",187);
}



void lineaHInf ()
{
    int i;

    printf("\n\t%c", 200);
    for (i = 15; i < 75; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n",188);
}




