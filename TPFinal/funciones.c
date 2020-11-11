#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

void verificarArchivos() {

    FILE *archivo;

    archivo = fopen("archivos/Vendedores.dat", "rb");

    if(!archivo) {
        archivo = fopen("archivos/Vendedores.dat", "wb");
        printf("Se creo el archivo \n");
    } else {
        printf(" Ya existe el archivo\n");
    }

    fclose(archivo);

    archivo = fopen("archivos/Polizas.dat", "rb");

    if(!archivo) {
        archivo = fopen("archivos/Polizas.dat", "wb");
         printf("Se creo el archivo \n");
    } else {
         printf(" Ya existe el archivo\n");
    }

    fclose(archivo);

    archivo = fopen("archivos/Siniestros.dat", "rb");

    if(!archivo) {
        archivo = fopen("archivos/Siniestros.dat", "wb");
      printf("Se creo el archivo \n");
    } else {
      printf(" Ya existe el archivo\n");
    }

    fclose(archivo);
}
