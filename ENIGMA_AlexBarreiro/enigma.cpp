#include "enigma.h"
#include "rotor.h"
#include <iostream>
#include <fstream>
#include <algorithm>

string limpiarMensaje(string mensaje) {
    string limpio;
    for (char c : mensaje) {
        if (isalpha(c)) {
            limpio += toupper(c);
        }
    }
    return limpio;
}

string agruparEnBloques(string texto) {
    string resultado;
    for (int i = 0; i < texto.size(); i++) {
        if (i > 0 && i % 5 == 0) {
            resultado += " ";
        }
        resultado += texto[i];
    }
    return resultado;
}

string cifrarMensaje(string mensaje) {
    mensaje = limpiarMensaje(mensaje);
    Rotor rotores[3];
    cargarRotor(rotores[0], "Rotor1.txt");
    cargarRotor(rotores[1], "Rotor2.txt");
    cargarRotor(rotores[2], "Rotor3.txt");
    cout << "Posición inicial: ";
    string posiciones;
    cin.ignore();
    getline(cin, posiciones);
    rotores[0].posicion = posiciones[0] - 'A';
    rotores[1].posicion = posiciones[2] - 'A';
    rotores[2].posicion = posiciones[4] - 'A';

    string cifrado;
    for (char c : mensaje) {
        rotores[0].posicion = (rotores[0].posicion + 1) % 26;
        if (rotores[0].letras[rotores[0].posicion] == rotores[0].notch) {
            rotores[1].posicion = (rotores[1].posicion + 1) % 26;
        }
        c = pasarPorRotor(c, rotores[0]);
        c = pasarPorRotor(c, rotores[1]);
        c = pasarPorRotor(c, rotores[2]);
        cifrado += c;
    }
    return agruparEnBloques(cifrado);
}

string descifrarMensaje() {
    ifstream archivo("Xifrat.txt");
    string mensaje;
    getline(archivo, mensaje);
    mensaje = limpiarMensaje(mensaje);
    Rotor rotores[3];
    cargarRotor(rotores[0], "Rotor1.txt");
    cargarRotor(rotores[1], "Rotor2.txt");
    cargarRotor(rotores[2], "Rotor3.txt");
    cout << "Posición inicial: ";
    string posiciones;
    cin.ignore();
    getline(cin, posiciones);
    rotores[0].posicion = posiciones[0] - 'A';
    rotores[1].posicion = posiciones[2] - 'A';
    rotores[2].posicion = posiciones[4] - 'A';

    string descifrado;
    for (char c : mensaje) {
        rotores[0].posicion = (rotores[0].posicion + 1) % 26;
        if (rotores[0].letras[rotores[0].posicion] == rotores[0].notch) {
            rotores[1].posicion = (rotores[1].posicion + 1) % 26;
        }
        c = pasarPorRotorInverso(c, rotores[2]);
        c = pasarPorRotorInverso(c, rotores[1]);
        c = pasarPorRotorInverso(c, rotores[0]);
        descifrado += c;
    }
    return descifrado;
}

void editarRotores() {
    cout << "Que rotor editar?: ";
    int num;
    cin >> num;
    cout << "Nuevas letras: ";
    string letras;
    cin >> letras;
    cout << "Letra notch: ";
    char notch;
    cin.ignore();
    notch = cin.get();
    if (notch == '\n') {
        notch = 'Z';
    }
    ofstream archivo("Rotor" + to_string(num) + ".txt");
    archivo << letras << endl << notch;
    cout << "¡Rotor guardado!" << endl;
}