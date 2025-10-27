
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para atoi (convertir string a int)

// --- Constantes y Arreglos Globales ---
#define MAX_STRS 100 // Máximo de cadenas en un lenguaje
#define MAX_LEN 50   // Máximo largo de una cadena

// Arreglos para guardar los resultados de las operaciones
char L_union[MAX_STRS][MAX_LEN];
int n_union = 0;

char L_concat[MAX_STRS][MAX_LEN];
int n_concat = 0;

char L_positiva[MAX_STRS][MAX_LEN];
int n_positiva = 0;

char L_kleene[MAX_STRS][MAX_LEN];
int n_kleene = 0;

// --- Funciones Auxiliares (Deben ir ANTES de main) ---

// Verifica si una cadena 'str' ya existe en el lenguaje 'L'
int esta_en(char* str, char L[][MAX_LEN], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(str, L[i]) == 0) {
            return 1; // 1 = Verdadero (sí está)
        }
    }
    return 0; // 0 = Falso (no está)
}

// Agrega 'str' al lenguaje 'L' SOLO si no está ya.
int agregar_si_no_esta(char* str, char L[][MAX_LEN], int n_actual) {
    if (!esta_en(str, L, n_actual)) {
        if (n_actual < MAX_STRS) {
            strcpy(L[n_actual], str);
            return n_actual + 1; // Incrementa el tamaño
        } else {
            printf("Error: Lenguaje resultado demasiado grande.\n");
        }
    }
    return n_actual; // No se agregó, tamaño igual
}

// Imprime un lenguaje
void imprimir_lenguaje(char L[][MAX_LEN], int n, char* nombre) {
    printf("%s = { ", nombre);
    if (n == 0) {
        printf("(vacio) ");
    }
    for (int i = 0; i < n; i++) {
        printf("\"%s\" ", L[i]);
    }
    printf("}\n");
}

// --- Punto de entrada del programa ---
int main() {
    printf("--- Tarea 5: Operaciones de Lenguajes ---\n");

    // --- Lenguajes de entrada (fijos) ---
    char L1[MAX_STRS][MAX_LEN] = {"a", "ab", "b"};
    int n1 = 3;
    char L2[MAX_STRS][MAX_LEN] = {"b", "ba"};
    int n2 = 2;

    imprimir_lenguaje(L1, n1, "L1");
    imprimir_lenguaje(L2, n2, "L2");

    // --- 1. Unión (L1 U L2) ---
    n_union = 0;
    for (int i = 0; i < n1; i++) {
        n_union = agregar_si_no_esta(L1[i], L_union, n_union);
    }
    for (int i = 0; i < n2; i++) {
        n_union = agregar_si_no_esta(L2[i], L_union, n_union);
    }
    imprimir_lenguaje(L_union, n_union, "Union (L1 U L2)");
    printf("----------------------------------\n");

    // --- 2. Concatenación (L1 L2) ---
    n_concat = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            char temp_concat[MAX_LEN];
            strcpy(temp_concat, L1[i]);
            strcat(temp_concat, L2[j]);
            n_concat = agregar_si_no_esta(temp_concat, L_concat, n_concat);
        }
    }
    imprimir_lenguaje(L_concat, n_concat, "Concatenacion (L1 L2)");
    printf("----------------------------------\n");

    // --- 3. Cerraduras (Positiva + y Kleene *) ---
    char L_base[MAX_STRS][MAX_LEN] = {"a", "b"};
    int n_base = 2;
    char k_input[10];
    int k_limite;

    printf("Para cerraduras, usaremos L_base = {\"a\", \"b\"}\n");
    printf("Introduce un limite (k) para las cerraduras (default 3): ");
    
    fgets(k_input, 10, stdin); 
    k_input[strcspn(k_input, "\n")] = 0; 

    if (strlen(k_input) == 0) {
        k_limite = 3;
        printf("Usando default k=3\n");
    } else {
        k_limite = atoi(k_input); 
        if(k_limite <= 0 || k_limite > 5) {
             printf("Valor invalido o muy grande, usando k=3\n");
             k_limite = 3;
        } else {
             printf("Usando k=%d\n", k_limite);
        }
    }
    
    // L+ = L^1 U L^2 U ... U L^k
    n_positiva = 0;
    char L_potencia_ant[MAX_STRS][MAX_LEN];
    int n_potencia_ant = 0;

    for(int i=0; i<n_base; i++) {
        n_potencia_ant = agregar_si_no_esta(L_base[i], L_potencia_ant, n_potencia_ant);
    }

    for (int k = 1; k <= k_limite; k++) {
        for(int i=0; i<n_potencia_ant; i++) {
            n_positiva = agregar_si_no_esta(L_potencia_ant[i], L_positiva, n_positiva);
        }
        
        char L_potencia_nueva[MAX_STRS][MAX_LEN];
        int n_potencia_nueva = 0;
        
        for (int i = 0; i < n_potencia_ant; i++) {
            for (int j = 0; j < n_base; j++) {
                char temp_concat[MAX_LEN];
                strcpy(temp_concat, L_potencia_ant[i]);
                strcat(temp_concat, L_base[j]);
                n_potencia_nueva = agregar_si_no_esta(temp_concat, L_potencia_nueva, n_potencia_nueva);
            }
        }
        
        n_potencia_ant = n_potencia_nueva;
        for(int i=0; i < n_potencia_ant; i++) {
             strcpy(L_potencia_ant[i], L_potencia_nueva[i]);
        }
    }
    imprimir_lenguaje(L_positiva, n_positiva, "Cerradura Positiva (L+)");

    // L* = L+ U L^0 (L^0 = {epsilon})
    n_kleene = 0;
    // Agregamos epsilon (usamos "e" o "" para representarlo, "e" es más visible)
    n_kleene = agregar_si_no_esta("e", L_kleene, n_kleene); 
    for(int i=0; i<n_positiva; i++) {
        n_kleene = agregar_si_no_esta(L_positiva[i], L_kleene, n_kleene);
    }
    imprimir_lenguaje(L_kleene, n_kleene, "Cerradura de Kleene (L*)");
    printf("\n");

    return 0; // Fin del programa
}