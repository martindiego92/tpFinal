#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef char palabra[30];
typedef char stringpat[8];

typedef struct
{
    int IDVendedor;
    palabra ApellidoVendedor;
    float TasaRendimiento;

}Vendedor;

typedef struct
{
    int NroPoliza;
    int IDVendedor;
    palabra Asegurado;
    palabra Marca;
    stringpat Patente;
    float ValoAsegurado;

}Poliza;

typedef struct
{
    int IDSiniestro;
    int NroPoliza;
    float ValorSiniestrado;

}Siniestro;
void dibujarMenu();

void verificarArchivos();
void cargarDatos(FILE *archivo);
int validarVendedor(palabra ApellidoVendedor);
int validarPoliza(int NroPoliza);
float calcularTasaRendimiento(int IDVendedor);
void listarInfo(FILE *archivo);
void listarPolizasVendedor(palabra ApellidoVendedor);
void vendedoresAPremiar();
void AseguradoPiedra();
void menuCargaDatos();
int valorExisteVendedor(palabra, int);
int existePoliza(int );

#endif // FUNCIONES_H_INCLUDED
