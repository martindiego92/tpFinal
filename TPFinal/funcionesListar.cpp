#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

#include<string.h>

void listarInfo(FILE *archivo)
{
    int opcion;

    printf("\nQue base de datos quisiera ver?\n");
    printf("1: Vendedores\n2: Polizas\n3: Siniestros\n\nOpcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        {
            Vendedor vendedor;
            archivo = fopen("archivos/Vendedores.dat", "rb");
            fread(&vendedor, sizeof(Vendedor), 1, archivo);

            printf("\nID\t Apellido\t Tasa de Rendimiento\n");

            while(!feof(archivo))
            {
                vendedor.TasaRendimiento = calcularTasaRendimiento(vendedor.IDVendedor);
                printf("%d\t %s\t %.2f\n", vendedor.IDVendedor, vendedor.ApellidoVendedor, vendedor.TasaRendimiento);
                fread(&vendedor, sizeof(Vendedor), 1, archivo);
            }
            fclose(archivo);

            break;
        }
    case 2:
        {
            Poliza poliza;
            archivo = fopen("archivos/Polizas.dat", "rb");
            fread(&poliza, sizeof(Poliza), 1, archivo);
            printf("NroPoliza | ID Vendedor |  Asegurado |  Marca |  Patente |  ValorAsegurado \n");
            while(!feof(archivo))
            {
                printf(" %d        %d         %s       %s          %s        %.2f \n", poliza.NroPoliza, poliza.IDVendedor, poliza.Asegurado, poliza.Marca, poliza.Patente, poliza.ValoAsegurado);
                fread(&poliza, sizeof(Poliza), 1, archivo);
            }
            fclose(archivo);
            break;
        }
    case 3:
        {
            Siniestro siniestro;
            archivo = fopen("archivos/Siniestros.dat", "rb");
            fread(&siniestro, sizeof(Siniestro), 1, archivo);
            printf("ID    Nro Poliza     Valor Siniestrado      ");

            while(!feof(archivo))
            {
                printf("%d %d %.2f  \n", siniestro.IDSiniestro, siniestro.NroPoliza, siniestro.ValorSiniestrado);
                fread(&siniestro, sizeof(Siniestro), 1, archivo);
            }
            fclose(archivo);
            break;
        }
    }


}
void listarPolizasVendedor(palabra apellido)
{
    FILE *polizasArch;
    FILE *sinietrosArch;
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
                    printf("NroPoliza |   ID Vendedor |   Asegurado |   Marca |   Patente |   ValorAsegurado \n");

            printf("   %d            %d           %s         %s          %s        %.2f \n", poliza.NroPoliza, poliza.IDVendedor, poliza.Asegurado, poliza.Marca, poliza.Patente, poliza.ValoAsegurado);

            Siniestro siniestro;
            sinietrosArch = fopen("archivos/Siniestros.dat", "rb");
            fread(&siniestro, sizeof(Siniestro), 1, sinietrosArch);
             printf("ID    Nro Poliza     Valor Siniestrado   \n");
            while(!feof(sinietrosArch))
            {


                if(poliza.NroPoliza == siniestro.NroPoliza)
                {
                printf("%d          %d           %.2f  \n", siniestro.IDSiniestro, siniestro.NroPoliza, siniestro.ValorSiniestrado);

                }
                  fread(&siniestro, sizeof(Siniestro), 1, sinietrosArch);
            }

                fclose(sinietrosArch);


            }
            fread(&poliza, sizeof(Poliza), 1, polizasArch);

        }
        fclose(polizasArch);
    }

}
void vendedoresAPremiar()
{
    FILE *vendedoresArchi;
    Vendedor vendedor;

    vendedoresArchi = fopen("archivos/Vendedores.dat", "rb");
    fread(&vendedor, sizeof(Vendedor), 1, vendedoresArchi);
    printf("Vendedores a premiar \n");
    while(!feof(vendedoresArchi))
    {
        int id = calcularTasaRendimiento(vendedor.IDVendedor);
        if( id< 5 && id>0)
        {
            printf(" %d", vendedor.IDVendedor);
        }
        fread(&vendedor, sizeof(Vendedor), 1, vendedoresArchi);
    }
    fclose(vendedoresArchi);

}
