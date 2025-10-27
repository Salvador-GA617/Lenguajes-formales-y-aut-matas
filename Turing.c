
#include <stdio.h>
#include <string.h>

#define MAX_CINTA 100

int main() {
    char cinta[MAX_CINTA];
    int cabezal = 0;
    
    
    char estado = '0'; // Representamos q0 como '0'

    
    printf("--- Tarea 3: MT Complemento Binario ---\n");
    printf("Introduce una cadena binaria ");
    scanf( cinta);

    printf("Iniciando simulacion...\n");
    printf("Cinta inicial: %s\n", cinta);
    printf("Estado: q%c, Cabezal en pos %d, Leyendo: %c\n", 
           estado, cabezal, cinta[cabezal]);

    while (estado != 'H') { // 'H' es el estado de Hal_ (parada)
        
        char simbolo_actual = cinta[cabezal];
        char simbolo_escrito = simbolo_actual;
        char movimiento = 'D'; // 'D' = Derecha

        // Función de Transición
        if (estado == '0' && simbolo_actual == '0') {
            simbolo_escrito = '1';
            estado = '0';
            movimiento = 'D';
        }
       
        else if (estado == '0' && simbolo_actual == '1') {
            simbolo_escrito = '0';
            estado = '0';
            movimiento = 'D';
        }
       
        else if (estado == '0' && simbolo_actual == '\0') {
            
            simbolo_escrito = '\0';
            estado = 'H'; // Parar
            movimiento = 'N'; // No mover
        }
        

        
        cinta[cabezal] = simbolo_escrito;
        
        if (movimiento == 'D') {
            cabezal++;
        }
        
        if (estado != 'H') {
             printf("Estado: q%c, Cabezal en pos %d, Leyendo: %c\n", 
                    estado, cabezal, cinta[cabezal] ? cinta[cabezal] : 'B');
        }
    }

    printf("Simulacion terminada.\n");
    printf("Cadena complementada: %s\n\n", cinta);

    return 0; // Fin del programa
}