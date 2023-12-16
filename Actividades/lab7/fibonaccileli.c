#include <stdio.h>
#include <string.h>
int num;
int Fibonacci(int n);
int main(){
    do {
        printf("Ingrese que número de la serie fibonacci quiere saber: ");
        scanf("%d",&num);
    } while(num <= 0);
    printf("%d \n",Fibonacci(num));
}
int Fibonacci(int n){
    if(n<=1){
        return 1;
    } else{
        return (Fibonacci(n-1) + Fibonacci(n-2));
    }
}
