#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"
#include<string.h>
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
        {


        Vendedor vendedor;
        archivo = fopen("archivos/Vendedores.dat","ab");
        printf("\n");
        printf("Ingrese el id del vendedor \n");
        scanf("%d",&vendedor.IDVendedor);
        printf("Ingrese apellido \n");
        scanf("%s",&vendedor.ApellidoVendedor);

        fwrite(&vendedor,sizeof(Vendedor),1,archivo);
        break;
         }
    case 2:
        {


        Poliza poliza;
        palabra apellido;
        int idVendedor = 0;


        //despues valido
        printf("Ingrese apellido del vendedor \n");
        scanf("%s",&apellido);
        idVendedor = validarVendedor(apellido);
        if(idVendedor == -1)
            {
                printf("No existe vendedor \n");
                //printf("Por favor ingrese nuevamente el apellido \n");
                //scanf("%s",&apellido);
                //idVendedor = validarVendedor(apellido);
                break;

            }
        archivo = fopen("archivos/Polizas.dat", "ab");
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
               }
    case 3:
        {


        Siniestro siniestro;
        int numPoliza;
        archivo = fopen("archivos/Siniestros.dat", "ab");
        printf("Indicar poliza de seguro del auto: \n");

        scanf("%d", &numPoliza);
        if(validarPoliza(numPoliza) != 1)
        {
            printf("Numero de poliza no se encusntra\n");
            break;

        }
        printf("Ingrese id del siniestro \n ");
        scanf("%d", &siniestro.IDSiniestro);



        printf("Valor siniestrado: ");
        scanf("%f", &siniestro.ValorSiniestrado);

        fwrite(&siniestro, sizeof(Siniestro), 1, archivo);


        break;
    }
      }
    fclose(archivo);
}

int validarVendedor(palabra apellido)
{
     FILE *archivo;
    Vendedor auxVendedor;
    int check = -1;

    archivo = fopen("archivos/Vendedores.dat", "rb");
    fread(&auxVendedor, sizeof(Vendedor), 1, archivo);

    while(!feof(archivo))
    {
        if(strcmp(apellido, auxVendedor.ApellidoVendedor) == 0)
        {
            fclose(archivo);
            return auxVendedor.IDVendedor;

        }
        fread(&auxVendedor, sizeof(Vendedor), 1, archivo);
    }

    fclose(archivo);
    return -1;
}
int validarPoliza(int num)
{
    FILE *archivo;
    Poliza poliza;

    archivo = fopen("archivos/Polizas.dat", "rb");
    fread(&poliza, sizeof(Poliza), 1, archivo);

    while(!feof(archivo))
    {
        if(num == poliza.NroPoliza)
        {
            fclose(archivo);
            return 1;
        }
        fread(&poliza, sizeof(Poliza), 1, archivo);
    }

    fclose(archivo);
    return -1;
}

float calcularTasaRendimiento(int id)
{

    FILE *pol;
    FILE *sini;

    float valorAsegurado = 0;
    float valorSiniestrado = 0;
    float capitalAsegurado = 0;
    float total = 0;

    Poliza poliza;
    Siniestro siniestro;

    pol = fopen("archivos/Polizas.dat", "rb");
    sini = fopen("archivos/Siniestros.dat", "rb");

    fread(&poliza, sizeof(Poliza), 1, pol);

    while(!feof(pol))
    {
        if(id == poliza.IDVendedor)
        {
            valorAsegurado = poliza.ValoAsegurado + valorAsegurado;

            fread(&siniestro, sizeof(Siniestro), 1, sini);
            while(!feof(sini))
            {
                if(poliza.NroPoliza == siniestro.NroPoliza)
                {
                    valorSiniestrado = siniestro.ValorSiniestrado + valorSiniestrado;
                }
                fread(&siniestro, sizeof(Siniestro), 1, sini);
            }
        }

        capitalAsegurado = poliza.ValoAsegurado + capitalAsegurado;
        fread(&poliza, sizeof(Poliza), 1, pol);

    }
    fclose(pol);
    fclose(sini);
     total =  (float)(((valorAsegurado - valorSiniestrado)*100)/capitalAsegurado);
    return total;

}




