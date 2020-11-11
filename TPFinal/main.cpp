#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include "funciones.c"



int main()
{
      FILE *archivo;
    verificarArchivos();
    cargarDatos(archivo);
    return 0;
}
