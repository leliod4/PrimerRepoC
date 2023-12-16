#include <stdio.h>
#include <string.h>
int num;
int SumatoriaAumento(int n);
int main(){
    printf("Ingrese un valor para ver la sumatoria desde 1 al numero dado, el numero debe ser natural: ");
    scanf("%d", &num);
    printf("Sumatoria con aumento: %d \n", SumatoriaAumento(num));
}
int SumatoriaAumento(int n){
    if (n==1){
        return 1;
    }else {
        return n + SumatoriaAumento(n-1);
    }

}
