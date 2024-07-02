# SnakeGame2D
![Portada ](https://github.com/EduardoGar0710/SnakeGame2D/assets/162521123/c4d45d71-dd45-4a8f-8ef5-1c38cdcd49cd)


Este proyecto es un juego con inspiracion en el juegp clasico de "Sanke " utilizando la biblioteca SFML en C++. El juego consiste en controlar una serpiente que ira comiendo manzanas que van apareciendo de manera random en la pantalla y al comerlas aumentara nuestro score por cada una que se haya comido

## Características

- **Mecánicas de Serpiente**: Controla la serpiente con las flechas del techaldo.
- **Manzanas**: Se generaran manzanas de manera aleatoria en el mapa.
- **Avance**: La velocidad se vera aumentada a medida que vamos comiendo manzanas
- **Efectos de Sonido**: Se escuchara un sonido de colicion al ingerir las manzanas.
- **Score**: La puntuacion ira aumentando en medida que comemos manzanas.
- **Condiciones de Victoria y Derrota**: El puntaje aumentara en medida de cuantas manzanas hemos comido pero tambien aumentara la   velocidad de los controles.

![JuegoSnake1](https://github.com/EduardoGar0710/SnakeGame2D/assets/162521123/f32bd90d-f860-4f2c-ae77-6eaff0eb5812)
![Juego snake2](https://github.com/EduardoGar0710/SnakeGame2D/assets/162521123/0dfc8af5-8c71-4d58-9634-3dc2d9e58981)

## Programas Necesarios

### Visual Studio Code
Descargar e instalar Visual Studio Code desde el siguiente [enlace](https://code.visualstudio.com/).

### MSYS2 (Windows)
Instalar MSYS2 usando el siguiente [enlace](https://www.msys2.org/).

Agregar los siguientes directorios al Path de Windows y reiniciar:
- `C:\msys64\mingw64\bin`
- `C:\msys64\usr\bin`

### Github Desktop
Cliente de escritorio para clonar el repositorio, descargar usando el siguiente [enlace](https://desktop.github.com/).

### Git
Para poder realizar commits desde Visual Studio Code es necesario tener instalado Git, descargarlo del siguiente [enlace](https://git-scm.com/).

### Instalar las Siguientes Librerías en la Terminal de MSYS2

1. Instalar las herramientas base de desarrollo y la cadena de herramientas para mingw64:

    ```bash
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
    ```

2. Instalar la biblioteca SFML:

    ```bash
    pacman -S mingw-w64-x86_64-sfml
    ```

3. Instalar la biblioteca Box2D:

    ```bash
    pacman -S mingw-w64-x86_64-box2d
    ```

## Complementos para Visual Studio Code

- **Material Icon Theme**
- **C/C++ Extension Pack**
- **Plant UML**
- **CMake Tools**
- **GitGraph**

## Instalación

1. **Clonar el Repositorio**: Clona este repositorio en tu máquina local.

    ```bash
    git clone https://github.com/EduardoGar0710/SnakeGame2D.git
    ```

2. **Compilar el Proyecto**: Navega al directorio del proyecto y compila el proyecto utilizando tu compilador de C++ preferido. Asegúrate de enlazar las bibliotecas SFML.

    ```bash
    cd SnakeGame2
    g++ -o SnakeGame2 main.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
    ```

## Uso

1. **Ejecutar el Juego**: Ejecuta el binario compilado.

    ```bash
    ./Main o en visual studio make runMain
    ```

2. **Controlar Snake**: Usa las flachas del teclado para controlar a Snake.

3. **Jugabilidad**:
   - Moverse por el mapa.
   - Comer manzanas.
   - Aumenta tu score.
   - Evita que chocar con las paredes

## Estructura del Juego

### Variables y Estructuras

- **Estructura de paredes**: Representa los limites del mapa.
- **Comida**: Representa el alimento para snake y el sumador del score.
- **Serpiente**: Es el elemento movible sobre el mapa.
- **Mapa**: Escenario generado para desarrollo del juego.

### Inicialización

- **Ventana**: Crea una ventana de juego con dimensiones específicas y un límite de fotogramas.
- **Formas**: Inicializa las formas del snake , la comida, las paredes y el mapa.
- **Fuentes y Sonidos**: Carga las fuentes y archivos de sonido necesarios.

### Bucle del Juego

- **Manejo de Eventos**: Captura y maneja los eventos de la ventana.
- **Lógica del Juego**: Actualiza el estado del juego, incluyendo el movimiento del snake, la detección de colisiones y el control del score.
- **Renderizado**: Limpia la ventana, dibuja los elementos del juego y muestra el fotograma actualizado.

## Activos

- **Fuentes**: Asegúrate de que `./assets/fonts/Minecraft.ttf` esté en el directorio correcto.
- **Sonidos**: Asegúrate de que los archivos de sonido `ReboteParedes.wav` estén en el directorio correcto.

## Creado por:

Luis Eduardo Rodriguez Garcia 
Registro: 23110167

## Agradecimientos

Este proyecto fue inspirado por el clásico juego Snake Un agradecimiento especial a la comunidad de SFML por proporcionar una robusta biblioteca multimedia.

## Licencia

Este proyecto está licenciado bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.

---

Siéntete libre de modificar y ampliar este proyecto para agregar más características y mejorar la experiencia de juego. ¡Feliz programación!
