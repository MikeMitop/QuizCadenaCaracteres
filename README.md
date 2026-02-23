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


