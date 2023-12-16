//LEANDRO ODETTO

//Esta accion lo que hace es invertir los valores de a y b.
//Lo quen hace ese algoritmo es invertir los valores de a y b (primer salida),
// y mostrar el primer valor que se le entra a la variable b (segunda salida).

//Lo que hace la implementacion, que corregi(supongo), es invertir los valores de a y b,
// luego los vuelve a pedir y los vuelve a invertir para mostrar el verdadero valor de a.

//En el algoritmo sin corregir, lo que muestra al ultimo es que a es 0. 

#include <stdio.h>
//LEXICO
int a,b;
void Swap (int *x,int *y);
//INICIO
int main() {
printf("introduce el valor de la variable a: ");
scanf("%i",&a);
printf("introduce el valor de la variable b: ");
scanf("%i",&b);
Swap (&a, &b);
printf (" el valor de a es: %d ", a);
printf ("\n el valor de b es: %d ", b);
printf("\n introduce el valor de la variable a: ");
scanf("%i",&a);
printf("introduce el valor de la variable b: ");
scanf("%i",&b);
Swap (&a, &b);
printf ("el valor de a es: %d ", a);
return 0;
}
//ACCION
void Swap (int *x,int *y) {
*x = (*x)+(*y);
*y = (*x)-(*y);
*x = (*x)-(*y);
}