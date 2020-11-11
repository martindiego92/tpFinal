#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef char palabra[30];
typedef char stringpat[8];
struct vendedor
{
    int IDVendedor;
    palabra ApellidoVendedor;
    float TasaRendimiento;
};

struct poliza
{
    int NroPoliza;
    int IDVendedor;
    palabra Asegurado;
    palabra Marca;
    stringpat Patente;
    float ValoAsegurado;

};

struct Siniestro
{
    int IDSiniestro;
    int NroPoliza;
    float ValorSiniestrado;
};

void verificarArchivos();
void cargarDatos(FILE *archivo);
int validarVendedor(palabra ApellidoVendedor);
int validarPoliza(int NroPoliza);
float calcularTasaRendimiento(int IDVendedor);
void listarInfo(FILE *archivo);
void listarPolizasVendedor(palabra ApellidoVendedor);
void endedoresAPremiar();
void AseguradoPiedra();
#endif // FUNCIONES_H_INCLUDED