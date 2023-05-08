#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct tPolinomio{
    int grado;
    vector<double>coef;
};

string esp(string& cadena);
void print_string(vector<string> vect);
void print_coe(vector<double> vect);
int exp(string term);
int signo(string term);
double erasse(string term);
tPolinomio suma_poli(vector<double>pols);

int main(){

    int num_pol; 
    string cadena = ""; //polinomio ingresado por el usuario
    string cadena_valida; //polinomio sin espacios
    string ter="";  //cade término del polinomio que se va guardando en un vector
    char c;

    cout << "Ingrese la cantidad de polinomios:";
    cin >> num_pol;
    cin.ignore(); // Ignoramos el salto de línea que queda en el buffer

    vector<tPolinomio>polinomios;

    for(int j = 0; j < num_pol; j++){
        vector<string>terminos;
        int deg = 0;
        cout << "Ingrese el polinomio " << j + 1 << ": ";
        getline(cin >> ws,cadena); //cin>>ws elimina cualquier espacio en blanco inicial en la entrada antes de la lectura
        cadena_valida=esp(cadena); //Aquí se ejecuta la función esp() que borra los espacios
        cout << "Cadena sin espacios: " << cadena_valida <<endl;
        
        for(size_t k = 0;k<cadena_valida.size();k++){ //Este for almacena los términos de cada polinomio 
           c = cadena_valida[k];
           if(c == '+' or c == '-'){  //Si el programa lee un "+" o un "-" almacena lo que estaba antes de ese signo como un término
               terminos.push_back(ter);
               ter = c;
           }
           else ter = ter + c;
        }
        
        terminos.push_back(ter);
        print_string(terminos);

        //Uso la función exp para ordenar a los coeficientes de cada polinomio según su grado
        for(size_t k = 0; k < terminos.size(); k++){
            int degter = exp(terminos[k]);
            if(deg < degter){
                deg = degter;
            }
        }
        cout << "El grado del polinomio ingresado es " << deg;
        tPolinomio Polte; //Polinomio Temporal
        Polte.grado = deg;

        //Almaceno los coeficientes en un vector de double
        double coeficiente;
        int exx;
        string part;
        vector<double>alcoe; //Almacena coeficientes
        for(int m = 0; m <= deg; m++){
            alcoe.push_back(0);
        };
        for(int h = 0; h < terminos.size(); h++){
            part = terminos[h];
            exx = exp(part);
            coeficiente = erasse(part); //Uso la función erasse() para eliminar signos (+,-,*) y la variable x
            alcoe[exx] = coeficiente;
        }
        Polte.coef=alcoe;

        vector<double>almacen = Polte.coef;
        int grado = Polte.grado;

        cout << "Datos del polinomio cargado: " << endl;
        print_coe(almacen);
        cout << endl << "Grado: " << grado << endl;
        polinomios.push_back(Polte);
        part = "";
    }

    cout << "Polinomios cargados: " << endl;
    for (int l = 0; l < polinomios.size(); l++){
        tPolinomio Polte = polinomios[l];
        vector<double>almacen = Polte.coef;
        int grado = Polte.grado;

        cout << "Datos del polinomio cargado: " << endl;
        print_coe(almacen);
        cout << endl;
    }

    return 0;
}

string esp(string& cadena){

    //Quita espacios en blanco
    string cadena_valida;
    const char* ptr = cadena.c_str();
            for (int i = 0; i < cadena.length(); i++) {
                if (*ptr != ' ') { // Si el caracter actual no es un espacio, lo copiamos a la nueva cadena
                    cadena_valida += *ptr;
                }
            ptr++; // Avanzamos al siguiente caracter
            }
            return cadena_valida;
}

void print_string(vector<string> vect){

    //Imprime un vector de strings
    for (size_t i = 0; i < vect.size(); ++i){
            cout << vect [i] << " ";
    }
}
void print_coe(vector<double> vect){

    //Imprime el vector de double de los coeficientes
    for (size_t i = 0; i < vect.size(); ++i){
            cout << vect [i] << " ";
    }
}

int exp(string term){
    
    //Encuentra los exponentes de cada término
    size_t pos = 0;//La variable recorre el string
    int ex = 0;
    pos = term.find("x"); //term.find() encuentra el caracter x dentro de cada polinomio
    string exponentes = "";

    if(pos!= string::npos){ //string::npos me indica que no se encontró la coincidencia que se busca
        if(pos + 1 == term.size()){
            ex = 1;
        }
        else{
            exponentes = term[pos+1];
            ex = stoi(exponentes); //stoi() es una función que me permite transformar un string a entero, siempre que se pueda
        }
    }
    return ex;
}

int signo(string term){
    
    //Me permite distinguir el signo para luego usarlo en la función erasse()
    int sign = 0;
    string s = "";
    s = term[0];

    if(s == "-"){
        sign = 1;
    }

    return sign;
}

double erasse(string term){

    /*Elimina todo lo que no sean los coeficinetes y los exponentes (borra los signos también, pero se asegura de tomar 
    en cuenta los negativos al momento de almacenar los coeficientes)*/
    if(exp(term) > 1){
        size_t er = term.size() -1;
        term.erase((er),1);
    }

    bool minus = false;
    if (signo(term) == 1){
        minus = true;  //si el bool minus aparece come true, entonces el coeficiente del término es negativo
    }

    size_t place = 0;//Se inicializa la variable posicion que marcará los sitios en que se aplicara el metodo erasse
    place = term.find("+"); //term.find() ya se usó en la función exp, cumple el mismo rol aquí
    while(place!= string::nplace){
        term.erase((place),1); /*term.erase() borra el término indicado, para no confundir con la función creada por nosotros, 
        se la llamó erasse. La función term.erase((pos),1) me indica el caracter a borrar (pos) y cuantos caracteres se tienen 
        que borrar (1) */
        place = term.find("+");
    }
    place = term.find("-");
    while(place!= string::nplace){
        term.erase((pos),1);
        place = term.find("-");
    }
    place = term.find("x");
    while(place!= string::nplace){
        term.erase((place),1);
        place = term.find("x");
    }
    place = term.find("*");
    while(place!= string::nplace){
        term.erase((place),1);
        place = term.find("*");
    }

    if(term == ""){
        term = "1";
    }

    double num = stod(term); //stod() transforma una cadena de string en un double, siempre que sea posible

    if(minus){
        num = num * (-1); //aquí nos aseguramos que los signos negativos sean contados dentro de los coeficientes
    }

    return(num);
}

tPolinomio suma_poli(vector<double>pols){
    
    //Suma los polinomios
    tPolinomio suma;
    return suma;
}