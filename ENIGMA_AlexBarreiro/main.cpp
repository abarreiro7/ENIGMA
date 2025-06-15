#include <iostream>
#include "enigma.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
    cout << "MAQUINA ENIGMA" << endl;
    while (true) {
        cout << "\n1. Cifrar\n2. Descifrar\n3. Editar rotores\n4. Salir\n\nElige: ";
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            cout << "Mensaje: ";
            string mensaje;
            cin.ignore();
            getline(cin, mensaje);

            string cifrado = cifrarMensaje(mensaje);

            ofstream archivo("Xifrat.txt");
            archivo << cifrado;
            cout << "Mensaje guardado en Xifrat.txt" << endl;
        }
        else if (opcion == 2) {
            string descifrado = descifrarMensaje();
            cout << "Mensaje descifrado: " << descifrado << endl;
        }
        else if (opcion == 3) {
            editarRotores();
        }
        else if (opcion == 4) {
            break;
        }
        else {
            cout << "Opcion no valida" << endl;
        }
    }
    return 0;
}