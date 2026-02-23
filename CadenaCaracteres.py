import sys

def afd_scanner(lexema):
  
    estado = 0
    
    for char in lexema:
        if estado == 0:
            if char.isalpha(): estado = 1
            elif char.isdigit(): estado = 2
            elif char == '+': estado = 3
            else: return False
        
        elif estado == 1: 
            if char.isalnum(): estado = 1
            else: return False
            
        elif estado == 2:
            if char.isdigit(): estado = 2
            else: return False
            
        elif estado == 3: 
            if char == '+': estado = 4
            else: return False 
            
        elif estado == 4: 
            return False
            
    return estado in [1, 2, 3, 4]

def procesar_archivo(nombre_archivo):
    try:
        with open(nombre_archivo, 'r') as f:
            for linea in f:
                palabras = linea.split()
                for p in palabras:
                    resultado = "ACEPTA" if afd_scanner(p) else "NO ACEPTA"
                    print(f"{p}: {resultado}")
    except FileNotFoundError:
        print("Archivo no encontrado.")

if __name__ == "__main__":
    procesar_archivo("archivo.txt")
