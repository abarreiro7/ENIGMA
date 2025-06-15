#include "rotor.h"
#include <fstream>
#include <iostream>

void cargarRotor(Rotor r, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    getline(archivo, r.letras);

    if (archivo.peek() != EOF) {
        archivo >> r.notch;
    }
    else {
        r.notch = 'Z';
    }

    r.posicion = 0;
}

char pasarPorRotor(char letra, Rotor r) {
    int pos = (letra - 'A' + r.posicion) % 26;
    return r.letras[pos];
}

char pasarPorRotorInverso(char letra, Rotor r) {
    size_t pos = r.letras.find(letra);
    return 'A' + (pos - r.posicion + 26) % 26;
}