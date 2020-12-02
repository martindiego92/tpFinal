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
//Funciones para cargar de datos
void verificarArchivos();
void validarArchivoVendedores( FILE *archivo);
void validarArchivoPoliza(FILE *archivo);
void validarArchivoSiniestros(FILE *archivo);
void cargarDatos(FILE *archivo);
int validarVendedor(palabra ApellidoVendedor);
int validarPoliza(int NroPoliza);
float calcularTasaRendimiento(int IDVendedor);
void cargarVendedor(FILE *archivo);
void cargarPoliza(FILE *archivo);
void cargarSiniestro(FILE *archivo);

//Funciones para listarInformacion
void listarInfo(FILE *archivo);
void listarPolizasVendedor(palabra ApellidoVendedor);
void vendedoresAPremiar();
void AseguradoPiedra();
void menuCargaDatos();
int valorExisteVendedor(palabra, int);
int existePoliza(int );
void listarInfoPolizas(FILE *archivo);
void listarInfoVendedores(FILE *archivo);
void listarInfoSiniestros(FILE*archivo);





#endif // FUNCIONES_H_INCLUDED
