
#include <stdio.h>
#include <string.h>


void inversa_cadena(char* original, char* resultado) {
    int len = strlen(original);
    int i;
    for (i = 0; i < len; i++) {
        
        resultado[i] = original[len - 1 - i];
    }
    
    resultado[len] = '\0';
}


int main() {
    printf("Inversa de Lenguaje ");

    
    char cadena_orig[] = "10110";
    char cadena_inv[50];

    inversa_cadena(cadena_orig, cadena_inv);
    printf("Cadena original:   \n", cadena_orig);
    printf("Inversa de cadena: \n", cadena_inv);

    
    
    char* L[] = {"01", "110", "1000", "0"};
    
    int n = sizeof(L) / sizeof(L[0]);

    printf("Lenguaje original L = { ");
    for (int i = 0; i < n; i++) {
        printf(L[i]);
    }
   

    printf("Lenguaje inverso L^R = { ");
    for (int i = 0; i < n; i++) {
        char buffer_inverso[50];
        inversa_cadena(L[i], buffer_inverso);
        printf( buffer_inverso);
    }
 

    return 0; 
}