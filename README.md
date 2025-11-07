# InputClear C++
Manejo de Errores Automático: Evita la necesidad de repetir código para manejar cin.fail(), cin.clear(), y cin.ignore() en cada lectura.
InputClear es una sencilla clase estática en C++ diseñada para simplificar y robustecer la lectura de datos (enteros, flotantes, caracteres y cadenas) desde la entrada estándar (cin), manejando de forma automática los errores comunes de stream (como cin.fail(), cin.clear() y el vaciado del buffer con cin.ignore()).

El objetivo principal es encapsular la lógica de validación de entrada, haciendo que el código principal sea más limpio y se concentre únicamente en la lógica del negocio.

Origen
Este proyecto surge como parte de un Trabajo Práctico (TP) de la universidad, con la finalidad de aplicar un patrón de diseño que centralice la gestión de errores de entrada, proporcionando una solución robusta y reusable para futuros proyectos.

Funcionalidad Clave
Manejo de Errores Automático: Evita la necesidad de repetir código para manejar cin.fail(), cin.clear(), y cin.ignore() en cada lectura.

Lectura de Tipos Básicos: Métodos para leer de forma segura int, float, char, std::string.

Validación Específica:

leerIntEnRango: Asegura que el entero esté dentro de un rango [min, max] definido.

leerCharOpciones: Restringe el caracter leído a un conjunto de opciones válidas (ej: 's', 'n').

Confirmación Booleana: confirmar simplifica la pregunta de Sí/No.

Lectura de Líneas Completas: leerLinea para leer una línea completa (incluyendo espacios) con validación de cadena vacía.

Diseño Modificable: La clase es una base que puedes modificar y extender fácilmente para adaptarse a tus necesidades específicas de validación.

Implementación y Uso (Ejemplos)
La clase InputClear está diseñada con métodos static, lo que significa que no necesitas crear una instancia para usarla. Simplemente llama al método directamente.


#include <iostream>
#include "InputClear.h"

int main() {
    // Pide un entero entre 1 y 10. No continúa hasta que la entrada sea válida.
    int edad = InputClear::leerIntEnRango("Ingrese su edad (1-100): ", 1, 100);
    std::cout << "Edad ingresada: " << edad << std::endl;

    return 0;
}

#include <iostream>
#include "InputClear.h"

int main() {
    // Pide un caracter, solo permite 'a', 'b', o 'c'.
    char opcion = InputClear::leerCharOpciones("Seleccione una opcion (a/b/c): ", "abc");
    std::cout << "Opcion seleccionada: " << opcion << std::endl;

    return 0;
}

#include <iostream>
#include "InputClear.h"

int main() {
    // Pide 's' o 'n' (o 'S'/'N') y devuelve true/false.
    bool resultado = InputClear::confirmar("Desea guardar los cambios (s/n)? ");
    
    if (resultado) {
        std::cout << "Cambios guardados." << std::endl;
    } else {
        std::cout << "Cambios descartados." << std::endl;
    }

    return 0;
}

#include <iostream>
#include "InputClear.h"

int main() {
    // Pide un número decimal de forma segura.
    float precio = InputClear::leerFloat("Ingrese el precio: ");
    std::cout << "Precio ingresado: " << precio << std::endl;

    return 0;
}
