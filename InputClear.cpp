#include "InputClear.h"
#include <iostream>
#include <limits>


using namespace std;

int InputClear::leerInt(const char* mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

      
        cout << "Entrada invalida. Debe ingresar un numero." << endl;
   

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int InputClear::leerIntEnRango(const char* mensaje, int min, int max) {
    while (true) {
        int valor = leerInt(mensaje);
        if (valor >= min && valor <= max) return valor;

       
        cout << "El valor debe estar entre " << min << " y " << max << endl;
      
    }
}

float InputClear::leerFloat(const char* mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        
        cout << "Entrada invalida. Debe ingresar un numero decimal." << endl;
       

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char InputClear::leerChar(const char* mensaje) {
    char c;
    while (true) {
        cout << mensaje;
        cin >> c;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return c;
        }

        cout << "Entrada invalida. Debe ingresar un solo caracter." << endl;
      

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char InputClear::leerCharOpciones(const char* mensaje, const char* opciones) {
    while (true) {
        char c = leerChar(mensaje);

        for (int i = 0; opciones[i] != '\0'; i++) {
            if (c == opciones[i]) return c;
        }
        cout << "Caracter invalido. Opciones validas: " << opciones << endl;
    }
}

        
        

string InputClear::leerString(const char* mensaje) {
    string s;

    while (true) {
        cout << mensaje;
        cin >> s;

        if (!cin.fail())
            return s;

      
        cout << "Entrada invalida." << endl;
        

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string InputClear::leerLinea(const char* mensaje) {
    string s;

    cout << mensaje;
    getline(cin, s);

    while (s.size() == 0) {
        cout << mensaje;
        getline(cin, s);
    }

    return s;
}

bool InputClear::confirmar(const char* mensaje) {
    char c = leerCharOpciones(mensaje, "sSnN");
    return (c == 's' || c == 'S');
}




