// Laboratorio 3, Ejerecicio 1, Hecho por Jose Armando Leon _ B94249
// Este programa le permite al usuario crear una matriz de orden n y llenarla con numeros elegidos
// por el o con numeros aleatorios dentro de un rango elegido por el usuario y tambien calcular la
// de las diagonales

// Libreria para usar prinf y scan
#include <stdio.h>
// Librerias para generar numeros aleatorios
#include <stdlib.h>
#include <time.h>
// Libreria para raiz cuadrada
#include <math.h>

// Funcion principal
int main() {
    
    // Declara la variable para el tamaño de la matriz
    int orden;
    
    // Mensaje que explica el funcionamiento del programa al usuario
    printf("Con este programa puedes crear matrices cuadradas de orden nxn de numeros enteros");
    printf(" para luego ser utilizada en calculos como la suma de las diagonales");
    
    // Pedir al usuario el tamaño de la matriz y lee su respuesta
    printf("\nIntroduce el tamaño de la matriz cuadrada: ");
    scanf("%d", &orden);

    // Declarar la matriz
    int matriz[orden][orden];
    
    // Declara la variable con las opciones
    int opciones;
    
    // Le indica las opciones al usuario
    printf("Tienes las siguientes opciones:");
    printf("\n 1. Rellenar la matriz con numeros aleatorios dentro de un rango");
    printf("\n 2. Ingresar los numeros de la matriz\n");
    scanf("%i", &opciones);
    
    // Ciclo que crea el menu de opciones
    // Opcion 1: Rellena la matriz con numeros aleatorios
    if (opciones == 1) {
        
        // Declara la variable para generar un rango maximo para un numero aleatorio
        int rangoMaximo;
        printf("Que numero deseas para tu rango maximos de numeros aleatorios:");
        scanf("%i", &rangoMaximo);
        
        // Inicializa el generador de números aleatorios y asegura que estos no se repitan
        srand(time(NULL));
        
        // Carga la matriz con numeros aleatorios
        // Ciclo for, declara un iterador i y lo inicia en 0, luego mientras i sea menor a el orden de la matriz
        // ejecuta lo que está dentro del ciclo y aumenta el iterador
        for (int i = 0; i < orden; i++) {
            // Realiza la misma acción anterior pero para el iterador j
            for (int j = 0; j < orden; j++) {
                // Carga la matriz con numeros aleatorios
                matriz[i][j] = (rand() % rangoMaximo) + 1;
            }
        }
    }   
    // Opcion 2: El usuario carga los numeros de la matriz
    else if (opciones == 2) {
        
        // Declara las variables utilizadas en el ciclo
        int numeroMatriz, contador = 0;
        
        // Como la matriz es cuadrada, el contador llega al la última posición que es el cuadrado del orden
        while (contador < orden * orden) {
            
            // Ciclo for, declara un iterador i y lo inicia en 0, luego mientras i sea menor a el orden de la matriz
            // ejecuta lo que está dentro del ciclo y aumenta el iterador
            for (int i = 0; i < orden; i++) {
                // Realiza la misma acción anterior pero para el iterador j
                for (int j = 0; j < orden; j++) {
                    
                    // Le  indica al usuario que posicion de la matriz va a llenar
                    printf("Ingrese un numero para la posicion (%i,%i): ", i, j);
                    scanf("%i", &numeroMatriz);
        
                    // Guarda el número ingresado en la posición [i][j]        
                    matriz[i][j] = numeroMatriz;
                    
                    // Aumenta  el contador 
                    contador++;    
                }
            }
        }
    }
    
    // Imprime la matriz
    printf("Matriz cuadrada de tamaño %d:\n", orden);
    // Ciclo for, declara un iterador i y lo inicia en 0, luego mientras i sea menor a el orden de la matriz
    // ejecuta lo que está dentro del ciclo y aumenta el iterador
    for (int i = 0; i < orden; i++) {
        // Realiza la misma acción anterior pero para el iterador j
        for (int j = 0; j < orden; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Calcula la suma de las diagonales
    // Declara la variable qu contiene la suma de ambas diagonales
    int diagonalDerecha = 0, diagonalIzquierda = 0  , sumaTotal;
    
    for (int i = 0; i < orden; i++) {
        // Suma diagonal derecha
        diagonalDerecha += matriz[i][i]; 
        // Suma diagonal izquierda
        diagonalIzquierda += matriz[i][orden - 1 - i]; 
    }
    
    // Operacion para calcular la suma de las diagonales
    sumaTotal = diagonalDerecha + diagonalIzquierda;
    printf("Las suma de las dos diagonales es: %i\n", sumaTotal);
    
    // informa que el programa se ejecuto correctamente
    return 0;
}
