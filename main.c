#include <stdio.h>
#include <stdlib.h>
void ingresarDato();

int main(void) {

    ingresarDato();
    return 0;
}


void ingresarDato() {
    int num;

    char seguir = 's';
    FILE *archivo;

    archivo = fopen("datos", "ab");
    if (archivo != NULL) {
        while (seguir == 's' || seguir == 'S') {
            printf("Ingrese un numero: ");
            fflush(stdin);
            scanf(" %i", &num);

            fwrite(&num, sizeof(int), 1, archivo);

            printf("Desea seguir?: ");
            fflush(stdin);
            scanf(" %c", &seguir);
        }

        fclose(archivo);
    }
}
