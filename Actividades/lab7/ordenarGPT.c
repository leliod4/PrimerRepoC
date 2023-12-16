#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define una estructura para representar a una persona
struct Persona {
    char nombre[50];
    int edad;
};

// Función de comparación para qsort
int compararPersonas(const void *a, const void *b) {
    return strcmp(((struct Persona*)a)->nombre, ((struct Persona*)b)->nombre);
}

int main() {
    // Definir un arreglo de estructuras Persona
    struct Persona listaDePersonas[10]; // Puedes ajustar el tamaño según tus necesidades

    // Llenar el arreglo con datos de personas
    strcpy(listaDePersonas[0].nombre, "Juan");
    listaDePersonas[0].edad = 25;

    strcpy(listaDePersonas[1].nombre, "Maria");
    listaDePersonas[1].edad = 30;

    strcpy(listaDePersonas[2].nombre, "Leandro");
    listaDePersonas[2].edad = 30;

    // Puedes continuar llenando el arreglo de personas de la misma manera

    // Obtener el número de elementos en el arreglo
    int numPersonas = 3; // En este caso, tenemos dos personas

    // Ordenar el arreglo alfabéticamente por nombre
    qsort(listaDePersonas, numPersonas, sizeof(struct Persona), compararPersonas);

    // Imprimir las personas ordenadas
    for (int i = 0; i < numPersonas; i++) {
        printf("Nombre: %s, Edad: %d\n", listaDePersonas[i].nombre, listaDePersonas[i].edad);
    }

    return 0;
}
