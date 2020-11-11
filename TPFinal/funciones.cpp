#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

void verificarArchivos()
{

    FILE *archivo;

    archivo = fopen("archivos/Vendedores.dat", "rb");

    if(!archivo)
    {
        archivo = fopen("archivos/Vendedores.dat", "wb");
        printf("Se creo el archivo \n");
    }
    else
    {
        printf(" Ya existe el archivo\n");
    }

    fclose(archivo);

    archivo = fopen("archivos/Polizas.dat", "rb");

    if(!archivo)
    {
        archivo = fopen("archivos/Polizas.dat", "wb");
        printf("Se creo el archivo \n");
    }
    else
    {
        printf(" Ya existe el archivo\n");
    }

    fclose(archivo);

    archivo = fopen("archivos/Siniestros.dat", "rb");

    if(!archivo)
    {
        archivo = fopen("archivos/Siniestros.dat", "wb");
        printf("Se creo el archivo \n");
    }
    else
    {
        printf(" Ya existe el archivo\n");
    }

    fclose(archivo);
}
void menuCargaDatos()
{
    printf("Opciones \n");
    printf("1-Cargar Vendedor \n");
    printf("2-Cargar Poliza \n");
    printf("3-Siniestro \n");
}
void cargarDatos(FILE *archivo)
{
    int op;
    menuCargaDatos();
    scanf("%d",&op);
    while(op>3 || op<1)
    {
        printf("Opcion invalida \n" );
        scanf("%d",&op);
    }

    switch(op)
    {
    case 1:
        Vendedor vendedor;
        archivo = fopen("archivos/Vendedores.dat","ab");
        printf("\n");
        printf("Ingrese el id del vendedor \n");
        scanf("%d",&vendedor.IDVendedor);
        printf("Ingrese apellido \n");
        scanf("%s",&vendedor.ApellidoVendedor);

        fwrite(&vendedor,sizeof(Vendedor),1,archivo);
        break;

    case 2:
        Poliza poliza;
        archivo = fopen("archivos/Polizas.dat", "ab");
        //despues valido


        printf("Ingrese Nro de poliza: \n");
        scanf("%d", &poliza.NroPoliza);



        printf("Ingrese vombre del asegurado: \n ");
        scanf("%s", poliza.Asegurado);

        printf("Ingrese marca del auto: \n ");
        scanf("%s", poliza.Marca);

        printf("Ingrese patente: \n ");
        scanf("%s", poliza.Patente);

        printf("Ingrese valor asegurado: \n");
        scanf("%f", &poliza.ValoAsegurado);

        fwrite(&poliza, sizeof(Poliza), 1, archivo);

        break;

    case 3:
        Siniestro siniestro;

        archivo = fopen("archivos/Siniestros.dat", "ab");
        printf("Indicar poliza de seguro del auto: \n");
        scanf("%d", &siniestro.NroPoliza);
        printf("Ingrese id del siniestro \n ");
        scanf("%d", &siniestro.IDSiniestro);



        printf("Valor siniestrado: ");
        scanf("%f", &siniestro.ValorSiniestrado);

        fwrite(&siniestro, sizeof(Siniestro), 1, archivo);


        break;
    }
    fclose(archivo);
}
