#include <stdio.h>

//LEXICO
#define NMax 50
int i;
typedef struct {
    int n[NMax];
    int cant;
    }TData;
TData a;

void Cargar(TData *b);
int main(){
Cargar (&a);
//MOSTRAR
for (i=0; i<a.cant; i++){
  printf("En posicion %d el valor es: %d \n", i, a.n[i]);
}
}
void Cargar(TData *b){
int i;
i = 1;
printf("Ingrese la cantidad de numeros del arreglo: ");
scanf("%d", &b->cant);
for(i=0;i < b->cant;i++){
printf("Ingrese el elemento nro %d del arreglo: ", i);
scanf("%d", &b->n[i]);
} 
}