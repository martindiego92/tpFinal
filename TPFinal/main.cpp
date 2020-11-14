#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include "funcionesListar.cpp"
#include "funcionesCarga.cpp"



int main()
{

    int exit = 0;
    int op;
    FILE *archivo;
    printf("Cargando archivos...\n");
    verificarArchivos();
    printf("Bienvenido \n");
    while(exit!=1)
    {
        dibujarMenu();
        scanf("%d",&op);
        switch(op)
        {
        case 1 :

            verificarArchivos();
            break;
        case 2 :

            cargarDatos(archivo);
            break;
        case 3:

           listarInfo(archivo);
           break;

        case 4:
            palabra apellido;
            printf("Ingrese apellido \n");
            scanf("%s",&apellido);
            listarPolizasVendedor(apellido);
            break;

        case 5:
            vendedoresAPremiar();
            break;
        case 6:
            AseguradoPiedra();
            break;

        case 7:
            exit=1;
            printf("Adios \n");
            break;

        default:
            printf("Operacion invalida \n");
        }



    }

    return 0;
}
