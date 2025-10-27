
#include <stdio.h>
#include <string.h>

int main() {
    // Estados:
    // 0 = q0 (Inicial)
    // 1 = q1 (Vio /)
    // 2 = q2 (Vio /*, dentro de comentario)
    // 3 = q3 (Vio *, posible fin)
    // 4 = qF (Final, vio */)
    // 99 = qError (Rechazo)
    int estado = 0;
    char cadena[200];
    
    printf("--- Tarea 6: Validador Comentario C (/*...*/) ---\n");
    printf("Introduce una cadena a validar: ");
    
    // Usamos fgets para leer toda la línea, espacios incluidos
    fgets(cadena, 200, stdin);
    // fgets captura el \n (salto de línea), hay que quitarlo
    cadena[strcspn(cadena, "\n")] = 0;

    printf("Procesando: \"%s\"\n", cadena);

    for (int i = 0; i < strlen(cadena); i++) {
        char simbolo = cadena[i];
        int estado_anterior = estado;

        switch (estado) {
            case 0: // q0
                if (simbolo == '/') estado = 1;
                else estado = 99;
                break;
            
            case 1: // q1
                if (simbolo == '*') estado = 2;
                else estado = 99;
                break;
                
            case 2: // q2 (Dentro de comentario)
                if (simbolo == '*') estado = 3;
                // Si es / u otro, se queda en q2
                break;
                
            case 3: // q3 (Vio un *)
                if (simbolo == '/') estado = 4;
                else if (simbolo == '*') ; // Se queda en q3 (ej. /**... )
                else estado = 2; // Falsa alarma, regresa a q2
                break;

            case 4: // qF (Estado final)
                // Si llega algo DESPUÉS de */, es un error
                estado = 99;
                break;
                
            case 99: // qError
                // Si ya está en error, se queda en error
                break;
        }
        
        if (estado != estado_anterior) {
            printf("  Leyo '%c', transicion: q%d -> q%d\n", 
                   simbolo, estado_anterior, estado == 99 ? 99 : estado);
        }
    }
    
    printf("Procesamiento terminado.\n");
    // La cadena es válida SI Y SOLO SI termina en el estado final 4
    if (estado == 4) {
        printf("Resultado: CADENA ACEPTADA\n\n");
    } else {
        printf("Resultado: CADENA RECHAZADA (Estado final fue q%d)\n\n", estado);
    }

    return 0; // Fin del programa
}