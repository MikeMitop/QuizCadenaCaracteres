#include <stdio.h>
#include <ctype.h>
#include <string.h>

int afd(char *str) {
    int estado = 0;
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        char c = str[i];
        switch (estado) {

            case 0:
                if (isalpha((unsigned char)c))       estado = 1;
                else if (isdigit((unsigned char)c))  estado = 2;
                else if (c == '+')                   estado = 3;
                else return 0;
                break;
            case 1:

                if (islower((unsigned char)c))       estado = 5;
                else return 0;
                break;
            case 2:

                if (!isdigit((unsigned char)c)) return 0;
                break;
            case 3:

                if (c == '+') estado = 4;
                else return 0;
                break;
            case 4:

                return 0;
            case 5:

                if (isdigit((unsigned char)c)) estado = 6;
                else return 0;
                break;
            case 6:

                if (islower((unsigned char)c)) estado = 5;
                else return 0;
                break;
        }
        
        i++;
    }
    return (estado == 1 || estado == 6 || estado == 2 || estado == 3 || estado == 4);
}

int main() {
    FILE *archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char palabra[512];
    while (fscanf(archivo, "%511s", palabra) != EOF) {
        if (afd(palabra)) printf("%s: ACEPTA\n", palabra);
        else printf("%s: NO ACEPTA\n", palabra);
    }

    fclose(archivo);
    return 0;
}
