#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"
#include "funcionesC.cpp"


int main()

{
    FILE *archi;

    verificarArchivos();
    listarInfo(archi);
    return 0;
}
