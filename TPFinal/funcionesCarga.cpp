#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"
#include<string.h>
void verificarArchivos()
{
    FILE *archivo;
    validarArchivoVendedores(archivo);
    validarArchivoPoliza(archivo);
    validarArchivoSiniestros(archivo);
}
void validarArchivoVendedores( FILE *archivo)
{
    archivo = fopen("archivos/Vendedores.dat", "rb");

    if(!archivo)
    {
        archivo = fopen("archivos/Vendedores.dat", "wb");
        printf("Se creo el archivo Vendedores\n");
    }
    else
    {
        printf(" Ya existe el archivo Vendedores\n");
    }

    fclose(archivo);
}
void validarArchivoPoliza(FILE *archivo)
{

    archivo = fopen("archivos/Polizas.dat", "rb");

    if(!archivo)
    {
        archivo = fopen("archivos/Polizas.dat", "wb");
        printf("Se creo el archivo Polizas \n");
    }
    else
    {
        printf(" Ya existe el archivo Polizas\n");
    }

    fclose(archivo);
}
void validarArchivoSiniestros(FILE *archivo)
{
     archivo = fopen("archivos/Siniestros.dat", "rb");

    if(!archivo)
    {
        archivo = fopen("archivos/Siniestros.dat", "wb");
        printf("Se creo el archivo Siniestros \n");
    }
    else
    {
        printf(" Ya existe el archivo Siniestros\n");
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
        cargarVendedor(archivo);
        break;
        }

    case 2:
        {
        cargarPoliza(archivo);
        break;
        }

    case 3:
        {
        cargarSiniestro(archivo);
        break;
        }

    }

}
void cargarVendedor(FILE *archivo)
{
       Vendedor vendedor;
        palabra apellido;
        int id = 0;

        printf("\n");
        printf("Ingrese el id del vendedor \n");
        scanf("%d",&id);

        printf("Ingrese apellido \n");
        scanf("%s",&apellido);

        int check = valorExisteVendedor(apellido, id);
        if(check == -1)
        {
            printf("El vendedor ya esta cargado en la db");


        }
        else
        {
        archivo = fopen("archivos/Vendedores.dat", "ab");

        strcpy(vendedor.ApellidoVendedor, apellido);
        vendedor.IDVendedor =id;



        fwrite(&vendedor,sizeof(Vendedor),1,archivo);
        fclose(archivo);


        }

}
void cargarPoliza(FILE *archivo)
{
      Poliza poliza;
        palabra apellido;
        int idVendedor = 0;
        int idPoliza = 0;


        printf("Ingrese apellido del vendedor \n");
        scanf("%s",&apellido);
        idVendedor = validarVendedor(apellido);
        if(idVendedor == -1)
            {
                printf("No existe vendedor \n");



            }

        else{

        archivo = fopen("archivos/Polizas.dat", "ab");
        poliza.IDVendedor = idVendedor;
        printf("Ingrese Nro de poliza: \n");
        scanf("%d", &idPoliza);

        if(existePoliza(idPoliza)==-1)
        {
            printf("El numero de poliza ya esta cargada \n");

        }
        else
        {


        poliza.NroPoliza = idPoliza;

        printf("Ingrese vombre del asegurado: \n ");
        scanf("%s", poliza.Asegurado);

        printf("Ingrese marca del auto: \n ");
        scanf("%s", poliza.Marca);

        printf("Ingrese patente: \n ");
        scanf("%s", poliza.Patente);

        printf("Ingrese valor asegurado: \n");
        scanf("%f", &poliza.ValoAsegurado);

        fwrite(&poliza, sizeof(Poliza), 1, archivo);
        fclose(archivo);
        }

}
}
void cargarSiniestro(FILE *archivo)
{
        Siniestro siniestro;
        int numPoliza;
        archivo = fopen("archivos/Siniestros.dat", "ab");
        printf("Indicar poliza de seguro del auto: \n");

        scanf("%d", &numPoliza);
        if(validarPoliza(numPoliza) != 1)
        {
            printf("Numero de poliza no se encusntra\n");


        }
        else
        {


        siniestro.NroPoliza = numPoliza;
        printf("Ingrese id del siniestro \n ");
        scanf("%d", &siniestro.IDSiniestro);



        printf("Valor siniestrado: ");
        scanf("%f", &siniestro.ValorSiniestrado);

        fwrite(&siniestro, sizeof(Siniestro), 1, archivo);
        fclose(archivo);

            }
}
int existePoliza(int idPoliza)
{
     FILE *archivo;
    Poliza poliza;


    archivo = fopen("archivos/Polizas.dat", "rb");
    fread(&poliza, sizeof(Poliza), 1, archivo);

    while(!feof(archivo))
    {

       if(poliza.NroPoliza == idPoliza)
       {
           fclose(archivo);
            return -1;
       }

        fread(&poliza, sizeof(Poliza), 1, archivo);
    }

    fclose(archivo);
    return 1;

}
int valorExisteVendedor(palabra apellido, int id)
{
     FILE *archivo;
    Vendedor auxVendedor;


    archivo = fopen("archivos/Vendedores.dat", "rb");
    fread(&auxVendedor, sizeof(Vendedor), 1, archivo);

    while(!feof(archivo))
    {
        if(strcmp(apellido, auxVendedor.ApellidoVendedor) == 0 || id == auxVendedor.IDVendedor)
        {
            fclose(archivo);
            return -1;

        }
        fread(&auxVendedor, sizeof(Vendedor), 1, archivo);
    }

    fclose(archivo);
    return 1;
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
            valorAsegurado += poliza.ValoAsegurado;

            fread(&siniestro, sizeof(Siniestro), 1, sini);
            while(!feof(sini))
            {
                if(poliza.NroPoliza == siniestro.NroPoliza)
                {
                    valorSiniestrado += siniestro.ValorSiniestrado;
                }
                fread(&siniestro, sizeof(Siniestro), 1, sini);
            }
        }


        capitalAsegurado = poliza.ValoAsegurado + capitalAsegurado;
        fread(&poliza, sizeof(Poliza), 1, pol);
    }

    fclose(pol);
    fclose(sini);
     total =  (((valorAsegurado - valorSiniestrado)*100)/capitalAsegurado);
    return total;

}




