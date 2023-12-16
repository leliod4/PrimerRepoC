#include <stdio.h>
#include <stdlib.h>

//LEXICO
#define Max 50;
typedef struct {
    char n[Max];
    int cant;
    }TData;
TData a;
int i;
int Espejo(TData b);
int main(){
printf("Ingrese la cantidad de letras: ");
scanf("%d",&a.cant);
//carga
i = 0;
while(i<a.cant){
 scanf("%s",&a.n[i]);
 i++;
}
printf("Su palabra al revez es: %s \n", Espejo(a));
}

int Espejo(TData b){
    int i;
    int j;
    TData c;
i=1;
j=b.cant;

do{
    c.n[j] = b.n[i];
    i++;
    j--;
} while((i <= b.cant)&&(1 <= j));

c.cant = b.cant;
return c;
}
 

