#!/bin/bash

# Solicitar apellidos y nombres
read -p "Ingrese el apellido de la primera persona: " apellido1
read -p "Ingrese el apellido de la segunda persona: " apellido2
read -p "Ingrese el nombre de la primera persona: " nombre1
read -p "Ingrese el nombre de la segunda persona: " nombre2

# Construir el nombre de la carpeta y archivo comprimido
FOLDER_NAME="${apellido1}${nombre1}${apellido2}${nombre2}_Taller1_ParteB"
ZIP_FILE="${FOLDER_NAME}.zip"

# Extraer el archivo comprimido
unzip "$ZIP_FILE"
cd "$FOLDER_NAME"

# Compilar los archivos
make all

# Ejecutar el programa y capturar la salida
PROGRAM_OUTPUT=$(./output)

# Resultado esperado con espacios
EXPECTED_OUTPUT="03:03 28:30 12:25 09:25"

# Limpiar la salida generada y esperada eliminando saltos de línea y espacios adicionales
CLEANED_PROGRAM_OUTPUT=$(echo "$PROGRAM_OUTPUT" | tr -d '\n ')
CLEANED_EXPECTED_OUTPUT=$(echo "$EXPECTED_OUTPUT" | tr -d ' ')

# Comparar la salida
if [ "$CLEANED_PROGRAM_OUTPUT" = "$CLEANED_EXPECTED_OUTPUT" ]; then
    echo "¡Ejercicio resuelto correctamente!"
else
    echo "El ejercicio no produce la salida esperada."
    echo "Salida esperada: '$CLEANED_EXPECTED_OUTPUT'"
    echo "Salida generada: '$CLEANED_PROGRAM_OUTPUT'"
fi

# Limpiar archivos generados
make clean

# Volver a la carpeta anterior
cd ..

# Eliminar la carpeta generada
rm -rf "$FOLDER_NAME"
