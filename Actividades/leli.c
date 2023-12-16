//leli.c
#include <stdio.h>

//LEXICO
char q;
int esVocal(char c);
int esMayuscula(char c);
int esLetra(char c);
char aMinuscula(char c);

//INICIO
int main(){

printf("Ingrese el caracter: ");
scanf("%c",&q);

if(esLetra(q)){
    if(esVocal(q)){
        printf("ES VOCAL");
    } else{
        printf("ES CONSONANTE");
    } else{
        printf("ES SIMBOLO");
    }
}

}

//FUNCIONES
int esVocal(char c){
char minus; //Léxico local
if (esMayuscula(c)){
 minus = aMinuscula(c);
}
else{
 minus = c;
}
return ((minus == 'a')||minus == 'e') ||
(minus == 'i')||(minus == 'o')||(minus ==
'u'));
}

int esMayuscula(char c){
 return ((c >= 'A') && (c <= 'Z'));
}

char aMinuscula(char c){
return (c + ('a'-'A'));
}

int esLetra(char c){
char minus; //Léxico local
if (esMayuscula(c)){
 minus = aMinuscula(c);
}
else{
 minus = c;
}
return ((a<=minus) && (minus<=z))
}
