#!/bin/bash
# Autor: José Armando León Solano - B94249
# Curso: Programación Bajo Plataformas Abiertas - IE-0117
# Ejercicio 1 del Laboratorio 2
# Este script en bash recibe como argumento un número correspondiente al ID de un proceso y obtiene 
# información relevante sobre el proceso, incluyendo el nombre del proceso, ID del proceso, Parent process ID, 
# usuario propietario, porcentaje de uso de CPU, consumo de memoria, estado (status), y path del ejecutable.

# Verifica que el usuario ingrese correctamente el ID del proceso
if [ $# -ne 1 ]; then # Compara el numero de parametros esperados con 1
    echo "Ingrese el ID del proceso, ejemplo: $0 id"
fi
   
# Variable que contiene la ID del proceso del que desea optener las información
pid=$1

# Verifica si el proceso con el ID dado existe, con el comando ps -p id, si encuentra un error lo redirecciona e imprime un mensaje
if ! ps -p "$pid" > /dev/null; then
    echo "El proceso con ID $pid no existe."
fi

# Obtiene la información del proceso usando ps, luego se extrae la infomación que se solicita
p_info=$(ps -p "$pid" -o user=,pid=,pcpu=,pmem=,stat=,etime=,comm=,ppid=)
# En caso de que no encuentre ninguna información, genera una cadena de texto vacia y utilizando -z se compara con cero
# y se indica que fallo al optener la información
if [ -z "$p_info" ]; then
    echo "Error, no se pudo obtener la información del proceso."
fi

# Redireciona la información del proceso almacenada en la variable process_info y guarda la información sucesivamente
# creando las variables
read -r p_user p_pid p_cpu p_mem p_stat p_time p_cmd p_ppid <<< "$p_info"

# Obtiene el nombre del proceso
p_name=$(basename "$p_cmd")

# Obtiene el path del ejecutable
exe_path=$(readlink -f /proc/"$pid"/exe 2>/dev/null) # redireciona cualquier mensaje de error y continua con su ejecución
if [ $? -ne 0 ]; then
    exe_path="Desconocido"
fi

# Imprime la información correspondiente del proceso
echo "Nombre del proceso: $p_name"
echo "ID del proceso: $p_pid"
echo "Parent process ID: $p_ppid"
echo "Usuario propietario: $p_user"
echo "Porcentaje de uso de CPU: $p_cpu%"
echo "Consumo de memoria: $p_mem%"
echo "Estado: $p_stat"
echo "Path del ejecutable: $exe_path"

