//
// Funciones de Rodrigo + Ivan
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Estructura
typedef struct {
    char nombre[50];
    int puntos;
    int descendio; // Campo booleano: 1 = Descendio (true), 0 = No descendio (false)
}equipos;

//Prototipos de funciones de Rodrigo
void cargar_datos(int *ptr);
void listar_datos(void);

//Prototipos agregados para Parte de Ivan
void listar_por_condicion(void);
void dividir_archivo_por_booleano(void);
void mostrar_menu(void);

#endif //FUNCIONES_H