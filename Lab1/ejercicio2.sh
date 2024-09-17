#!/bin/bash

# Hechó por José Armando León - B94249
# Laboratorio 1 del curso de Programacion Bajo Plataformas abiertas
# UCR  IE-0117

# Este script crea y revisa si un usuario y grupo existe en el sistema, en ambos caso genera # un mensaje de informe, ademas agrega al usuario defult y al nuevo usuario al grupo creado, 
# finalmente cambia los permisos de un archivo en especifico para que solo los miembro del 
# grupo creado puedan ejecutarlo.


# Verifica que el usuario ingrese los 2 argumentos esperados
if [ "$#" -ne 2 ]; then # Compara el numero de variables con 2
    echo "Ingrese un usuario y grupo, ejemplo: $0 Juan Estudiantes"
    exit 1 # Código de salida
fi

usuario="$1" # Guarda el nombre del usuario
grupo="$2"   # Guarda el nombre del grupo

# Verifica si el usuario ya existe
if id "$usuario" &>/dev/null; then # Revisa si el usuario ya exister t redirecciona cualquier error a /dev/null
    echo "El usuario '$usuario' ya existe."
else # Si el usuario no existe
    sudo useradd "$usuario" # Crear el usuario con permisos de administrador
    echo "Usuario '$usuario' ha sido creado."
fi

# Verifica si el grupo ya existe
if getent group "$grupo" &>/dev/null; then # Revisa si el grupo ya existe y redirecciona cualquier error a /dev/null
    echo "El grupo '$grupo' ya existe."
else # Si el usuario no existe
    sudo groupadd "$grupo"  # Crear el grupo con permisos de administrador
    echo "Grupo '$grupo' ha sido creado."
fi

# Agrega el usuario default y el nuevo usuario al grupo, a todos los comandos se deben de ejecutar con permisos de administrador
def_usr=$(whoami) # obtiene el usuario actual

# Agregar el usuario por defecto al grupo
sudo usermod -aG "$grupo" "$def_usr"

# Agregar el nuevo usuario al grupo
sudo usermod -aG "$grupo" "$usuario"

# Informa al usuario del resultado de los comandos anteriores
echo "Los usuarios '$usuario' y '$def_usr' fueron agregados al grupo '$grupo'."

# Hace que el grupo sea propietario del archivo
sudo chgrp "$grupo" ejercicio1.sh
# Le da permisos de ejecucíon solo al grupo
sudo chmod 050 ejercicio1.sh
