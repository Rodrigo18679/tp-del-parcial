#include "funciones.h"//incluyo funciones de archivo de funciones.h

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
                cargar_datos(&totalCargados);
                break;
            case 2:
                listar_datos();
                break;
            case 3:
                listar_por_condicion();
                break;
            case 4:
                dividir_archivo_por_booleano();
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida. Reintente.\n");
        }
    }while (opcion != 0);

    return 0;
}
