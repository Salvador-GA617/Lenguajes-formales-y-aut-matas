
#include <stdio.h>
#include <string.h>

/*
 * Función para calcular la inversa de una cadena.
 * Escribe el resultado en el puntero 'resultado'.
 * Esta función DEBE ir ANTES de main() para que main() la conozca.
 */
void inversa_cadena(char* original, char* resultado) {
    int len = strlen(original);
    int i;
    for (i = 0; i < len; i++) {
        // Copia desde el final del original al inicio del resultado
        resultado[i] = original[len - 1 - i];
    }
    // ¡Muy importante! Añadir el terminador nulo al final
    resultado[len] = '\0';
}

// Punto de entrada del programa
int main() {
    printf("--- Tarea 4: Inversa de Lenguaje ---\n");

    // --- 1. Inversa de una cadena ---
    char cadena_orig[] = "10110";
    char cadena_inv[50]; // Buffer para guardar el resultado

    inversa_cadena(cadena_orig, cadena_inv);
    printf("Cadena original:   %s\n", cadena_orig);
    printf("Inversa de cadena: %s\n", cadena_inv);

    printf("----------------------------------\n");

    // --- 2. Inversa de un Lenguaje (finito) ---
    // Representamos el lenguaje como un arreglo de punteros a cadenas
    char* L[] = {"01", "110", "1000", "0"};
    // Calculamos cuántas cadenas hay en el lenguaje
    int n = sizeof(L) / sizeof(L[0]);

    printf("Lenguaje original L = { ");
    for (int i = 0; i < n; i++) {
        printf("\"%s\" ", L[i]);
    }
    printf("}\n");

    printf("Lenguaje inverso L^R = { ");
    for (int i = 0; i < n; i++) {
        char buffer_inverso[50];
        inversa_cadena(L[i], buffer_inverso);
        printf("\"%s\" ", buffer_inverso);
    }
    printf("}\n\n");

    return 0; // Fin del programa
}