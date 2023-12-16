#include <stdio.h>
#include <stdlib.h>

int fib2;
int fib1;
int fib;
int i;
int n;

int main(){

printf("Ingrese el numeros del sistema fibonacci: ");
scanf("%d", &n);

if(n==0){
    printf("%d \n", n);
} else{
    fib2 = 0;
    fib1 = 1;
    printf("%d \n", fib2);
    i = 0;
    do{
        fib = fib2 + fib1;
        fib1 = fib2;
        fib2 = fib;
        printf("El numero del sistema fibonacci en %d es: %d \n", i, fib);
        i++;
    }while(i <= n);
    }
}