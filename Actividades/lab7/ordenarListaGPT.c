#include <stdio.h>
#include <string.h>

// Define una estructura para representar a una persona
struct Persona {
    char nombre[50];
    int edad;
};

// Función para comparar nombres alfabéticamente
int compararNombres(const void *a, const void *b) {
    return strcmp(((struct Persona*)a)->nombre, ((struct Persona*)b)->nombre);
}

int main() {
    // Definir un arreglo de estructuras Persona
    struct Persona listaDePersonas[10]; // Puedes ajustar el tamaño según tus necesidades

    // Llenar el arreglo con datos de personas
    strcpy(listaDePersonas[0].nombre, "Ana");
    listaDePersonas[0].edad = 25;

    strcpy(listaDePersonas[1].nombre, "Carlos");
    listaDePersonas[1].edad = 30;

    int numPersonas = 2; // En este caso, tenemos dos personas

    // Ordenar el arreglo alfabéticamente por nombre
    qsort(listaDePersonas, numPersonas, sizeof(struct Persona), compararNombres);

    // Imprimir las personas ordenadas
    printf("Personas ordenadas alfabéticamente:\n");
    for (int i = 0; i < numPersonas; i++) {
        printf("Nombre: %s, Edad: %d\n", listaDePersonas[i].nombre, listaDePersonas[i].edad);
    }

    // Insertar un nuevo nombre (por ejemplo, "David") en el arreglo ordenado
    char nuevoNombre[50];
    strcpy(nuevoNombre, "David");

    // Encontrar la posición adecuada para insertar el nuevo nombre
    int posicion = 0;
    while (posicion < numPersonas && strcmp(nuevoNombre, listaDePersonas[posicion].nombre) > 0) {
        posicion++;
    }

    // Desplazar los elementos para abrir espacio para el nuevo nombre
    for (int i = numPersonas; i > posicion; i--) {
        listaDePersonas[i] = listaDePersonas[i - 1];
    }

    // Insertar el nuevo nombre en la posición adecuada
    strcpy(listaDePersonas[posicion].nombre, nuevoNombre);
    listaDePersonas[posicion].edad = 0; // Puedes establecer la edad apropiada

    // Incrementar el contador de personas
    numPersonas++;

    // Imprimir el arreglo actualizado
    printf("\nPersonas ordenadas alfabéticamente después de la inserción:\n");
    for (int i = 0; i < numPersonas; i++) {
        printf("Nombre: %s, Edad: %d\n", listaDePersonas[i].nombre, listaDePersonas[i].edad);
    }

    return 0;
}
