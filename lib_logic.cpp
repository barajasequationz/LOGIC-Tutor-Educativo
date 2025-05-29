#include "lib_logic.h"


 
        Ejercicio::Ejercicio(string enunciado, string respuesta, string dificultad) {
            this->enunciado = enunciado;
            this->dificultad = dificultad;
            this->respuesta = respuesta;
        }

        Ejercicio::~Ejercicio() {}

         void Ejercicio::mostrarEjercicio() {
           cout << enunciado << endl;
        }
        string Ejercicio::getEnunciado() {
            return enunciado;
        }
        string Ejercicio::getDificultad() {
            return dificultad;
        }
        string Ejercicio::getRespuesta() {
            return respuesta;
        }

        //funcion para validar la respuesta del usuario 
        bool Ejercicio::validarRespuesta(const string& usuario) {
            return usuario == respuesta;
        }

        // polimorfismo estatico:
        // Sobrecarga: para validar la respuesta del usuario ignorando mayusculas y minusculas
        bool Ejercicio::validarRespuesta(const string& usuario, bool ignorarMayusculas) {
            if (!ignorarMayusculas) return usuario == respuesta;

            string userLower = usuario, respLower = respuesta;
            transform(userLower.begin(), userLower.end(), userLower.begin(), ::tolower);
            transform(respLower.begin(), respLower.end(), respLower.begin(), ::tolower);
            return userLower == respLower;
        }



;

    Historial::Historial() : respuestasCorrectas(0), respuestasIncorrectas(0), promedio(0.0) {}

    Historial::Historial (int respuestasCorrectas, int respuestasIncorrectas, double promedio) {
        this->respuestasCorrectas = respuestasCorrectas;
        this->respuestasIncorrectas = respuestasIncorrectas;
        this->promedio = promedio;
    }
    
    double Historial::getPromedio() const {
        return promedio;
    }
    int Historial::getRespuestasCorrectas() const {
        return respuestasCorrectas;
    }
    int Historial::getRespuestasIncorrectas() const {
        return respuestasIncorrectas;
    }

    void Historial::calcularPromedio() {
       promedio = (static_cast<double>(respuestasCorrectas) / (respuestasCorrectas + respuestasIncorrectas)) * 100;
    if (respuestasCorrectas + respuestasIncorrectas == 0) {
            promedio = 0.0; // Evitar división por cero
        }
        cout << "Promedio: " << fixed << setprecision(2) << promedio << "%" << endl;
    
    }
    void Historial::agregarRespuestaCorrecta() {
        respuestasCorrectas++;
    }
    void Historial::agregarRespuestaIncorrecta() {
        respuestasIncorrectas++;
    }
    void Historial::mostrarHistorial() const {
        cout << "Respuestas correctas: " << respuestasCorrectas << endl;
        cout << "Respuestas incorrectas: " << respuestasIncorrectas << endl;
        cout << "Promedio: " << fixed << setprecision(2) << promedio << "%" << endl;
    }
    //Guardar historial en un archivo
   void Historial::guardarHistorial(const string& nombreUsuario) const {
    ofstream archivo("historial_general.txt", ios::app); // archivo único
    if (archivo.is_open()) {
        archivo << nombreUsuario << ',' << respuestasCorrectas << ',' << respuestasIncorrectas << ',' << promedio << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de historial general" << endl;
    }
}

   void Historial::cargarHistorialGeneral(const string& nombreUsuario) {
    ifstream archivo("historial_general.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre;
            getline(ss, nombre, ',');
            if (nombre == nombreUsuario) {
                string correctas, incorrectas, prom;
                getline(ss, correctas, ',');
                getline(ss, incorrectas, ',');
                getline(ss, prom, ',');
                respuestasCorrectas = stoi(correctas);
                respuestasIncorrectas = stoi(incorrectas);
                promedio = stod(prom);
            }
        }
        archivo.close();
    }
}



    Usuario::Usuario(string nombre) : nombre(nombre), historial() {}
    string Usuario::getNombre() const { 
        return nombre; 
    }
    Historial& Usuario::getHistorial() {
        return historial;
    }





    EjercicioAritmetica::EjercicioAritmetica(string enunciado, string respuesta, string dificultad, string tipo, int puntos) : Ejercicio(enunciado, respuesta, dificultad) {
        this->tipo = tipo;
        this->puntos = puntos;
    }

    void EjercicioAritmetica::mostrarEjercicio(){
        cout << enunciado << endl;
    }





    EjercicioLogica::EjercicioLogica(string enunciado, string respuesta, string dificultad, string tipo, int puntos) : Ejercicio(enunciado, respuesta, dificultad) {
        this->tipo = tipo;
        this->puntos = puntos;
    }
    void EjercicioLogica::mostrarEjercicio() {
        cout << enunciado << endl;
    }

    void clearConsole() {
    std::cout << "\x1B[2J\x1B[H";
}