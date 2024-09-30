# Deteccion de rostros en una imagen

## Descripcion
Este proyecto procesa una imagen usando opencv para luego con un modelo preentrenado detecte rostros en una imagen y luego guarda cada rostros individual en una imagen propia.

## Estructura Del Proyecto
- `faceDetection.cpp`: Archivo principal con toda la funcionalidad del proyecto.
- `Makefile`: Reglas de compilacion.
- `haarcascade_frontalface_default.xml`: Modelo preentrenado para detectar los rostros .
- `croppedFaces`: Carpeta donde se guardaran los rostros individuales. Si no esta crearla.


## Dependencias del proyecto
- Compilador de C++ con soporte para C++17
- opencv4
- OpenMP

## Instalacion

### Compilacion
```
make
```

## Uso
```
./programa_jpeg <archivo_entrada> 
```
A veces por permisos es necesario ejecutarlo con sudo o version respectiva para que muestre la imagen completa con un cuadro verde en cada rostros

```
make clean
```
Comando para borrar el ejecutable y las imagenes de rostros individuales de la carpeta "croppedFaces"

```
make cleanfaces
```
Comando para borrar solo las imagenes de rostros individuales de la carpeta "croppedFaces"

## Paralelizacion
- se utiliza OpenMP para paralelizar el proceso de crear la imagen de cada rostro y guardarla