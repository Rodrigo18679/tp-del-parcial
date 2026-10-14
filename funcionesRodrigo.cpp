//
// funciones.C
//Rodrigo
#include "funcionesRodrigo.h" //Se incluyen todas la funciones del Archivo funciones.h

void cargar_datos(int*ptr) {

    int cantidad;
    char categoria;
    int i;
    FILE *registro;
    equipos *lista;

    cantidad=0;
    registro = fopen("equipos.txt","a"); //Modo append: al final


    if (registro==NULL) {
        printf("Error: No se pudo abrir el archivo equipos.txt");
    }else {
        printf("¿Cuantos equipos ingresara ahora?: ");
        while (cantidad <= 0){
            scanf("%d", &cantidad);
            if (cantidad<=0) {
                printf("Error: Ingrese un numero mayor a cero: ");
            }
        }

        *ptr = cantidad;
        //Se Reserva memoria
        lista = (equipos *)malloc(cantidad * sizeof(equipos));

        if (lista !=NULL) {
            for (i = 0; i < cantidad; i++) {
                 printf("Cargar Equipo %d", i + 1);

                printf("Ingrese nombre del equipo: ");
                scanf("%s", lista[i].nombre);

                printf("Ingrese los pts: ");
                scanf("%d", &lista[i].puntos);

                printf("¿El equipo descendio? s/n ");
                do {
                    scanf("%c", &categoria);
                    categoria = (char)tolower(categoria);
                }while (categoria !='s' && categoria !='n');
                if (categoria == 's') {
                    lista[i].descendio= 1;
                }else {
                    lista[i].descendio= 0;
                }

                fprintf(registro,"%s %d %d\n", lista[i].nombre, lista[i].puntos, lista[i].descendio);
            }
            free(lista);
        }
        fclose(registro);
    }

}

void listar_datos() {

    FILE *registro;
    char nombre[50];
    int puntos;
    int categoria;

   registro = fopen("equipos.txt","r");

    if (registro==NULL) {
        printf("Error: No se pudo abrir el archivo equipos.txt\n");
    }else {
        printf("LISTA GENERAL DE EQUIPOS\n");
        printf("%-20s | %-8s | %-12s\n", "NOMBRE", "PUNTOS", "DESCENDIO");

        while (fscanf(registro,"%s %d %d",nombre,&puntos,&categoria)==3) {
            printf("%-20s | %-8d | %-12s\n", nombre, puntos, (categoria == 1) ? "SI" : "NO");
        }

        fclose(registro);
    }
}