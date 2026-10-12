//
// Created by alexa on 11/10/2026.
//
#include <cstdio>
#include <cstdlib>
#include<funciones.h>
void cargar_datos() {
    int cantidad=0;
    FILE* registro=fopen("rodrigo.txt","a");
    if (registro==NULL) {
        printf("error al abrir el archivo");
    }else {
        printf("cuantos equipos ingresara ahora: ");
        while (cantidad<=0){
            scanf("%d", &cantidad);
            if (cantidad<=0) {
                printf("error no se admite numeros negativos");
            }
        }
        equipos *lista=(equipos*)malloc(cantidad*sizeof(equipos));
        fprintf( registro,"nombre del equipo\tpts\n");
        for (int i=0; i<cantidad; i++) {
            printf("Ingrese nombre del equipo: ");
            scanf("%s", &lista[i].nombre);
            printf("Ingrese los pts: ");
            scanf("%d", &lista[i].puntos);
            fprintf(registro,"%s\t\t\t%d\n", lista[i].nombre, lista[i].puntos);
        }
        free(lista);//para
        fclose(registro);
    }return;
}