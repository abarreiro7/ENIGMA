#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <fstream>
using namespace std;

struct Rotor {
    string letras;
    char notch;
    int posicion;
};

void cargarRotor(Rotor r, string nombreArchivo);
char pasarPorRotor(char letra, Rotor r);
char pasarPorRotorInverso(char letra, Rotor r);

#endif