/*PROYECTO OOP: LOGIC: TUTOR*/
//Karim Herrera, Montse Sanchez, Sergio Barajas Jr.


#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>


using namespace std;


class Ejercicio {
    protected: 
        string dificultad;
        string respuesta;
        string enunciado;

    public: 
        Ejercicio(string enunciado, string respuesta, string dificultad) {
            this->enunciado = enunciado;
            this->dificultad = dificultad;
            this->respuesta = respuesta;
        }
        string getEnunciado() {
            return enunciado;
        }
        string getDificultad() {
            return dificultad;
        }
        string getRespuesta() {
            return respuesta;
        }

};

class Historial {
    private: 
    double promedio;
    int respuestasCorrectas;
    int respuestasIncorrectas;

    Historial (int respuestasCorrectas, int respuestasIncorrectas, double promedio) {
        this->respuestasCorrectas = respuestasCorrectas;
        this->respuestasIncorrectas = respuestasIncorrectas;
        this->promedio = promedio;
    }
    public:
    
    double getPromedio() const {
        return promedio;
    }
    int getRespuestasCorrectas() const {
        return respuestasCorrectas;
    }
    int getRespuestasIncorrectas() const {
        return respuestasIncorrectas;
    }

    void calcularPromedio() {
        promedio = (respuestasCorrectas * 100) / (respuestasCorrectas + respuestasIncorrectas);
    }
    void agregarRespuestaCorrecta() {
        respuestasCorrectas++;
    }
    void agregarRespuestaIncorrecta() {
        respuestasIncorrectas++;
    }
    void mostrarHistorial() const {
        cout << "Respuestas correctas: " << respuestasCorrectas << endl;
        cout << "Respuestas incorrectas: " << respuestasIncorrectas << endl;
        cout << "Promedio: " << fixed << setprecision(2) << promedio << "%" << endl;
    }
    void reiniciarHistorial() {
        respuestasCorrectas = 0;
        respuestasIncorrectas = 0;
        promedio = 0.0;
    }
    
};

class Usuario {
    private:
    string nombre;
   
    vector<Historial> historial;
    public:
    Usuario(string nombre) {
        this->nombre = nombre;
      
    }
    string getNombre() const {
        return nombre;
    }

    
};

class EjercicioAritmetica : public Ejercicio {
    private:
    string tipo;
    int puntos;
    public:
    EjercicioAritmetica(string enunciado, string respuesta, string dificultad, string tipo, int puntos) : Ejercicio(enunciado, respuesta, dificultad) {
        this->tipo = tipo;
        this->puntos = puntos;
    }


};

class EjercicioLogica : public Ejercicio {
    private:
    string tipo;
    int puntos;
    public:
    EjercicioLogica(string enunciado, string respuesta, string dificultad, string tipo, int puntos) : Ejercicio(enunciado, respuesta, dificultad) {
        this->tipo = tipo;
        this->puntos = puntos;
    }


};



void crearEjercicios(){

    
}

void menu(){
    cout << "1. Nuevo usuario" << endl;
    cout << "2. Iniciar sesion"  << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";

}

void menuUsuario(){
    cout << "1. Empezar ejercicios" << endl;
    cout << "2. Ver historial"  << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: " ;
}

int buscarUsuario(const string& nombre, const vector<Usuario>& usuarios){
	int indice = 0;
    for(const auto& c : usuarios){
        if(c.getNombre() == nombre){
			return indice;
		}
		indice++;
	}
	return -1;
}



int main(){
    cout << "LOGIC TUTOR EDUCATIVO" << endl;
    int opcion = 0;
    int opcionUsuario = 0;

    vector<Usuario> usuarios;

    do{
    menu();
    cin >> opcion;
    cin.ignore();
    string nombre;
    int indiceUsuario = 0;
    
    switch(opcion){
            case 1: {
                cout << "Ingrese su nombre: ";
                getline(cin, nombre);
        
                for(const auto & c : usuarios){
                    if (c.getNombre() != nombre) {
                        usuarios.emplace_back(nombre);
                        cout << "Usuario registrado con exito " << endl;
                    }else{
                        cout << "Este usuario ya existe" << endl;
                    }
                }
            break;
            } 
            
            case 2: {
                cout << "Inicio de sesion" << endl;
                cout << "Ingrese su nombre: ";
                getline(cin, nombre);
               
                indiceUsuario = buscarUsuario(nombre, usuarios);
                cout << "Inicio de sesion exitoso" << endl;

            

                do{
                    menuUsuario();
                    cin >> opcionUsuario;
                    cin.ignore();
                    cout << "indice" << indiceUsuario << endl;

                    }while (opcionUsuario != 3);
                 }
                
            }
           

    
    }while (opcion != 3);
    
    }






