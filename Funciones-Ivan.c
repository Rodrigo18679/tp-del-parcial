// Funciones_ivan.c
//Muestra unicamente los equipos que cumplen la condicion (descendio == 1)

#include "funcionesRodrigo.h"

void listar_por_condicion(void) {

    FILE *registro;
    char nombre[50];
    int puntos;
    int descendio;
    int contadorCoincidencias;

    contadorCoincidencias = 0;
    registro = fopen("equipos.txt", "r");

    if (registro == NULL) {
        printf("Error: No se pudo abrir el archivo equipos.txt\n");
    }else {
        printf("EQUIPOS EN ZONA DE DESCENSO (FILTRO: DESCENDIO == 1)\n");
        printf("%-20s | %-8s\n", "NOMBRE", "PUNTOS");

        while (fscanf(registro, "%s %d %d", nombre, &puntos, &descendio) == 3) {
            if (descendio == 1) {
                printf("%-20s | %-8d\n", nombre, puntos);
                contadorCoincidencias++;
            }
        }

        fclose(registro);

        if (contadorCoincidencias == 0) {
            printf("No existen equipos registrados que hayan descendido.\n");
        }
    }
}

void dividir_archivo_por_booleano(void) {

    FILE *origen;
    FILE *archDescendidos;
    FILE *archPermanecen;
    char nombre[50];
    int puntos;
    int descendio;

    origen = fopen("equipos.txt", "r");
    archDescendidos = fopen("descendidos.txt", "w");
    archPermanecen = fopen("permanecen.txt", "w");

    if (origen == NULL || archDescendidos == NULL || archPermanecen == NULL) {
        printf("Error al abrir o generar los archivos para la division.\n");
    } else {
        while (fscanf(origen, "%s %d %d", nombre, &puntos, &descendio) == 3) {
            if (descendio == 1) {
                fprintf(archDescendidos, "%s %d %d\n", nombre, puntos, descendio);
            } else {
                fprintf(archPermanecen, "%s %d %d\n", nombre, puntos, descendio);
            }
        }

        fclose(origen);
        fclose(archDescendidos);
        fclose(archPermanecen);


        printf(" Proceso de division completado correctamente:\n");
        printf(" Se creo 'descendidos.txt' con equipos descendidos.\n");
        printf(" Se creo 'permanecen.txt' con equipos que mantienen categoria.\n");
    }
}
void mostrar_menu(void) {

    printf("   SISTEMA DE GESTION DE EQUIPOS DE FUTBOL\n");

    printf("1. Agregar equipos al archivo\n");
    printf("2. Listar todos los equipos\n");
    printf("3. Listar solo equipos descendidos (Condicion)\n");
    printf("4. Dividir archivo (Descendidos vs Permanecen)\n");
    printf("5. Salir del sistema\n");

    printf("Ingrese una opcion: ");
}