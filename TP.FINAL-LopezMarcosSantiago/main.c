#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Cliente.h"
#include "otrasClientes.h"
#include "lista.h"
#include "varias.h"
#include "Consumo.h"
#include "otrasConsumos.h"
#include "menu.h"
#include "Arbol.h"


#define ESC 27




int main()
{
    srand(time(NULL));
    int cantidad=0, vConsumo = 0;
    char continuar = 's';
    char confirmacion;
    char opcion;
    char apellido[30];
    char nombre[30];
    int DIM = 1000;
    stCliente cliente[DIM];
    stConsumos consumo[DIM];
    stCliente aux, modif;
    stConsumos auxMax, auxMin;
    system("COLOR E0");

    do
    {
        system("cls");

        menu();

        opcion = getch();
        system("cls");

        switch (opcion)
        {
        case '1': /// CLIENTES.

            do
            {
                system("cls");
                menuClientes();
                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case '1': /// ALTA.

                    do
                    {
                        menuAltaCliente();
                        opcion = getch();
                        system("cls");

                        switch (opcion){
                        case '1':
                            cargaArchivoClientesManual();
                            break;
                        case '2':
                            printf("\n\tCantidad de clientes a cargar: ");
                            scanf("%d", &cantidad);
                            cargaArchivoClientesRandom(cantidad);
                            break;
                        case '3':
                            muestraArchCliente();
                            break;
                        }
                        system("pause");
                        printf("\n¿Desea seguir en ALTA DE CLIENTE? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');
                    break;

                case '2':
                    do
                    {
                        system("cls");

                        bajaCliente();

                        system("pause");
                        printf("\n¿Desea continuar en BAJA DE CLIENTE? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);


                    } while (continuar == 's');

                    break;

                case '3':

                    do
                    {
                        system("cls");

                        printf("\n\tIngrese el apellido a buscar\n");
                        fflush(stdin);
                        gets(apellido);
                        aux = buscaUnClienteApellidoArchivo(apellido);


                        modif = clienteModificado(aux);
                        modificaRegistro(modif);

                        system("pause");

                        printf("\n¿Desea continuar en MODIFICACION DE CLIENTES? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '4':

                    do
                    {
                        system("cls");

                        menuOrden();

                        opcion = getch();
                        system("cls");

                        switch (opcion)
                        {
                        case '1':
                            cantidad = arch2Arreglo(cliente, DIM);
                            ordPorSelDni(cliente, cantidad);
                            muestraClientes(cliente, cantidad);
                            break;

                        case '2':
                            cantidad = arch2Arreglo(cliente, DIM);
                            ordPorSelApellido(cliente, cantidad);
                            muestraClientes(cliente, cantidad);
                            break;

                        case '3':
                            printf("\n\tIngrese el apellido a buscar\n");
                            fflush(stdin);
                            gets(apellido);
                            aux = buscaUnClienteApellidoArchivo(apellido);
                            if (aux.id != -1){
                                muestraUnCliente(aux);
                            } else {
                                printf("\nEl cliente no existe en el archivo\n");
                            }
                            break;

                        }
                        system("pause");
                        printf("\n¿Desea continuar en LISTAR CLIENTES ACTIVOS? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '5':

                    //gotoxy(5, 5);
                    printf("\n\tSe muestra los clientes inactivos ordenados por email\n");

                    cantidad = archInactivos2Arreglo(cliente, DIM);
                    ordPorSelEmail(cliente, cantidad);
                    muestraClientes(cliente, cantidad);

                    break;

                }
                system("pause");
                printf("\n¿Desea continuar en MENU DE CLIENTES? s(si)- n(no)\n");
                fflush(stdin);
                scanf("%c", &continuar);

            } while (continuar == 's');

            break;

        case '2':

            do
            {
                system("cls");

                menuConsumo();

                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case '1':

                    do
                    {
                        menuCargaConsumo();
                        opcion = getch();
                        system("cls");

                        switch(opcion)
                        {
                        case '1':

                            cargaConsumoClienteRandom();

                            break;

                        case '2':

                            muestraArchConsumo();

                            break;
                        }
                        system("pause");
                        printf("\n¿Desea continuar en CARGA DE CONSUMO? s = si / n = no\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '2':

                    bajaConsumo();

                    break;

                case '3':

                    do
                    {
                        system("cls");

                        modificacionConsumo();

                        system("pause");

                        printf("\¿Desea continuar en MODIFICACION DE CONSUMOS? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');

                    break;

                case '4':

                    do{
                        menuListarConsumos();
                        opcion=getch();
                        system("cls");

                        switch (opcion){

                            case '1':

                                vConsumo = arch2ArregloConsumos(consumo, DIM);
                                ordPorSelFecha(consumo, vConsumo);
                                muestraConsumos(consumo, vConsumo);
                                break;

                            case '2':

                                do{
                                printf("\nIngrese el apellido del cliente: \n");
                                fflush(stdin);
                                gets(apellido);
                                aux = buscaUnClienteApellidoArchivo(apellido);
                                vConsumo = arch2ArregloConsumosSegunID(consumo, DIM, aux.nroCliente);

                                if (aux.id != -1){
                                    muestraConsumos(consumo, vConsumo);
                                }
                                else{
                                    printf("\nEl cliente no existe en el archivo\n");
                                }
                                printf("\n¿Desea buscar otro cliente? s/n \n");
                                opcion = getch();
                                } while (opcion == 's');
                                break;

                            case '3':
                                vConsumo = arch2ArregloConsumosBaja(consumo, DIM);
                                printf("\nLos consumos dados de baja son: \n");
                                muestraConsumos(consumo, vConsumo);
                                break;

                           case '4':
                                    do{
                                    printf("\nIngrese el apellido del cliente: \n");
                                    fflush(stdin);
                                    gets(apellido);
                                    aux = buscaUnClienteApellidoArchivo(apellido);
                                    if (aux.id != -1)
                                    {
                                        vConsumo = arch2ArregloConsumosSegunID(consumo, DIM, aux.nroCliente);
                                        auxMax = buscarMaximo(consumo, vConsumo);
                                        auxMin = buscarMinimo(consumo, vConsumo);
                                        system("cls");
                                        printf("\nEl mayor consumo del cliente es: \n");
                                        muestraUnConsumo(auxMax);
                                        printf("\nEl menor consumo del cliente es: \n");
                                        muestraUnConsumo(auxMin);
                                    } else {
                                        printf("\nEl cliente no existe. Ingrese nuevamente\n");
                                    }
                                    printf("\n¿Desea buscar otro cliente? s(si)- n(no) \n");
                                    opcion = getch();
                                    system("cls");
                                    } while (opcion == 's');
                                break;


                        }
                       system("pause");

                        printf("\n¿Desea continuar en LISTAR CONSUMOS? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                    } while (continuar == 's');
                    break;
                }
                system("pause");
                printf("\n¿Desea continuar con la operacion de Consumo? s(si)- n(no)\n");
                fflush(stdin);
                scanf("%c", &continuar);
                system("cls");
            } while (continuar == 's');
            break;

                           case '3':

                            system("cls");

                            nodoArbol* arbolCliente = inicArbol();
                            arbolCliente = pasarArchConsumosToArbol(AR_CONSUMO, arbolCliente);





                            do{
                            system("cls");




                            menuArbolDeListas();

                            opcion = getch();
                            system("cls");
                            switch (opcion){

                               case '1':

                                system("cls");

                                //preorder(arbolCliente);
                                enorder(arbolCliente);

                                system("pause");


                                break;
                               case '2':
                                   do{

                                    system("cls");

                                    printf("\n Ingrese el nombre del Cliente que desea eliminar del arbol : ");
                                    fflush(stdin);
                                    gets(nombre);
                                    printf("\n Ahora ingrese el apellido del Cliente : ");
                                    fflush(stdin);
                                    gets(apellido);


                                    nodoArbol * aBuscar;
                                    aBuscar = buscaNodoArbolPorNombre(arbolCliente, nombre, apellido);

                                    if(aBuscar == NULL)
                                    {
                                       printf("\nEL CLIENTE NO SE ENCUENTRA EN EL ARBOL  \n");
                                    }

                                    else{
                                            mostrarNodoArbol(aBuscar);
                                    printf("\n\n DESEA ELIMINAR ESTE CLIENTE? s(si) n(no)");
                                    fflush(stdin);
                                    scanf("%c", &confirmacion);
                                        if(confirmacion == 's')

                                            {arbolCliente = borrarNodoArbol(arbolCliente, aBuscar->dato);
                                            printf("\n CLIENTE BORRADO  xxxxxxxxx\n");}

                                    }

                                    system("pause");
                                    printf("\n¿Desea continuar en BORRAR CLIENTES DEL ARBOL? s(si)- n(no)\n");
                                    fflush(stdin);
                                    scanf("%c", &continuar);
                                    system("cls");

                                    } while (continuar == 's');
                                    break;

                               case '3':
                                    do{
                                        system("cls");
                                        menuLiquidacion();
                                        opcion = getch();
                                        system("cls");

                                        switch(opcion)
                                        {

                                    case '1':
                                        do{

                                        int mes;
                                        int anio;

                                        float precioMB;
                                        printf("\n Ingrese el nombre del Cliente que desea liquidarle un mes : ");
                                        fflush(stdin);
                                        gets(nombre);
                                        printf("\n Ahora ingrese el apellido del Cliente : ");
                                        fflush(stdin);
                                        gets(apellido);



                                        nodoArbol* aBuscar;
                                        aBuscar = buscaNodoArbolPorNombre(arbolCliente, nombre, apellido);

                                        do{
                                        system("cls");
                                        printf("\nIngrese el mes:");
                                        scanf("%i", &mes);

                                        }while(mes <= 0 || mes > 12);
                                        do{
                                        system("cls");
                                        printf("\nIngrese el anio:");
                                        scanf("%i", &anio);

                                        }while(anio < 2018 || anio > 2021);
                                        printf("\nIngrese el precio del MB :");
                                        scanf("%f", &precioMB);
                                        liquidacionClienteMes(aBuscar, precioMB , mes, anio );

                                        system("pause");
                                        printf("\n¿Desea continuar en LIQUIDACION MENSUAL? s(si)- n(no)\n");
                                        fflush(stdin);
                                        scanf("%c", &continuar);
                                        system("cls");

                                    }while (continuar == 's');
                                    break;

                             case '2':
                                    do{

                                        system("cls");

                                        int anio;
                                        nodoArbol* aBuscar;
                                        float precioMB;

                                        printf("\n Ingrese el nombre del Cliente que desea liquidarle un anio : ");
                                        fflush(stdin);
                                        gets(nombre);
                                        printf("\n Ahora ingrese el apellido del Cliente : ");
                                        fflush(stdin);
                                        gets(apellido);


                                        aBuscar = buscaNodoArbolPorNombre(arbolCliente, nombre, apellido);
                                        if(aBuscar == NULL)
                                        {
                                            printf("\nEL CLIENTE NO SE ENCUENTRA EN EL ARBOL\n");
                                        }
                                        else{

                                        do{
                                        system("cls");
                                        printf("\nIngrese el anio:");
                                        scanf("%i", &anio);

                                        }while(anio < 2019 || anio > 2021);
                                        printf("\nIngrese el precio del MB :\n");
                                        scanf("%f", &precioMB);
                                        system("cls");
                                        liquidacionClienteAnio(aBuscar, precioMB , anio );

                                        }


                                    system("pause");
                                    printf("\n¿Desea continuar en LIQUIDACION ANUAL? s(si)- n(no)\n");
                                    fflush(stdin);
                                    scanf("%c", &continuar);
                                    system("cls");

                                    }while (continuar == 's');
                                    break;
                                        }


                                system("pause");
                                printf("\n¿Desea continunar en LIQUIDACION DE CONSUMOS? s(si)- n(no)\n");
                                fflush(stdin);
                                scanf("%c", &continuar);
                                system("cls");
                                }while(continuar == 's');
                                break;


                                }


                        system("cls");
                        printf("\n¿Desea continuar en ARBOL DE LISTAS? s(si)- n(no)\n");
                        fflush(stdin);
                        scanf("%c", &continuar);
                        system("cls");

                       }while(continuar == 's');

        }
        system("pause");
        printf("\nDesea volver al MENU PRINCIPAL? s = si / n = salir \n");
        fflush(stdin);
        scanf("%c", &continuar);

    } while (continuar == 's');

    return 0;

}










