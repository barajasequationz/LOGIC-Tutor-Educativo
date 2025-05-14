/*PROYECTO OOP: LOGIC: TUTOR*/
//Karim Herrera, Montse Sanchez, Sergio Barajas Jr.


#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <fstream>


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





int main(){
    cout << "LOGIC TUTOR EDUCATIVO" << endl;
    int opcion = 0;
    int opcionUsuario = 0;

    do{
    menu();
    cin >> opcion;
    cin.ignore();
    
    string nombre;
    string linea;
    switch(opcion){
         case 1: {
            cout << "Ingrese su nombre: ";
            getline(cin, nombre);
                
            fstream archivo("usuarios.txt", ios::in); //ios::in para leer el archivo
            bool existe = false;
            string linea;

            if (archivo.is_open()) {
                while (getline(archivo, linea)) {
                    if (linea == nombre) {
                        existe = true;
                        break;
                        }
                    }
                    archivo.close();
                    } else {
                        cout << "Error al abrir el archivo" << endl;
                    return 0;
                    }
                    if (existe) {
                        cout << "El usuario ya existe" << endl;
                    } else {
                        //archivoOut es una instancia de fstream para escribir en el archivo
                        ofstream archivoOut("usuarios.txt", ios::app); //ios::app para agregar al final del archivo
                        if (archivoOut.is_open()) {
                            archivoOut << nombre << endl;
                            archivoOut.close();
                            cout << "Usuario creado exitosamente" << endl;
                        } else {
                            cout << "Error al escribir en el archivo" << endl;
                        }
                    }
                    break;
                } 
            
            case 2: {
                cout << "Inicio de sesion" << endl;
                cout << "Ingrese su nombre: ";
                getline(cin, nombre);
               
                cout << "Inicio de sesion exitoso" << endl;

            

                do{
                    menuUsuario();
                    cin >> opcionUsuario;
                    cin.ignore();
         

                    }while (opcionUsuario != 3);
                 }
                
            }
           

    
    }while (opcion != 3);
    
    }






