#ifndef ENIGMA_H
#define ENIGMA_H
#include <string>
using namespace std;

string limpiarMensaje(string mensaje);
string agruparEnBloques(string texto);
string cifrarMensaje(string mensaje);
string descifrarMensaje();
void editarRotores();

#endif