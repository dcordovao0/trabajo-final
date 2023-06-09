/*
Trabajo final de Programación en C++ I
Profesor: Felipe Grijalva
Nombres: Danny Córdova/Brandom Mosquera/Cristina Proaño/ Marco Calderón
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>

using namespace std;  

struct tPolinomio{
    int grado;
    vector<double>coef;
};

//Prototipos de funciones, en la parte de abajo se encuentra el funcionamiento de cada una 
bool number_validation(string& num_pol);
string Validacion_cadena(string& num_pol);
bool check_pol(string& cadena);
string esp(string& cadena);
string bye_zero(string& cadena_valida);
void print_string(vector<string>& vect);
void print_coe(vector<double>& vect);
int exp(string& term);
int signo(string& term);
string search_and_destroy(string& term,char& c);
double erasse(string& term);

int main()
{
    string cadena; //polinomio ingresado por el usuario
    string cadena_valida; //polinomio sin espacios
    string ter="";  //cada término del polinomio que se va guardando en un vector
    string num_pol; // Numero de repeticiones para ingresar el polinomio
    char c;
    int intpol;
    int deg_max= 0; //Variable para almacenar el grado maximo
    tPolinomio PolResul ; // Variable que almacena el resultado
    vector<double>alcoe;//Almacena coeficientes
	tPolinomio Polte; //Polinomio Temporal
	vector<double>almacen;//Almacen general 
	vector<tPolinomio>polinomios;//Vector donde se guardan los polinomios

    //Validación si la entrada es un entero
    bool Npolinomio = false;
    cout << "Ingrese la cantidad de polinomios: ";
    getline(cin,num_pol);
    while(Npolinomio == false){
    	if(number_validation(num_pol) == false || number_validation(cadena_valida)==false){
			while(number_validation(num_pol)==false){
        	cout<<"Por favor, ingrese un numero entero. Ingrese la cantidad de polinomios: ";
        	getline(cin,num_pol);
        	Npolinomio == number_validation(num_pol);
    		}
		}
    	if(number_validation(num_pol) == true){
    		cadena_valida=Validacion_cadena(num_pol);
    		Npolinomio = number_validation(cadena_valida);
    		num_pol = cadena_valida;
    		while(number_validation(num_pol)==false){
    			cout<<"Por favor, ingrese un numero entero. Ingrese la cantidad de polinomios: ";
        		getline(cin,num_pol);
			}
		}
	}
    intpol=stoi(cadena_valida);
    
    cout<<endl<<"Para una lectura correcta, los polinomios deben ser ingresados de la forma: a*x^n +b*x^m..."<<endl;

    for(int j = 0; j < intpol; j++){
        vector<double> alcoe;
        vector<double>almacen;
        vector<string>terminos;
        int deg = 0;

        bool ErrorInsertar = 1; //fuerza la entrada al while para cada polinomio
		while(ErrorInsertar == 1)
        { //Verifica que los datos del string sean correctos
			ErrorInsertar = 0;
			cout<<"Polinomio "<<j+1<<": ";
			getline(cin >> ws, cadena);
            ErrorInsertar=check_pol(cadena);
            cadena_valida=esp(cadena); //Aquí se ejecuta la función esp() que borra los espacios  
            for(int i=0;i<cadena_valida.size();i++){
				if(cadena_valida[i]=='x'){
                    if((cadena_valida[i-1]=='*' and cadena_valida[i+1]=='*') or cadena_valida[i+1]=='x'){
                    		ErrorInsertar=1;               
                	}
            	}
                else if (cadena_valida[i]=='+' or cadena_valida[i]=='-'){
                    if(cadena_valida[i+1]=='+'  or cadena_valida[i+1]=='-'){
                    		ErrorInsertar=1;               
                	}
                }
            }
            if(ErrorInsertar == 1)
				cout<<"Inserte correctamente el polinomio, por favor (a*x^n +b*x^m...)."<<endl;  
        }
            
                               	        
            
        if(cadena_valida[0]=='+' or cadena_valida[0]=='-') cadena_valida.insert(0,"0"); /*Inserta un 0 al inicio para evitar errores 
        en la lectura cuando se ingresa un '+' o un '-' al inicio*/  
        else if(cadena_valida[0]=='x') cadena_valida.insert(0,"1");
        else if((cadena_valida[0]=='+' or cadena_valida[0]=='-') and cadena_valida[1]=='x') cadena_valida.insert(0,"0");
        
        cadena_valida=bye_zero(cadena_valida); //Se ejecuta la función bye_zero que elimina los ceros después del punto decimal del exp
        ter = "";
        for(int k = 0;k<cadena_valida.size();k++){ //Este for almacena los términos de cada polinomio 
           c = cadena_valida[k];
           if(c == '+' or c == '-'){  //Si el programa lee un "+" o un "-" almacena lo que estaba antes de ese signo como un término
               terminos.push_back(ter);
               ter = c;
           }
           else ter = ter + c;
        }
         
        terminos.push_back(ter);

        //Uso la función exp para ordenar a los coeficientes de cada polinomio según su grado
        for(int k = 0; k < terminos.size(); k++){
            int degter = exp(terminos[k]);
            if(deg < degter){
                deg = degter;
            }
        }
        if(deg> deg_max ) {
        	deg_max = deg;
		}
        Polte.grado = deg;

        //Almaceno los coeficientes en un vector de double
        double coeficiente;
        int exx;
        string part;
        for(int m = 0; m <= deg_max; m++){
            alcoe.push_back(0);
        };
        for(int h = 0; h < terminos.size(); h++){
            part = terminos[h];
            exx = exp(part);
            coeficiente = erasse(part); //Uso la función erasse() para eliminar signos (+,-,*) y la variable x
            alcoe[exx] = coeficiente;
        }
        Polte.coef=alcoe;
        
        almacen= Polte.coef;
        int grado = Polte.grado;
        polinomios.push_back(Polte);
        part = ""; 

    }
    for(int i=0;i<polinomios.size();i++){
        for(int m =polinomios[i].coef.size() ; m <= deg_max; m++){
            polinomios[i].coef.push_back(0);
        };
    }
    //Empieza la suma 
	PolResul.grado = deg_max;
	cout<<endl<<"El grado de la suma es: "<<deg_max<<endl; // Asigna el grado maximo en la estructura resultante 
	PolResul.coef.push_back(0);
    vector<double>sum(deg_max,0);
    
		
	for (int i=0;i<=deg_max;i++){
		double x = 0;
		for (int j=0;j<polinomios.size();j++){
			x = x + polinomios[j].coef[i];
		}	
		PolResul.coef[i]=x;
	}	
	
	
	// Imprimo los resultados
	cout<<"La suma es: ";
	int contadorGrado=deg_max;
	for (int i=deg_max;i>=0;i--){
	    if (PolResul.coef[i]!=0){
	    	if(i!=0){
	    		if(PolResul.coef[i-1]<0)
	    		cout<<PolResul.coef[i]<<"*x"<<contadorGrado;
	    		else if(PolResul.coef[i-1]>0)
	    		cout<<PolResul.coef[i]<<"*x"<<contadorGrado<<"+";
	    		else if(PolResul.coef[i-1] == 0){
	    			int j = i-1;
	    			while (PolResul.coef[j] == 0){
						j--;
						if(j==-1){
							cout<<PolResul.coef[i]<<"*x"<<contadorGrado;
							break;
						}
					if(PolResul.coef[j]<0){
	    					cout<<PolResul.coef[i]<<"*x"<<contadorGrado;
	    					break;
	    				}
	    				else if(PolResul.coef[j]>0){
	    					cout<<PolResul.coef[i]<<"*x"<<contadorGrado<<"+";	
							break;
						}
					}
				}
			}
			else if(i==0 && PolResul.coef[i]!=0)
				cout<<PolResul.coef[i];
			contadorGrado--;
		}
		else if(PolResul.coef[i]==0){
			contadorGrado--;
		}
	}

    return 0;
}

