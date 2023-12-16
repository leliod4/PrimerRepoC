#include <stdio.h>
#include <string.h>
int num;
int resultado;
int FactorialAumento(int n);
void FactorialCola (int n, int *res);
int main(){
    printf("Ingrese un valor para ver su factorial en ambas versiones, en caso de ingresar negativo se finaliza el programa: ");
    scanf("%d", &num);
    while(0<num){
        resultado=1;
        printf("Factorial con aumento: %d \n", FactorialAumento(num));
        FactorialCola(num,&resultado);
        printf("Factorial en cola: %d \n", resultado);
        printf("Otro factorial: ");
        scanf("%d", &num);
    }
}

int FactorialAumento(int n){
    if (n==0){
        return 1;
    }else {
        return n * FactorialAumento(n-1);
    }
}

void FactorialCola (int n, int *res){
    if(n==1){
        *res=1;
     }else {   
        *res = *res * n;
        FactorialCola(n-1, res);
    }
}