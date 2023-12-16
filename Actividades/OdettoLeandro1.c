#include <stdio.h> 
#include <string.h>
#define Fil 100
#define Col 100
typedef struct {
 int m[Fil][Col];
 int cantFila;
 int cantCol;
 }TData;
TData Tabla;
void Cargar(TData *b);
int Repetido(TData b);

//INICIO
int main(){
    Cargar(&Tabla);
    if (Repetido(Tabla) == 1){
        printf("Verdadero \n");
    } else{
        printf("Falso \n");
    }
}
void Cargar(TData *b){
    int i,j;
    printf("Ingrese la cantidad de filas del arreglo: ");
    scanf("%d", &b->cantFila);
    printf("Ingrese la cantidad de columnas del arreglo: ");
    scanf("%d", &b->cantCol);
    for(i=0;i < b->cantFila;i++){
        for(j=0;j < b->cantCol;j++){
            printf("Ingrese el elemento nro %d,%d del arreglo: ", i, j);
            scanf("%d", &b->m[i][j]);
    }
    } 
}
int Repetido(TData b){
    int n;
    int i,j;
    int cont;
    cont=0;
    printf("Ingrese el numero que quiere verificar si se repite 3 veces: ");
    scanf("%d", &n);
    for(i=0;i < b.cantFila;i++){
        for(j=0; j < b.cantCol;j++){
            if (b.m[i][j] == n) {
                cont=cont+1;
            }
        }
    }
    if (cont>=3){
        return 1;
    } else{
        return 0;
    }
    
}