bool number_validation(string& num_pol){
    
    //Mira si lo ingresado en el número es un número o un punto
    bool is_digit = true;   
	for (char c : num_pol) {
    	if (!isdigit(c) && c!='.') { //is digit reconoce si los char de una cadena de strings son números y no otros símbolos
    		is_digit = false;
     		break;
    	}
	}
    return is_digit;
}

string Validacion_cadena(string& num_pol){
	
    //Mira si el exponente ingresado no es un entero
    string numPolTemp;
	for(int j=0; j<num_pol.length();j++){
		if(num_pol[j]!='.'){
		numPolTemp.push_back(num_pol[j]);
		continue;
		}
		//El if se mueve por la string desde el punto
		else if(num_pol[j]=='.'){
			for(int k=j+1; k<num_pol.length();k++){
				//Si es distinto de 0 lo vuelve un signo
				if(num_pol[k]!='0' ){
					numPolTemp.push_back('&'); //Para que de error en la validacion despues si el numero es fraccionario
					j=num_pol.length(); //para que salga del primero for 
					break; //para que salga del segundo for
				}
				//Si es 0 lo continua
				else{
                	j=k;
					continue;
				}
			}
		}
    }
    return (numPolTemp);
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

bool check_pol(string& cadena){
    
    //Hace validaciones de que lo que se ingrese del polinomio esté correcto
    bool ErrorInsertar = 0;
    for(int k=0; k<cadena.length();k++){
	    //Revisa caracteres que no irian en un polinomio
		if((cadena[k]<'0' || cadena[k]>'9') && (cadena[k]!='x' && cadena[k]!='+' && 
		cadena[k]!='-' && cadena[k]!='*' && cadena[k]!='.' && cadena[k]!=' ')){
			ErrorInsertar = 1;
			break;	
		}
		if(cadena[k]=='*'){
			if(k==cadena.length()-1){
				ErrorInsertar=1;
			}
			else{
				for(int h=k+1; h<cadena.length(); h++){
					if(cadena[h]=='x')				
                        break;
					else if(cadena[h]==' ')
						continue;
					else 
						ErrorInsertar=1;
				}
			}
		}
		//Revisa si el caracter es un numero y es como maximo el penultimo termino ya que se evalua mas adelante el penultimo termino
		//el ultimo termino no afecta en si es un espacio o un numero
		if ((cadena[k]>='0' || cadena[k]<='9') && k<cadena.length()-2){ 
		//Revisa si el siguiente termino es un caracter disntinto de " "
		if((cadena[k+1]>='0' && cadena[k+1]<='9') || cadena[k]=='x' || cadena[k]=='+' || 
		cadena[k]=='-' || cadena[k]=='*' || cadena[k]=='.'){
			continue;
		}
	    //Revisa si el siguiente termino es un " " y no es el ultimo termino ya que no afectaria.
		else if (cadena[k+1]==' ' && (k+1)!=(cadena.length()-1)){
		//Establece k como el termino despues del " "
		for(int h=k+2;k<cadena.length();h++){
		//Mira si k es un caracter disntinto de " " o un numero por lo que seria valido y saldria del for
		    if(cadena[h]=='x' || cadena[h]=='+' || 
			cadena[h]=='-' || cadena[h]=='*' || cadena[h]=='.'){
				break;
			}
	    //Mira si k es un numero lo cual daria un erro y evitar leer Ej. 10   10 = 1010
			else if(cadena[h]>='0' && cadena[h]<='9'){
				ErrorInsertar = 1;
				break;
			}
			//Si k es un espacio continua el for a revisar el proximo termino que no sea un " "
			else if(cadena[h]==' '){
				continue;
							}
			    }
		    }
		}
	}                
    return ErrorInsertar;
}


string bye_zero(string& cadena_valida){
    
    //Elimina los ceros del exponente
    string PolTemp;
		for(int j=0; j<cadena_valida.length();j++){
			//si el char es un disti nto de . lo copia
			if(cadena_valida[j]!='.')
				PolTemp.push_back(cadena_valida[j]);
			//El if mira el punto
			else if(cadena_valida[j]=='.'){
				for(int k=j+1; k<cadena_valida.length();k++){
					//si es 0 se mueve hasta encontrar un numero distinto o acabar el polinomio e igualar j
					if(cadena_valida[k]=='0'){
						while(cadena_valida[k]=='0'){
							if(k==cadena_valida.length()-1){
								j=k;
								break;
							}
							k++;
						}
						if(cadena_valida[k]=='*' || cadena_valida[k]=='+' || cadena_valida[k]=='-' || cadena_valida[k]=='x' ){
							j=k-1;
							break;
						}
						//si encuentra un numero distinto, copia todo lo despues del punto
						else if(cadena_valida[k] > '0' && cadena_valida[k] <='9'){
							PolTemp.push_back(cadena_valida[j]);
							break;
						}
					}
					//si es distinto de 0 el numero despues del punto copia todo lo despues del punto
					else if(cadena_valida[k] >= '0' && cadena_valida[k] <='9'){
							PolTemp.push_back(cadena_valida[j]);
							break;
					}
				}
			}
		}
	cadena_valida = PolTemp; //Copia el polinomio
    return cadena_valida;
}

void print_string(vector<string>& vect){

    //Imprime un vector de strings
    for (size_t i = 0; i < vect.size(); ++i){
            cout << vect [i] << " ";
    }
}
void print_coe(vector<double>& vect){

    //Imprime el vector de double de los coeficientes
    for (size_t i = 0; i < vect.size(); ++i){
            cout << vect [i] << " ";
    }
}

int exp(string& term){
    
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
            pos=pos+1;
            while (pos<term.size()){
                exponentes=exponentes+term[pos];
                pos = pos+1;
            }
            stringstream ss(exponentes); 
            ss>>ex; //esta función que me permite transformar un string a entero, siempre que sea posible
        }
    }

    return ex;
}

