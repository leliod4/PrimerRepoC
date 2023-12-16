#include <stdio.h>
#include <time.h>

// Estructura para representar una fecha
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Función para calcular la edad actual
int calcularEdad(struct Fecha fechaNacimiento, struct Fecha fechaActual) {
    int edad = fechaActual.anio - fechaNacimiento.anio;

    // Verificar si ya ha pasado el cumpleaños de este año
    if (fechaActual.mes < fechaNacimiento.mes || (fechaActual.mes == fechaNacimiento.mes && fechaActual.dia < fechaNacimiento.dia)) {
        edad--;
    }

    return edad;
}

int main() {
    struct Fecha fechaNacimiento;
    struct Fecha fechaActual;

    // Solicitar al usuario que ingrese la fecha de nacimiento
    printf("Ingrese tu fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &fechaNacimiento.dia, &fechaNacimiento.mes, &fechaNacimiento.anio);

    // Obtener la fecha actual del sistema
    time_t tiempoActual = time(NULL);
    struct tm* tmActual = localtime(&tiempoActual);

    // Asignar la fecha actual
    fechaActual.dia = tmActual->tm_mday;
    fechaActual.mes = tmActual->tm_mon + 1; // tm_mon es 0-based
    fechaActual.anio = tmActual->tm_year + 1900; // tm_year es el año desde 1900

    // Calcular y mostrar la edad
    int edad = calcularEdad(fechaNacimiento, fechaActual);
    printf("Tu edad actual es: %d años\n", edad);

    return 0;
}