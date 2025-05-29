#pragma once
using namespace std;
#include <cstdint>
#include <iostream> 
#include <vector> //para manejar vectores
#include <iomanip> //para setprecision
#include <string> 
#include <limits> //para manejar errores de entrada
#include <cstdlib> 
#include <fstream> // Para manejar archivos
#include <algorithm> // para std::shuffle
#include <random> // para std::default_random_engine
#include <chrono> // para seed del reloj



class Ejercicio {
    protected: 
        string dificultad;
        string respuesta;
        string enunciado;

    public: 
        Ejercicio(string enunciado, string respuesta, string dificultad);

        virtual ~Ejercicio();

        virtual void mostrarEjercicio();

        string getEnunciado();
        string getDificultad();
        string getRespuesta();

        //funcion para validar la respuesta del usuario 
        bool validarRespuesta(const string& usuario);

        // polimorfismo estatico:
        // Sobrecarga: para validar la respuesta del usuario ignorando mayusculas y minusculas
        bool validarRespuesta(const string& usuario, bool ignorarMayusculas);

};

class Historial {
    private: 
    double promedio;
    int respuestasCorrectas;
    int respuestasIncorrectas;

    public:
    Historial();

    Historial (int respuestasCorrectas, int respuestasIncorrectas, double promedio) ;
    
    double getPromedio() const;
    int getRespuestasCorrectas() const;
    int getRespuestasIncorrectas() const;

    void calcularPromedio() ;
    void agregarRespuestaCorrecta() ;
    void agregarRespuestaIncorrecta() ;
    void mostrarHistorial() const ;
    //Guardar historial en un archivo
   void guardarHistorial(const string& nombreUsuario) const ;

   void cargarHistorialGeneral(const string& nombreUsuario);
};

class Usuario {
    private:
    string nombre;
    Historial historial; //composicion

    public:
    Usuario(string nombre);
    string getNombre() const;
    Historial& getHistorial();

};


class EjercicioAritmetica : public Ejercicio { //herencia
    private:
    string tipo;
    int puntos;
    public:
    EjercicioAritmetica(string enunciado, string respuesta, string dificultad, string tipo, int puntos) ;

    void mostrarEjercicio() override;


};

class EjercicioLogica : public Ejercicio { //herencia
    private:
    string tipo;
    int puntos;
    public:
    EjercicioLogica(string enunciado, string respuesta, string dificultad, string tipo, int puntos);
    void mostrarEjercicio() override ;

};

   void clearConsole();