#include "Consumo.h"
#include "otrasConsumos.h"
#include "otrasClientes.h"


stConsumos cargaUnConsumo(int id)
{
    stConsumos C;
    C.idCliente = id;
    do {
    C.anio = randomRango(2018, 2021);
    C.mes = randomRango(1, 12);
    C.dia = randomRango(1, 31);
    } while (!validacFecha(C.anio, C.mes, C.dia));
    C.datosConsumidos = randomRango(100, 500);
    C.baja = 0;

    return C;
}

void cargaConsumoClienteRandom(){
    stCliente aux;
    char apellido[20];
    int cant;
    do{
        printf("\n\tIngrese el apellido del cliente para cargar consumos: ");
        fflush(stdin);
        gets(apellido);
        aux = buscaUnClienteApellidoArchivo(apellido);
        if (aux.id >= 0){
            printf("\n\tIngrese la cantidad de consumos a cargar: ");
            scanf("%d", &cant);
            cargaArchConsumoRandom(aux, cant);
        } else {
            printf("\n\tEl cliente no se encuentra en el archivo");
        }
    } while (aux.id == -1);
}


void cargaArchConsumoRandom(stCliente cl, int cant){
    stConsumos C;
    for (int i = 0; i < cant; i++){
        C = cargaUnConsumo(cl.nroCliente);
        C.id = buscaUltimoIdConsumo() + 1;
        guardaUnConsumo(C);
    }
    system("cls");
}


void guardaUnConsumo(stConsumos C)
{
    FILE *pArchConsumo = fopen(AR_CONSUMO,"ab");
    if(pArchConsumo != NULL)
    {
        fwrite(&C,sizeof(stConsumos),1,pArchConsumo);
        fclose(pArchConsumo);
    }
}


void muestraUnConsumo(stConsumos C)
{

    printf("\n    ID  %2d         ", C.id);

    printf("\n  ID de Cliente............: %d", C.idCliente);

    printf("\n  Anio.....................: %d", C.anio);

    printf("\n  Mes......................: %d", C.mes);

    printf("\n  Dia......................: %d", C.dia);

    printf("\n  Datos Consumidos.........: %d mb", C.datosConsumidos);

    printf("\n  Baja.....................: %s\n", (C.baja)?"SI":"NO");

}


void muestraArchConsumo () {

    stConsumos C;
    FILE *pArchConsumo = fopen(AR_CONSUMO,"rb");

    if (pArchConsumo) {
        while (fread(&C, sizeof(stConsumos), 1, pArchConsumo) > 0) {
            muestraUnConsumo(C);
        }
       fclose(pArchConsumo);
    }
    printf("\n");
}