int signo(string& term){
    
    //Me permite distinguir el signo para luego usarlo en la función erasse()
    int sign = 0;
    string s = "";
    s = term[0];

    if(s == "-"){
        sign = 1;
    }

    return sign;
}

string search_and_destroy(string& term,char& c){
    for (int i = 0; i < term.size(); i++) {
        if (term[i] == c) {
            term.erase(i, 1); //borra el caracter indicado
            i--;
        }
    }
    return term;
}

double erasse(string& term){

    int aux = term.find('x');
    if (aux != string::npos){
        term = term.substr(0,aux); //Este código se encarga de tomar todo lo que está antes de la x
    }


    bool minus = false;
    if (signo(term) == 1){
        minus = true;  //si el bool minus aparece come true, entonces el coeficiente del término es negativo
    }

    char c='+';
    search_and_destroy(term,c);
    c='-';
    search_and_destroy(term,c);
    c='x';
    search_and_destroy(term,c);
    c='*';
    search_and_destroy(term,c);

    if(term == ""){
        term = "1";
    }

    double n = 0; 
    stringstream ss(term);
    ss>>n; //esta función transforma una cadena de string en un double, siempre que sea posible

    if(minus){
        n = n * (-1); //aquí nos aseguramos que los signos negativos sean contados dentro de los coeficientes
    }

    return(n);
}
