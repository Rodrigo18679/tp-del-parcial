#include<cstdio>
#define max 50
//torneos deportivos
//parcial de paradigmas el 27/10
typedef struct {
    char equipo[max];
    int nros_integrantes=0;
    int edad;
    bool continuar=false;
}torneos;
void listar(torneos arreglo[]);
int main() {
    torneos torneos_deportivos[max];
    int nros=0;
    listar(torneos_deportivos);
    return 0;
}
void listar(torneos arreglo[]) {
    file *f= fopen("torneos.txt","r");
    if (new==null) puts("error al abrir el archivo para leer");
    else {
        int i=0;
        fprintf("nros de integrantes:");
        fcanf("%d",torneos_deportivos.nros)
    }
}
//
// Created by alexa on 6/10/2026.
//
