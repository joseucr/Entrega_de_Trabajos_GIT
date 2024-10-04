#include <stdio.h>

// Funcion que calcula el factorial de un numero
// La funcion llamada factorial recibe n como argumento
int factorial(int n) {
    // Declara la variable i y la inicializa en 1
    int i = 1;
    // Bucle para el calculo de cualquier numero mayor a uno
    // La formula es n! = 1 * 2 * 3 * ... * n
    while (n > 1) {
        // Multiplica el numero anterior que para numeros mayores que uno siempre es uno
        i = i * n;
        // Calcula el numero anterior al que se tenia
        n = n - 1; // Corrección: se eliminó la redeclaración de n
    }
    return i;
}

// Funcion principal
int main(int argc, char *argv[]) {
    // Declaro la variable que contiene el numero y la variable que va a contener el resultado
    int numeroFactorial, resultado;
    
    // Solicita al usuario que ingrese un numero
    printf("Ingrese el numero al cual desea calcular el factorial: ");
    scanf("%d", &numeroFactorial); // Corrección: se agregó & para pasar la dirección de memoria
    
    // Llama a la funcion y retorna el factorial del numero
    resultado = factorial(numeroFactorial); // Corrección: se eliminó la redeclaración de resultado
    printf("Factorial de %d es %d! = %d\n", numeroFactorial, numeroFactorial, resultado);
    
    // Informa que el programa se ejecuto correctamente
    return 0;
}
