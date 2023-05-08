/*
Trabajo final de Programación en C++ I
Profesor: Felipe Grijalva
Nombres: Danny Córdova/Brandom Mosquera/Cristina Proaño/ Marco Calderon
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Lee n cadenas tipo polinomio y  quita los espacios
    tPolinomio polinomio;
    string cadena;
    string cadena_valida;
    int n; // Numero de polinomios introducidos 
    int num_pol; // Numero de repeticiones para ingresar el polinomio

    cout << "Ingrese la cantidad de polinomios: ";
    cin >> num_pol;
    cin.ignore(); // Ignoramos el salto de línea que queda en el buffer

    for (int j = 0; j < num_pol; j++) {
        cout << "Ingrese el polinomio " << j + 1 << ": ";
        getline(cin, cadena);

    const char* ptr = cadena.c_str();
    for (int i = 0; i < cadena.length(); i++) {
        if (*ptr != ' ') { // Si el caracter actual no es un espacio, lo copiamos a la nueva cadena
            cadena_valida += *ptr;
        }
        ptr++; // Avanzamos al siguiente caracter

    }
    cout << "El polinomio sin espacios: " << cadena_valida << endl;
    cadena_valida= "";

	}
    return 0;
}
