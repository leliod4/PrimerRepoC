#include <stdio.h>
#include <stdlib.h>
//LEXICO
int n1;
int n2;
int n;
int i;
int max;
int cant;
int mayor(int a, int b);

//INICIO
int main(){
    printf("Ingrese la cantidad de numeros a evaluar: ");
    scanf("%d",&cant);
    printf("Ingrese el primer numero: ");
    scanf("%d",&n1);
    printf("Ingrese otro numero: ");
    scanf("%d",&n2);
    i = 2;
    do{
        printf("Ingrese otro numero: ");
        scanf("%d",&n);
        max = mayor(max,n);
        i = i + 1;
    } while(i<cant);
        printf("El mayor entre todos los numeros es: %d \n", max);
    }
    
    int mayor(int a, int b){
    return (((a+b)+abs(a-b))/2);
}