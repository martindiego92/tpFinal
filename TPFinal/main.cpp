#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include "funcionesListar.cpp"
#include "funcionesCarga.cpp"



int main()
{
      FILE *archivo;
    verificarArchivos();
    for(int i = 0 ; i <3 ; i++)
    {
        //cargarDatos(archivo);
    }

    //listarInfo(archivo);

   // listarPolizasVendedor("jorge");
    vendedoresAPremiar();
    return 0;
}
