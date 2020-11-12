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
