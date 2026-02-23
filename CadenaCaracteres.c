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
                if (isalpha(c)) estado = 1;
                else if (isdigit(c)) estado = 2;
                else if (c == '+') estado = 3;
                else return 0;
                break;
            case 1: // ID
                if (!isalnum(c)) return 0;
                break;
            case 2: // Entero
                if (!isdigit(c)) return 0;
                break;
            case 3: // Suma -> Incremento
                if (c == '+') estado = 4;
                else return 0;
                break;
            case 4: // Final de Incremento
                return 0;
        }
        i++;
    }
    return (estado >= 1 && estado <= 4);
}

int main() {
    FILE *archivo = fopen("archivo.txt", "r");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char palabra[100];
    while (fscanf(archivo, "%s", palabra) != EOF) {
        if (afd(palabra)) printf("%s: ACEPTA\n", palabra);
        else printf("%s: NO ACEPTA\n", palabra);
    }

    fclose(archivo);
    return 0;
}
