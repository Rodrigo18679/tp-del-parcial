//
// Created by alexa on 11/10/2026.
//
#include <cstdio>
#include <cstdlib>
#include<funciones.h>
#include <locale>
#include <cstdbool>

void cargar_datos(int*ptr) {
    int cantidad=0;
    char categoria;
    FILE* registro=fopen("equipos.txt","w");
    if (registro==NULL) {//creo que lo hice mal, porque creo innecesario pero bueno mejor precavido jajaja
        printf("error al abrir el archivo");
    }else {
        printf("cuantos equipos ingresara ahora: ");
        while (cantidad<=0){
            scanf("%d", &cantidad);
            if (cantidad<=0) {
                printf("error no se admite numeros negativos");
            }
        }
        *ptr=cantidad;
        equipos *lista=(equipos*)malloc(cantidad*sizeof(equipos));
        //fprintf( registro,"nombre del equipo\tpts\n");
        for (int i=0; i<cantidad; i++) {
            printf("Ingrese nombre del equipo: ");
            scanf("%s", &lista[i].nombre);
            printf("Ingrese los pts: ");
            scanf("%d", &lista[i].puntos);
            printf("¿el equipo descendio s/n?");
            do {
                scanf("%c", &categoria);
                categoria=tolower(categoria);
            }while (categoria!='s' && categoria!='n');
            if (categoria=='s') {
                lista[i].descendio=true;
            }else {
                lista[i].descendio=false;
            }
            fprintf(registro,"%s\t\t\t%d\t%hhd\n", lista[i].nombre, lista[i].puntos,lista[i].descendio);
        }free(lista);
        fclose(registro);
    }return;
}
void listar_datos() {
    FILE *registro=fopen("equipos.txt","r");
    if (registro==NULL) {
        printf("error al abrir el archivo");
    }else {
        char nombre[50];
        int puntos;
        int categoria;
        char encabezado[100];
        //fgets(encabezado, sizeof(encabezado), registro);
        while (fscanf(registro,"%s %d %d",nombre,&puntos,&categoria)==3) {
            printf("equipo: %s \t puntos: %d\t descendio: %d\n", nombre, puntos, categoria);
        }
        fclose(registro);
        }
    return;
    }