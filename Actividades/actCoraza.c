#include <stdio.h>

int main (){
    int n = 4; //Filas
    int m = 4; //Columnas
    int matriz[n][m];
    
//Ingresar los valores de la matriz
printf ("Ingrese los valores de la matriz %dx%d :\n", n , m);
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf ("%d", &matriz[i][j]);
        }
 
 }
 
//Calcular las sumatorias de las matrices 
int sumaLimites = 0;
for (int i= 0; i < n; i++){
  for (int j = 0; j < m; j++) {
    if (i==0 && i==n-1 && j==0 && j==m-1){
    sumaLimites += matriz[i][j];
    }
  }
}
//Calcular la sumatorias de la celda del interior
int sumaInterior = 0;
  for (int i= 1; i < n - 1; i++){
    for (int j = 1; j < m - 1; j++) {  
      sumaInterior += matriz[i][j];
    }
}

//Comparar los valores de las sumatorias
if (sumaLimites == sumaInterior) {
    printf ("La sumatoria de las celdas limites es igual que las sumatoria de las celdas interiores\n");
  }else {
    printf ("La sumatoria de las celdas limites es distinta que las sumatoria de las celdas interiores\n");
  }
return 0;
}