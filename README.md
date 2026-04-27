# Laboratorio: Simulación de Deadlock en Sistemas Operativos

Este proyecto contiene una demostración práctica de un interbloqueo (**Deadlock**) utilizando el bloqueo de archivos en entornos Linux. El objetivo es observar cómo dos procesos pueden quedar en espera mutua e indefinida al intentar acceder a recursos protegidos.

## 🛠 Requisitos Técnicos

* **Lenguaje:** C
* **Sistema Operativo:** Linux (basado en POSIX)
* **Compilador:** GCC
* **Librerías:** `<sys/file.h>` para la gestión de bloqueos con `flock`.

## 📁 Contenido del Repositorio

* `lock1_tarea.c`: Programa que bloquea el archivo `r1.txt` e intenta acceder a `r2.txt`.
* `lock2_tarea.c`: Programa que bloquea el archivo `r2.txt` e intenta acceder a `r1.txt`.

## 🚀 Instrucciones de Ejecución

1. **Preparar el entorno:**
   Cree los archivos de texto necesarios en el directorio raíz:
   ```bash
   touch r1.txt r2.txt
