// Funciones_Ivan.c
//Muestra unicamente los equipos que cumplen la condicion (descendio == 1)

#include "Funciones-Rodrigo.h"

void listar_por_condicion(const char *nombre_archivo) {
    FILE *registro;
    char nombre[50];
    int puntos;
    int descendio;
    int contadorCoincidencias;

    contadorCoincidencias = 0;
    registro = fopen(nombre_archivo, "r");

    if (registro == NULL) {
        printf("Error: No se pudo abrir el archivo equipos.txt\n");
    } else {
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
    FILE *f_origen;
    FILE *archDescendidos;
    FILE *archPermanecen;
    char nombre[50];
    int puntos;
    int descendio;

    f_origen = fopen(origen, "r");
    archDescendidos = fopen(destino_desc, "w");
    archPermanecen = fopen(destino_perm, "w");

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
        printf(" Se creo '%s' con equipos descendidos.\n", destino_desc);
        printf(" Se creo '%s' con equipos que mantienen categoria.\n", destino_perm);
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
