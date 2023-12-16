#include <stdio.h>
#include <stdlib.h>

int peso;
int altura;
int res;
void Indice(int p, int a, int *in);

int main(){
printf("Ingrese su peso: ");
scanf("%d", &peso);
printf("Ingrese su altura: ");
scanf("%d", &altura);
Indice(peso,altura,&res);
if (res = 1){
    printf("NORMAL \n");
} else{
    if(res = 2){
        printf("SOBREPESO \n");
    } else{
        printf("OBESIDAD \n");
    }
}
}
void Indice(int p, int a, int *in){
int num;
num = p / (a*a);
if(num < 25){
    *in = 1;
}   else{
        if(num < 30){
            *in = 2;
    }   else{
     *in = 3;       
    }
}
}
