//main
#include "Funciones-Rodrigo+Ivan.c"//incluyo funciones de archivo de funciones.h

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
    }while (opcion != 5);

    return 0;
}
