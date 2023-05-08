/*
Trabajo final de Programación en C++ I
Profesor: Felipe Grijalva
Nombres: Danny Córdova/Brandom Mosquera/Cristina Proaño/ Marco Calderon
*/

#include <iostream>
<<<<<<< HEAD
#include <algorithm>
#include <sstream>
||||||| 2e92bfb
=======
#include <sstream>
>>>>>>> 7f5824c2b235a7888f9952d8d276f70d60ad4741
#include <vector>
<<<<<<< HEAD
#include <cstring>
#include <map>
||||||| 2e92bfb

=======
#include <cstring>
>>>>>>> 7f5824c2b235a7888f9952d8d276f70d60ad4741
using namespace std;
<<<<<<< HEAD
 
struct tPolinomio {
    int grado;
    vector<double> coef;
};
	tPolinomio polinomio;
    string cadena;
    string cadena_valida;
    int n; // Numero de polinomios introducidos 
    int num_pol; // Numero de repeticiones para ingresar el polinomio
    
int main() 
{
       
    /*Lee n cadenas tipo polinomio y  quita los espacios*/

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
        
        /*Ordenar el polinomio*/
        
        stringstream ss(cadena_valida);
        string pol;
	
	}

	
||||||| 2e92bfb

int main()
{
=======

// Lee n cadenas tipo polinomio y  quita los espacios
 
struct tPolinomio {
    double grado;
    vector<double> coef;
};
	tPolinomio polinomio;
    string cadena;
    string cadena_valida;
    int n; // Numero de polinomios introducidos 
    int num_pol; // Numero de repeticiones para ingresar el polinomio
    
int main() {
       
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

	
>>>>>>> 7f5824c2b235a7888f9952d8d276f70d60ad4741
    return 0;
}