#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Estructura de datos
typedef struct {
    char nombre[50];
    int puntos;
    int descendio; // 1 = Descendio, 0 = Permanece
} equipos;

// Prototipos de funciones - Parte A (Rodrigo)
void cargar_datos(const char *nombre_archivo, int *ptr);
void listar_datos(const char *nombre_archivo);

// Prototipos de funciones - Parte B (Ivan)
void listar_por_condicion(const char *nombre_archivo);
void dividir_archivo_por_booleano(const char *origen, const char *destino_desc, const char *destino_perm);

// Interfaz de menu
void mostrar_menu(void);

int main(void) {
    int opcion;
    int totalCargados;

    opcion = 0;
    totalCargados = 0;

    do {
        mostrar_menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargar_datos("equipos.txt", &totalCargados);
                break;
            case 2:
                listar_datos("equipos.txt");
                break;
            case 3:
                listar_por_condicion("equipos.txt");
                break;
            case 4:
                dividir_archivo_por_booleano("equipos.txt", "descendidos.txt", "permanecen.txt");
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida. Reintente.\n");
        }
    } while (opcion != 5);

    return 0;
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

void cargar_datos(const char *nombre_archivo, int *ptr) {
    int cantidad;
    char categoria;
    int i;
    FILE *registro;
    equipos *lista;

    cantidad = 0;
    registro = fopen(nombre_archivo, "a");

    if (registro == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", nombre_archivo);
    } else {
        printf("¿Cuantos equipos ingresara ahora?: ");
        while (cantidad <= 0) {
            scanf("%d", &cantidad);
            if (cantidad <= 0) {
                printf("Error: Ingrese un numero mayor a cero: ");
            }
        }

        *ptr = cantidad;


        lista = (equipos *)malloc(cantidad * sizeof(equipos));

        if (lista != NULL) {
            for (i = 0; i < cantidad; i++) {
                printf(" Carga Equipo %d\n", i + 1);

                printf("Ingrese nombre del equipo: ");
                scanf("%s", lista[i].nombre);

                printf("Ingrese los puntos: ");
                scanf("%d", &lista[i].puntos);

                printf("¿El equipo descendio? (s/n): ");
                do {
                    scanf(" %c", &categoria);
                    categoria = (char)tolower(categoria);
                } while (categoria != 's' && categoria != 'n');

                if (categoria == 's') {
                    lista[i].descendio = 1;
                } else {
                    lista[i].descendio = 0;
                }

                fprintf(registro, "%s %d %d\n", lista[i].nombre, lista[i].puntos, lista[i].descendio);
            }

            free(lista); // Liberacion de memoria dinamica
        }
        fclose(registro);
    }
}

void listar_datos(const char *nombre_archivo) {
    FILE *registro;
    char nombre[50];
    int puntos;
    int categoria;

    registro = fopen(nombre_archivo, "r");

    if (registro == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", nombre_archivo);
    } else {
        printf(" LISTADO GENERAL DE EQUIPOS\n");
        printf("%-20s | %-8s | %-12s\n", "NOMBRE", "PUNTOS", "DESCENDIO");


        while (fscanf(registro, "%s %d %d", nombre, &puntos, &categoria) == 3) {
            printf("%-20s | %-8d | %-12s\n", nombre, puntos, (categoria == 1) ? "SI" : "NO");
        }

        fclose(registro);
    }
}


void listar_por_condicion(const char *nombre_archivo) {
    FILE *registro;
    char nombre[50];
    int puntos;
    int descendio;
    int contadorCoincidencias;

    contadorCoincidencias = 0;
    registro = fopen(nombre_archivo, "r");

    if (registro == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", nombre_archivo);
    } else {
        printf(" EQUIPOS EN ZONA DE DESCENSO (FILTRO: DESCENDIO == 1) ===\n");
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

void dividir_archivo_por_booleano(const char *origen, const char *destino_desc, const char *destino_perm) {
    FILE *f_origen;
    FILE *archDescendidos;
    FILE *archPermanecen;
    char nombre[50];
    int puntos;
    int descendio;

    f_origen = fopen(origen, "r");
    archDescendidos = fopen(destino_desc, "w");
    archPermanecen = fopen(destino_perm, "w");

    if (f_origen == NULL || archDescendidos == NULL || archPermanecen == NULL) {
        printf("Error al abrir o generar los archivos para la division.\n");
    } else {
        while (fscanf(f_origen, "%s %d %d", nombre, &puntos, &descendio) == 3) {
            if (descendio == 1) {
                fprintf(archDescendidos, "%s %d %d\n", nombre, puntos, descendio);
            } else {
                fprintf(archPermanecen, "%s %d %d\n", nombre, puntos, descendio);
            }
        }

        fclose(f_origen);
        fclose(archDescendidos);
        fclose(archPermanecen);


        printf("Proceso de division completado correctamente:\n");
        printf(" Se creo '%s' con equipos descendidos.\n", destino_desc);
        printf(" Se creo '%s' con equipos que mantienen categoria.\n", destino_perm);

    }
}