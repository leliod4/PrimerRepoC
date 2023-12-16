//LEANDRO ODETTO
#include <stdio.h>

//LEXICO
#define NMax 50
int i;
typedef struct {
    int n[NMax];
    int cant;
    }TData;
TData a;
void Insertar(TData *b);
void Cargar(TData *b);

//INICIO
int main(){
Cargar (&a);
Insertar (&a);
for (i=0; i<=a.cant; i++){
  printf("En posicion %d el valor es: %d \n", i, a.n[i]);
}
}
void Cargar(TData *b){
int i;
i = 1;
printf("Ingrese la cantidad de numeros del arreglo: ");
scanf("%d", &b->cant);
for(i=0;i < b->cant;i++){
printf("Ingrese el elemento nro %d del arreglo(numeros del 1 al 10): ", i);
scanf("%d", &b->n[i]);
} 
}
void Insertar (TData *b){
int i;
int j;
int num;
printf("Ingrese un numero entre 1 y 10: ");
scanf("%d", &num);

if (b->cant >= NMax){ 
    printf("ERROR NO HAY LUGAR \n");
} else{
    i = 1;
    do {
        i++;
    } while ((i<=b->cant)&&(b->n[i] <= num));
    for(j = b->cant+1 ; i<j ; j--){
        b->n[j] = b->n[j-1];
    }
     i=j;
     b->n[i] = num;
}
} 
