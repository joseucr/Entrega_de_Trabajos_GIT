// Laboratorio 3, Ejercicio 3, Hecho por José Armando León, B94249
// Este programa calcula la secuencia de 1s más larga dentro de una matriz cuadrada
// la cual utiliza una matriz ya definida o una con números aleatorios, el tamaño
// de la matriz está definido por un macro

// Librería para usar printf y scanf
#include <stdio.h>
// Librerías para generar números aleatorios
#include <stdlib.h>
#include <time.h>

// Macro para el tamaño de la matriz
#define SIZE 10

// Función que encuentra la sucesión de números 1 más grande
int findLargestLine(int matriz[][SIZE]) {
    
    // Contador de 1s
    int contador = 0;
    // Variable que guarda la sucesión más grande
    int sucesionMaxima = 0;
    // Variable que guarda el tamaño de la sucesión del momento
    int sucesionActual = 0;
    
    // Recorre la matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            
            // Caso en el que encuentre un 1
            if (matriz[i][j] == 1) {
                // Actualiza el contador con el uno que se encontró
                contador++;
                // Actualiza la sucesión actual con el número de unos contados
                sucesionActual = contador;
                // Compara la sucesión actual con la máxima y si la actual es más grande la guarda en la máxima
                if (sucesionActual > sucesionMaxima) {
                    // Guarda la sucesión más grande registrada
                    sucesionMaxima = sucesionActual;
                }
                
            }
            
            // Caso en que encuentra un 0
            else if (matriz[i][j] == 0) {
                // Reinicia el contador de 1s
                contador = 0;
                // Reinicia la sucesión actual
                sucesionActual = 0;
            }
        }
    }
    return sucesionMaxima;
}

// Función principal
int main() {
    
    // Declara la variable para el menú de opciones 
    int eleccion;
    
    // Indica al usuario qué hace el programa y cómo utilizarlo
    printf("Este programa cuenta la sucesión de unos más grande de una matriz binaria cuadrada de tamaño: %dx%d, el cual es definido por el macro SIZE.\n", SIZE, SIZE);
    printf("Si desea utilizar una matriz ya definida ingrese 1 y si desea generar una matriz de números aleatorios ingrese 2: ");
    scanf("%i", &eleccion);
    
    // Opción 1: utiliza matriz predefinida
    if (eleccion == 1) {
        
        // Declara una matriz de números binarios
        int matrix[SIZE][SIZE] = {
            { 0, 1, 1, 1, 0 },
            { 0, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 0 },
            { 0, 1, 1, 0, 1 },
            { 1, 0, 1, 0, 1 }
        };
        
        // Imprime la matriz
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n"); // Añadido para mejorar la legibilidad
        }
        
        // Declara la variable que almacena la secuencia, la cual toma el valor del retorno de la función
        int largestLine = findLargestLine(matrix);
    
        // Informa cuál es la secuencia más grande
        printf("El tamaño de la secuencia de 1s más grande es de: %d\n", largestLine);
    }   
    
    // Opción 2: genera una matriz aleatoria
    else if (eleccion == 2) {
        
        // Declara una matriz
        int matrix[SIZE][SIZE];
        
        // Rellena la matriz aleatoriamente
        // Inicializa el generador de números aleatorios
        srand(time(NULL));
        
        // Recorre la matriz
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Carga la matriz con números binarios
                matrix[i][j] = rand() % 2;
            }
        }
        
        printf("Esta es la matriz que se generó aleatoriamente:\n");
        
        // Imprime la matriz
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        
        // Declara la variable que almacena la secuencia, la cual toma el valor del retorno de la función
        int largestLine = findLargestLine(matrix);
        
        // Informa cuál es la secuencia más grande
        printf("El tamaño de la secuencia de 1s más grande es de: %d\n", largestLine);
    }
    
    // Informa que el programa se ejecutó correctamente
    return 0; 
}
