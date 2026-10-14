Trabajo Práctico: Sistema de Gestión de Equipos de Fútbol

Materia: Programación 1 — USAL (Turno Noche)  
Lenguaje: C Estándar   
Integrantes: Rodrigo y Iván  


1. Descripción General
El sistema es una aplicación de consola desarrollada en C puro para la gestión y procesamiento de información de equipos de fútbol mediante archivos de texto. Permite registrar nuevos clubes, consultar el listado general, aplicar filtros condicionales según el estado de descenso y clasificar/dividir automáticamente la base de datos en dos archivos nuevos.


2. Estructura de Datos (`struct equipos`)

La entidad principal está definida en C Estándar mediante la siguiente estructura:


typedef struct {
    char nombre[50]; // Nombre del equipo (sin espacios)
    int puntos;      // Puntos acumulados en el torneo
    int descendio;   // Campo booleano: 1 = Descendió, 0 = Permanece
} equipos;
