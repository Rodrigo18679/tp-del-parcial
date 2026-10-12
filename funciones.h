//
// Created by alexa on 11/10/2026.
//

#ifndef TP_DEL_PARCIAL_FUNCIONES_H
#define TP_DEL_PARCIAL_FUNCIONES_H
#include <cstdbool>

typedef struct {
    char nombre[50];
    int puntos=0;
    bool descendio;
}equipos;
void cargar_datos(int*ptr);
void listar_datos();
#endif //TP_DEL_PARCIAL_FUNCIONES_H