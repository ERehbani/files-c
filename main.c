#include <stdio.h>
#include <stdlib.h>

const int max = 30;

typedef struct
{
    int legajo;

    //NO USAR CONSTANTES EN LAS ESTRUCTURAS 
    char nombreYapellido[30];
    int edad;
    int anio;
} Alumno;

int recuentoDeDatos(FILE* archivo, int registro);
void mostrarArchivo(FILE* archivo) ;
void ingresarDato(FILE* archivo);
int cargarAlumnos(FILE* archivo, Alumno alumno[]);
void mostrarAlumnos(FILE* archivo, Alumno alumno[], int validos);

int main(void)
{

    FILE* archivo;
    int registro = 0;
    Alumno alumno[max];
    int validos;

    int ejercicio;
    char seguir = 's';

    while(seguir == 's')
    {
        printf("Ingrese ejercicio a ejecutar: ");
        fflush(stdin);
        scanf(" %i", &ejercicio);

        switch(ejercicio)
        {
        case 1:
            ingresarDato(&archivo);
            break;
        case 2:
            mostrarArchivo(&archivo);
            break;
        case 3:
            registro = recuentoDeDatos(&archivo, registro);
            printf("\nEl archivo cuenta con %i datos", registro);
        case 4:
            validos = cargarAlumnos(&archivo, alumno);
            mostrarAlumnos(&archivo, alumno, validos);
        }

        printf("\nDeseas continuar ejecutando?: (s/n): ");
        scanf(" %c", &seguir);
    }
    return 0;
}


void ingresarDato(FILE* archivo)
{
    int num;

    char seguir = 's';

    archivo = fopen("datos", "ab");
    if (archivo != NULL)
    {
        while (seguir == 's' || seguir == 'S')
        {
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


void mostrarArchivo(FILE* archivo)
{
    int num;
    int i = 1;

    archivo = fopen("datos", "rb");

    if(archivo != NULL)
    {
        while(!feof(archivo))
        {
            fread(&num, sizeof(int), 1, archivo);

            if(!feof(archivo))
            {
                printf("Dato: %i: %i\n", i, num);
                i++;
            }
        }

        fclose(archivo);
    }
}


int recuentoDeDatos(FILE* archivo, int registro)
{
    int num;
    int i = 1;

    archivo = fopen("datos", "rb");

    if(archivo != NULL)
    {
        while(!feof(archivo))
        {
            fread(&num, sizeof(int), 1, archivo);
            if(!feof(archivo))
            {
                i++;
                registro++;
            }
        }
    }
    return registro;
}


int cargarAlumnos(FILE* archivo, Alumno alumno[])
{
    int i = 0;

    archivo = fopen("datos", "ab");

    if(archivo != NULL)
    {

        while(i < 2)
            // CAMBIAR A UNA FUNCION QUE CARGUE UN SOLO ALUMNO.
            // NO USAR ARRAY JIJOOOOOO
        {
            printf("Ingrese el legajo: ");
            fflush(stdin);
            scanf(" %i", &alumno[i].legajo);

            printf("Ingrese el nombre: ");
            fflush(stdin);
            scanf(" %s", &alumno[i].nombreYapellido);

            printf("Ingrese la edad: ");
            fflush(stdin);
            scanf(" %i", &alumno[i].edad);

            printf("Ingrese el anio: ");
            fflush(stdin);
            scanf(" %i", &alumno[i].anio);


            fwrite(&alumno, sizeof(Alumno), 1, archivo);
            i++;
        }

        fclose(archivo);
    }

    return i;
}

void mostrarAlumnos(FILE* archivo, Alumno alumno[], int validos)
{

    int i = 0;
    archivo = fopen("datos", "rb");

    if(archivo != NULL)
    {
        while(!feof(archivo) && i < validos)
        {
            printf("\n-------------------\n");
            printf("Alumno #%i", i + 1);

            printf("\nLegajo: %i", alumno[i].legajo);
            printf("\nNombre: %s", alumno[i].nombreYapellido);
            printf("\nEdad: %i", alumno[i].edad);
            printf("\nAnio: %i", alumno[i].anio);

            i++;
        }

        fclose(archivo);
    }

}
