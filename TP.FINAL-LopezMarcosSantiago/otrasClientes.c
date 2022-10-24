#include "otrasClientes.h"



int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0)
    {
        if(email[i]==64)
        {
            flag=1;
        }
        i++;
    }
    return flag;
}


int existenciaNroCl (int nro)
{
    int flag=0;
    stCliente c;

    FILE *pArchCliente = fopen(AR_CLIENTES, "rb");
    if (pArchCliente)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)
        {
            if(c.nroCliente == nro)
            {
                flag=1;
            }
        }
        fclose(pArchCliente);
    }

    return flag;
}


void guardaUnCliente(stCliente c)
{
    FILE *pArchCliente = fopen(AR_CLIENTES,"ab");
    if(pArchCliente != NULL)
    {
        if (!existenciaNroCl(c.nroCliente)){

            fwrite(&c,sizeof(stCliente),1,pArchCliente);

        } else {

            printf("\n\nEl Cliente ya se enuentra registrado en el archivo\n");
        }

        fclose(pArchCliente);
    }
}


void cargaArchivoClientes()
{
    char continuar = 's';
    stCliente c;
    while(continuar == 's')
    {
        system("cls");
        printf("\n Carga de Clientes \n");

        c = cargaUnCliente();

        c.id = buscaUltimoId() + 1;
        guardaUnCliente(c);

        printf("\nDesea continuar con la carga? s = si / n = no\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
}


void muestraArchCliente () {

    stCliente c;

    FILE *pArchCliente = fopen(AR_CLIENTES,"rb");

    if (pArchCliente) {

        while (fread(&c, sizeof(stCliente), 1, pArchCliente) > 0) {
            muestraUnCliente(c);
        }
       fclose(pArchCliente);
    }

    printf("\n");
}


int buscaUltimoId()
{
    stCliente c;
    int id = -1;

    FILE *pArchCliente = fopen(AR_CLIENTES,"rb");

    if(pArchCliente)
    {
        fseek(pArchCliente, sizeof (stCliente)*(-1), SEEK_END);

        if(fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            id = c.id;
        }
        fclose(pArchCliente);
    }
    return id;
}


void bajaCliente ()
{
    stCliente  aux;
    char apellido[20];
    char continuar;

    printf("\n\tIngrese el apellido a buscar\n");
    fflush(stdin);
    gets(apellido);

    aux = buscaUnClienteApellidoArchivo(apellido);

    if (aux.id != -1){
        printf("\nEl cliente existe en el archivo\n");
        muestraUnCliente(aux);
        printf("\nDesea dar de baja al cliente? s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);
    } else{
        printf("\nEl cliente no existe en el archivo\n");
    }

    if (continuar == 's'){
        aux.baja = 1;
        muestraUnCliente(aux);
        modificaRegistro(aux);
    }
}


stCliente buscaUnClienteApellidoArchivo(char apellido[])
{
    stCliente c;
    int flag=0;

    FILE *pArchCliente = fopen(AR_CLIENTES,"rb");

    if(pArchCliente)
    {
        while( flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)
        {
            if(strcmpi(c.apellido, apellido) == 0)
            {
                flag=1;
            }
        }
        fclose(pArchCliente);
    }

    if(flag==0)
    {
        c.id = -1;
    }

    return c;
}


stCliente buscaUnClientePorID(int idCliente)
{
    stCliente c;
    int flag=0;

    FILE *pArchCliente = fopen(AR_CLIENTES,"rb");
    if(pArchCliente){
        while( flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0){
            if(c.nroCliente == idCliente){
                flag=1;
            }
        }
        fclose(pArchCliente);
    }
    return c;
}


stCliente buscaMenorDNIarch () {

    stCliente c;
    stCliente menor;

    menor.id = -1;
    FILE *parchClientes = fopen(AR_CLIENTES, "rb");

    if (parchClientes){
        if(fread(&menor, sizeof(stCliente), 1, parchClientes) > 0) {
            while (fread(&c, sizeof(stCliente), 1, parchClientes) > 0) {
                if (c.dni < menor.dni) {
                    menor = c;
                }
            }
        }
        fclose(parchClientes);
    }
    return menor;
}


int buscaPos(int id)
{
    int pos = -1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes){
        while(pos==-1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0){
            if(c.id == id){
                pos = ftell(pArchClientes)/sizeof(stCliente)-1;
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}


void muestraArchClienteActivos () {

    stCliente c;
    FILE *pArchCliente = fopen(AR_ACTIVOS,"rb");

    if (pArchCliente) {
        while (fread(&c, sizeof(stCliente), 1, pArchCliente) > 0) {
            muestraUnCliente(c);
        }
        fclose(pArchCliente);
    }
    printf("\n");
}


void muestraArchClienteInactivos () {

    stCliente c;
    FILE *pArchCliente = fopen(AR_INACTIVOS,"rb");

    if (pArchCliente) {
        while (fread(&c, sizeof(stCliente), 1, pArchCliente) > 0) {
            muestraUnCliente(c);
        }
        fclose(pArchCliente);
    }
    printf("\n");
}


int buscaPosMenorDni(stCliente c[], int v, int inicio){
    int posMenor = inicio;
    int i = inicio + 1;
    while(i<v){
        if(c[i].dni < c[posMenor].dni){
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}


void intercambiaClientes(stCliente *a, stCliente *b){
    stCliente aux;
    aux=*a;
    *a=*b;
    *b=aux;
}


void ordPorSelDni(stCliente c[], int v){
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor=buscaPosMenorDni(c,v,i);
        intercambiaClientes(&c[i],&c[posMenor]);
        i++;
    }
}


int buscaPosMenorApellido(stCliente c[], int v, int inicio)
{
    int posMenor = inicio;
    int i = inicio + 1;
    while(i<v){
        if(strcmp(c[i].apellido,c[posMenor].apellido)<0){
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}



void ordPorSelApellido(stCliente c[], int v)
{
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor=buscaPosMenorApellido(c,v,i);
        intercambiaClientes(&c[i],&c[posMenor]);
        i++;
    }
}


int buscaPosMenorEmail(stCliente c[], int v, int inicio)
{
    int posMenor = inicio;
    int i = inicio + 1;
    while(i<v){
        if(strcmp(c[i].email,c[posMenor].email)<0){
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}


void ordPorSelEmail(stCliente c[], int v)
{
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor=buscaPosMenorEmail(c,v,i);
        intercambiaClientes(&c[i],&c[posMenor]);
        i++;
    }
}


stCliente clienteModificado (stCliente c)
{
    int opcion;
    char continuar;
    stCliente d;
    menuClienteAModificar();
    scanf("%d", &opcion);

    do {
        switch (opcion){
        case 1:
            do {
            printf("\nIngrese el nuevo Nro de Cliente: ");
            scanf("%d", &d.nroCliente);
            c.nroCliente = d.nroCliente;
            }while(d.nroCliente<0 || d.nroCliente>9999999);
            break;
        case 2:
            printf("\nIngrese el nuevo nombre del Cliente: ");
            fflush(stdin);
            gets(d.nombre);
            strcpy(c.nombre, d.nombre);
            break;
        case 3:
            printf("\nIngrese el nuevo apellido del Cliente: ");
            fflush(stdin);
            gets(d.apellido);
            strcpy(c.apellido, d.apellido);
            break;
        case 4:
            printf("\nIngrese el nuevo DNI del Cliente: ");
            scanf("%d", &d.dni);
            c.dni = d.dni;
            break;
        case 5:
            do {
            printf("\nIngrese el nuevo email del Cliente: ");
            fflush(stdin);
            gets(d.email);
            strcpy(c.email, d.email);
            }while(!validaEmail(d.email));
            break;
        case 6:
            printf("\nIngrese el nuevo domicilio del Cliente: ");
            fflush(stdin);
            gets(d.domicilio);
            strcpy(c.domicilio, d.domicilio);
            break;
        case 7:
            printf("\nIngrese el nuevo movil del Cliente: ");
            scanf("%d", &d.movil);
            c.movil = d.movil;
            break;
        }

    system("pause");
    printf("\nDesea continuar? s = si / n = no\n");
    fflush(stdin);
    scanf("%c", &continuar);

    } while (continuar == 's');

    return c;
}


void modificaRegistro(stCliente c)
{
    int pos = 0;
    pos = buscaPos(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES, "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        fwrite(&c, sizeof(stCliente), 1, pArchClientes);
        fclose(pArchClientes);
    }
}
