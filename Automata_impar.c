
#include <stdio.h>
#include <string.h>

int main() {
    // Estados:
    // 'E' = Estado Par (Inicial)
    // 'O' = Estado Impar (Final)
    char estado = 'E';
    char cadena[100];

    printf("--- Tarea 7: Automata Impar de 'a' ---\n");
    
    // --- 1. Imprimir Función y Tabla de Transición ---
    printf("Definicion del Automata:\n");
    printf("  Q = {E, O}, Sigma = {a, b}, q0 = E, F = {O}\n");
    printf("Funcion de Transicion (delta):\n");
    printf("  delta(E, a) = O\n  delta(E, b) = E\n");
    printf("  delta(O, a) = E\n  delta(O, b) = O\n");
    printf("\nTabla de Transicion:\n");
    printf("  delta  |   a   |   b   \n");
    printf("---------|-------|-------\n");
    printf(" -> E    |   O   |   E   \n");
    printf("  * O    |   E   |   O   \n\n");

    // --- 2. Recibir y validar cadena ---
    printf("Introduce una cadena a validar (con 'a' y 'b'): ");
    scanf("%s", cadena); // Lee una sola palabra

    printf("Procesando: \"%s\"\n", cadena);
    printf("  Estado inicial: %c\n", estado);

    for (int i = 0; i < strlen(cadena); i++) {
        char simbolo = cadena[i];
        char estado_anterior = estado;
        
        if (simbolo == 'a') {
            if (estado == 'E') estado = 'O';
            else estado = 'E';
        } 
        else if (simbolo == 'b') {
            // El estado no cambia con 'b'
        } 
        else {
            printf("  Simbolo '%c' ignorado (no en alfabeto).\n", simbolo);
            continue;
        }
        
        if (estado != estado_anterior) {
             printf("  ...leyo '%c', transicion: %c -> %c\n", 
                    simbolo, estado_anterior, estado);
        }
    }

    printf("Procesamiento terminado. Estado final: %c\n", estado);
    
    if (estado == 'O') {
        printf("Resultado: CADENA ACEPTADA (Estado 'O' es final)\n\n");
    } else {
        printf("Resultado: CADENA RECHAZADA (Estado 'E' no es final)\n\n");
    }

    return 0; // Fin del programa
}