#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

#include<string.h>

void dibujarMenu()
{
    printf("Ingrese una operacion \n");
    printf("1- Verificar archivos \n");
    printf("2- Cargar Archivos \n");
    printf("3- Listar Informacion \n");
    printf("4- Ver polizas por vendedor \n");
    printf("5- Listar vendedores a premiar \n");
    printf("6- Mostrar el aseguradao con el mayor pago de siniestros \n");
    printf("7- Salir \n");
}

void listarInfo(FILE *archivo)
{
    int opcion;

    printf("Ingrese una operacion \n");
    printf("1- Vendedores \n");
    printf("2- Polizas \n ");
    printf("3- Siniestros \n");

    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        {

            listarInfoVendedores(archivo);
            break;
        }
    case 2:
        {
            listarInfoPolizas(archivo);

            break;
        }
    case 3:
        {
            listarInfoSiniestros(archivo);

            break;
        }
    }


}
void listarInfoVendedores(FILE *archivo)
{
    Vendedor vendedor;
    archivo = fopen("archivos/Vendedores.dat", "rb");
    fread(&vendedor, sizeof(Vendedor), 1, archivo);

    printf("%-5s%-15s%-20s\n", "ID |", " Apellido |", " Tasa de rendimiento |");
    while(!feof(archivo))
    {
        vendedor.TasaRendimiento = calcularTasaRendimiento(vendedor.IDVendedor);
        printf("%-5d%-15s%-20.2f\n", vendedor.IDVendedor, vendedor.ApellidoVendedor, vendedor.TasaRendimiento);
        fread(&vendedor, sizeof(Vendedor), 1, archivo);
    }
    fclose(archivo);
}
void listarInfoPolizas(FILE *archivo)
{

    Poliza poliza;
    archivo = fopen("archivos/Polizas.dat", "rb");
    fread(&poliza, sizeof(Poliza), 1, archivo);
    printf("%-13s%-15s%-20s%-13s%-15s%-10s\n","Nro Poliza", "ID Vendedor", "Asegurado", "Marca", "Patente", "Valor Asegurado");
    while(!feof(archivo))
    {
        printf("%-13d%-15d%-20s%-13s%-15s%-10.2f\n", poliza.NroPoliza, poliza.IDVendedor, poliza.Asegurado, poliza.Marca, poliza.Patente, poliza.ValoAsegurado);
        fread(&poliza, sizeof(Poliza), 1, archivo);
    }
    fclose(archivo);
}
void listarInfoSiniestros(FILE *archivo)
{
    Siniestro siniestro;
    archivo = fopen("archivos/Siniestros.dat", "rb");
    fread(&siniestro, sizeof(Siniestro), 1, archivo);
    printf("%-4s%-12s%-20s\n", "ID", "Nro Poliza", "Valor Siniestrado");


    while(!feof(archivo))
    {
        printf("%-4d%-12d%-20.2f\n", siniestro.IDSiniestro, siniestro.NroPoliza, siniestro.ValorSiniestrado);
        fread(&siniestro, sizeof(Siniestro), 1, archivo);
    }
    fclose(archivo);
}
void listarPolizasVendedor(palabra apellido)
{

    FILE *polizasArch;
    FILE *sinietrosArch;
     int cont  = 0;

    int id = validarVendedor(apellido);
    if(id == -1)
    {
        printf("No se encontro apellido \n");
    }
    else
    {

        printf("Vendedor %s \n",apellido);
        Poliza poliza;
        polizasArch = fopen("archivos/Polizas.dat", "rb");
        fread(&poliza, sizeof(Poliza), 1, polizasArch);
        while(!feof(polizasArch))
        {
            if(poliza.IDVendedor == id)
            {

            printf("\n%-13s%-15s%-20s%-13s%-15s%-10s\n","Nro Poliza|", "ID Vendedor|", "Asegurado|", "Marca|", "Patente|", "Valor Asegurado|");
            printf("%-13d%-15d%-20s%-13s%-15s%-10.2f\n", poliza.NroPoliza, poliza.IDVendedor, poliza.Asegurado, poliza.Marca, poliza.Patente, poliza.ValoAsegurado);

            Siniestro siniestro;
            sinietrosArch = fopen("archivos/Siniestros.dat", "rb");
            fread(&siniestro, sizeof(Siniestro), 1, sinietrosArch);
            cont++;

            while(!feof(sinietrosArch))
            {


                if(poliza.NroPoliza == siniestro.NroPoliza)
                {
                printf("%-4s%-12s%-20s\n", "ID", "Nro Poliza", "Valor Siniestrado");
                printf("%-4d%-12d%-20.2f\n", siniestro.IDSiniestro, siniestro.NroPoliza, siniestro.ValorSiniestrado);

                }
                  fread(&siniestro, sizeof(Siniestro), 1, sinietrosArch);
            }

                fclose(sinietrosArch);


            }
            fread(&poliza, sizeof(Poliza), 1, polizasArch);

        }
        fclose(polizasArch);
    }
    if(cont==0)
    {
        printf("El vendedor no posee ninguna informacion para mostrar \n");
    }

}
void vendedoresAPremiar()
{
    FILE *vendedoresArchi;
    Vendedor vendedor;
    int cont = 0;
    vendedoresArchi = fopen("archivos/Vendedores.dat", "rb");
    fread(&vendedor, sizeof(Vendedor), 1, vendedoresArchi);
    printf("Vendedores a premiar \n");
    while(!feof(vendedoresArchi))
    {
        int id = calcularTasaRendimiento(vendedor.IDVendedor);
        if( id > 5 && id>0)
        {
            printf(" %d", vendedor.IDVendedor);
            printf("%s \n",vendedor.ApellidoVendedor);
            cont++;
        }
        fread(&vendedor, sizeof(Vendedor), 1, vendedoresArchi);
    }
    fclose(vendedoresArchi);
    if(cont == 0)
    {
        printf("No hay vendedores para premiar \n");
    }
}
void AseguradoPiedra()
{
    FILE *polizaArch;
    FILE *siniestroArch;
    float total = 0;
    float maX = 0;
    palabra asegurado;
    int nrPoliza=0;
    Poliza poliza;
    Siniestro siniestro;

    polizaArch = fopen("archivos/Polizas.dat", "rb");
    fread(&poliza, sizeof(Poliza), 1, polizaArch);

    while(!feof(polizaArch))
    {
        siniestroArch = fopen("archivos/Siniestros.dat", "rb");
        fread(&siniestro, sizeof(Siniestro), 1, siniestroArch);

        while(!feof(siniestroArch))
        {
            if(poliza.NroPoliza == siniestro.NroPoliza )
            {
                total = siniestro.ValorSiniestrado + total;
            }

            fread(&siniestro, sizeof(Siniestro), 1, siniestroArch);
        }

        fclose(siniestroArch);

        if(total > maX)
        {
            strcpy(asegurado, poliza.Asegurado);
            nrPoliza = poliza.NroPoliza;
            maX = total;
        }

        fread(&poliza, sizeof(Poliza), 1, polizaArch);
    }

    fclose(polizaArch);
    printf("Asegurado al que mas dinero debe pagarse \n");
    printf("Asegurado : %s NrPoliza: %d  Total: %2.f $ \n",asegurado,nrPoliza,maX);
}
