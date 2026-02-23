# Quiz AFD Cadenas de Caracteres

# CadenaCaracteres — AFD Léxico

Implementación de un **Autómata Finito Determinista (AFD)** en C y Python para
clasificar lexemas como tokens válidos de un lenguaje simple. Lee cadenas desde
un archivo de texto y determina si cada una es **ACEPTA** o **NO ACEPTA**.

## Estructura del Proyecto

```
CadenaCaracteres/
├── AFD.c # Implementación en C
├── AFD.py # Implementación en Python
├── archivo.txt # Archivo de entrada con los lexemas
└── README.md
```


# Tokens Reconocidos


---


| Token          | Patrón                          | Ejemplo         |
|----------------|---------------------------------|-----------------|
| **Id**         | `[A-Za-z]([a-z][0-9])*`        | `a`, `Ab1`, `ab1c2` |
| **Entero**     | `[0-9]+`                        | `123`, `9876543210` |
| **Suma**       | `+`                             | `+`             |
| **Incremento** | `++`                            | `++`            |

---

## Explicación del Algoritmo:

El AFD funciona como una máquina de estados: parte siempre en q0 y con cada carácter leído decide a qué estado moverse. Si en algún momento no hay transición válida, rechaza inmediatamente. Al terminar la cadena, el estado en el que quedó determina si acepta o no.

```c
int estado = 0;   // siempre arranca en q0
int i = 0;        // índice del carácter actual
```

El autómata no tiene memoria del pasado, solo importa el estado actual y el carácter que llega.

Se recorre la cadena carácter a carácter hasta llegar a '\0' (fin de cadena):

```
while (str[i] != '\0') {
    char c = str[i];
    // aplicar función delta(estado, c)
    i++;
}
```

En cada iteración se aplica la función de transición δ(estado, c):

**(estado actual, carácter leído) → nuevo estado**



---

##  Uso

### Python y C
```bash
python AFD.py

gcc AFD.c -o afd
./afd

```

### Formato.TXT

a
Ab1
ab1c2
123
+
++
Usuario2026
1234a
_variable
+++


### Salida Esperada:

a: ACEPTA
Ab1: ACEPTA
ab1c2: ACEPTA
123: ACEPTA
+: ACEPTA
++: ACEPTA
Usuario2026: NO ACEPTA
1234a: NO ACEPTA
_variable: NO ACEPTA
+++: NO ACEPTA


