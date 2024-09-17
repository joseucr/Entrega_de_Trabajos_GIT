#!/bin/bash

# Hechó por José Armando León - B94249
# Laboratorio 1 del curso de Programacion Bajo Plataformas abiertas
# UCR  IE-0117

# Este sript tiene como funcíon recibir una ruta de archivo verificar e
# informar al usuario de su existencia, y mostrar los permisos asociados
# al archivo

# Informa al usuario que no ingresó la ruta del archivo
if [ $# -ne 1 ]; then # Verifica que se ingrese un argumento
	echo "Ingrese la ruta del archivo, ejemplo: $0 /home/user/Documents/file" # Uso 
    	exit 1 # Codigo de salida
fi

# Variable con la ruta del archivo
archivo="$1"

# Varible con el nombre del archivo
file=$(basename "$archivo")

# Verifica si el archivo existe
if [ -e "$archivo" ]; then # Condición para operador if que verifica si un archivo existe
	echo "El archivo "$file" existe."
else # En caso que no exista, se le informa al ususario y se gerenera un codigo de error   
    	echo "El archivo "$file" no existe, errorcode 404"
    	error=404 # Codigo de error
    	exit 2 # Codigo de salida, tambien se puede utlizar como codigo de error
fi

# Variable con los permisos del archivo
permisos=$(stat -c "%A" "$archivo") # A la variable permisos se le asigna la salida del comando stat -c la cual extrae los permisos del archivo


# Función para interpretar y obtener permisos detallados
get_permissions_verbose() {
    local permisos="$1"
	
    # Extraer los caracteres que simbolizan los permisos para usuario, grupo y otros
    local usuario="${permisos:1:3}"
    local grupo="${permisos:4:3}"
    local otros="${permisos:7:3}"

    echo "Permisos del usuario:"
    
    # Utilizando el operador case en se compara el valor de "leido" con los caracters rwx, si el valor es el mismo, se imprime el nombre de permiso, de lo contrario se idica que no tiene el permiso.
    case ${usuario:0:1} in
        r) echo "  - Lectura" ;;
        -) echo "  - Sin lectura" ;;
    esac
    case ${usuario:1:1} in
        w) echo "  - Escritura" ;;
        -) echo "  - Sin escritura" ;;
    esac
    case ${usuario:2:1} in
        x) echo "  - Ejecución" ;;
        -) echo "  - Sin ejecución" ;;
    esac

    echo "Permisos del grupo:"
    case ${grupo:0:1} in
        r) echo "  - Lectura" ;;
        -) echo "  - Sin lectura" ;;
    esac
    case ${grupo:1:1} in
        w) echo "  - Escritura" ;;
        *) echo "  - Sin escritura" ;;
    esac
    case ${grupo:2:1} in
        x) echo "  - Ejecución" ;;
        -) echo "  - Sin ejecución" ;;
    esac

    echo "Permisos de otros:"
    case ${otros:0:1} in
        r) echo "  - Lectura" ;;
        -) echo "  - Sin lectura" ;;
    esac
    case ${otros:1:1} in
        w) echo "  - Escritura" ;;
        -) echo "  - Sin escritura" ;;
    esac
    case ${otros:2:1} in
        x) echo "  - Ejecución" ;;
        -) echo "  - Sin ejecución" ;;
    esac
}

# Llama a la función y se le asigna la variable con los permisos.
get_permissions_verbose "$permisos"
