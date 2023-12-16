#include <stdio.h>
#include <stdlib.h>


int mmax;
int mmin;
int i;
int lluvia;
int pmaxima;
int pminima;

int main(){
i = 0;
pmaxima = 0;
pminima = 10000;
do{
    i++;
    printf("Ingrese la precipitacion del mes %d: ", i);
    scanf("%d", &lluvia);
    if(lluvia < pminima){
        pminima = lluvia;
        mmin = i;
    }
    if (pmaxima < lluvia){
        pmaxima = lluvia;
        mmax = i;
    } 
} while(i != 12);

printf("La precipitacion minima es: %d \n", pminima);
printf("En el mes %d \n", mmin);
printf("La precipitacion maxima es: %d \n", pmaxima);
printf("En el mes %d \n", mmax);
}