/*PROYECTO OOP: LOGIC: TUTOR*/
//Karim Herrera, Montse Sanchez, Sergio Barajas Jr.

#include <iostream> 
#include <vector> //para manejar vectores
#include <iomanip> //para setprecision
#include <string> 
#include <limits> //para manejar errores de entrada
#include <cstdlib> 
#include <fstream> // Para manejar archivos


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

        virtual ~Ejercicio() {}

        virtual void mostrarEjercicio() {
           cout << enunciado << " (Dificultad:" << dificultad << ")" << endl;
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

    public:
    Historial() : respuestasCorrectas(0), respuestasIncorrectas(0), promedio(0.0) {}

    Historial (int respuestasCorrectas, int respuestasIncorrectas, double promedio) {
        this->respuestasCorrectas = respuestasCorrectas;
        this->respuestasIncorrectas = respuestasIncorrectas;
        this->promedio = promedio;
    }
    
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
        promedio = ((respuestasCorrectas * 100) / (respuestasCorrectas + respuestasIncorrectas));
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
};

class Usuario {
    private:
    string nombre;
    Historial historial;

    public:
    Usuario(string nombre) : nombre(nombre), historial() {}
    string getNombre() const { 
        return nombre; 
    }
    Historial& getHistorial() {
        return historial;
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

    void mostrarEjercicio() override {
        cout << enunciado << " (Dificultad: " << dificultad << ")" << endl;
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
    void mostrarEjercicio() override {
        cout << enunciado << " (Dificultad: " << dificultad << ")" << endl;
    }

};




vector<EjercicioLogica*> obtenerEjerciciosFacilLogica() {
    vector<EjercicioLogica*> ejercicios;
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero y B es falso, ¿cuál es el resultado de A y B?", "Falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero o B es falso, ¿cuál es el resultado de A o B?", "Verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es falso y B es falso, ¿cuál es el resultado de A y B?", "Falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero y B es verdadero, ¿cuál es el resultado de A y B?", "Verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es falso o B es falso, ¿cuál es el resultado de A o B?", "Falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es falso y B es verdadero, ¿cuál es A o B?", "Verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es falso y B es verdadero, ¿cuál es A y B?", "Falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("¿Cuál es la negación de Verdadero?", "Falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("¿Cuál es la negación de Falso?", "Verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero, ¿cuál es A o Falso?", "Verdadero", "facil", "logica", 1));

    return ejercicios;
}

vector<EjercicioLogica*> obtenerEjerciciosIntermedioLogica() {
    vector<EjercicioLogica*> ejercicios;
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero y B es verdadero, ¿cuál es el resultado de A y B?", "Verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si A es falso o B es verdadero, ¿cuál es el resultado de A o B?", "Verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si no A es verdadero y A es falso, ¿es A una contradicción?", "Sí", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si A implica B y A es verdadero, ¿qué se puede decir de B?", "Verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si A equivale a B y A es falso, ¿qué se puede decir de B?", "Falso", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si A implica B y B es falso, ¿qué se puede decir de A?", "Falso", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("¿Qué valor tiene A si ¬A es falso?", "Verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si A y B son verdaderos, ¿cuál es A implica B?", "Verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("¿Qué valor tiene ¬(A ∨ B) si A es falso y B también?", "Verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si A es falso, ¿cuál es el valor de A ∧ ¬A?", "Falso", "intermedio", "logica", 2));

    return ejercicios;
}

vector<EjercicioLogica*> obtenerEjerciciosDificilLogica() {
    vector<EjercicioLogica*> ejercicios;
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero y B es falso, ¿cuál es el resultado de A y B?", "Falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero o B es falso, ¿cuál es el resultado de A o B?", "Verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("¿Cuál es la negación de 'A y B'?", "No A o no B", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("¿Qué valor tiene A si A implica B es falso y B es verdadero?", "Falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("¿Cuál es el valor de verdad de 'A o (B y C)' si A es falso, B es verdadero y C es falso?", "Falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("¿Cuál es la negación de 'A implica B'?", "A y no B", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si A o B es verdadero, y A es falso, ¿qué se puede decir de B?", "Verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("¿Cuál es el valor de ¬(A ∧ B) si A es verdadero y B falso?", "Verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si A es verdadero y ¬B es falso, ¿cuál es B?", "Verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si (A ↔ B) es verdadero y A es falso, ¿cuál es B?", "Falso", "dificil", "logica", 3));

    return ejercicios;  
}

vector<EjercicioAritmetica*> obtenerEjerciciosFacilAritmetica() {
    vector<EjercicioAritmetica*> ejercicios;
    ejercicios.push_back(new EjercicioAritmetica("2 + 2", "4", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("3 + 5", "8", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("6 - 1", "5", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("1 + 1", "2", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("4 + 0", "4", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("7 - 3", "4", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("5 + 2", "7", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("10 - 5", "5", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("3 + 3", "6", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("9 - 4", "5", "facil", "aritmetica", 1));

    return ejercicios;
}   

vector<EjercicioAritmetica*> obtenerEjerciciosIntermedioAritmetica() {
    vector<EjercicioAritmetica*> ejercicios;
    ejercicios.push_back(new EjercicioAritmetica("5 * 3", "15", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("10 - 4", "6", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("9 / 3", "3", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("6 * 2", "12", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("8 + 7", "15", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("7 * 2", "14", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("18 / 3", "6", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("14 - 7", "7", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("3 * 5", "15", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("20 - 9", "11", "intermedio", "aritmetica", 2));

    return ejercicios;
}

vector<EjercicioAritmetica*> obtenerEjerciciosDificilAritmetica() {
    vector<EjercicioAritmetica*> ejercicios;
    ejercicios.push_back(new EjercicioAritmetica("12 / 4", "3", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("15 + 7", "22", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("9 * 6", "54", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("25 - 13", "12", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("100 / 4", "25", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("144 / 12", "12", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("13 * 4", "52", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("45 - 28", "17", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("99 / 3", "33", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("36 / 6", "6", "dificil", "aritmetica", 3));

    return ejercicios;
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
    string nombre, password, password2, linea, respuestaUsuario;

    do{
        menu();
         cin >> opcion;
          if (cin.fail()) {
            cin.clear(); // limpia el estado de error
            cin.ignore(10000, '\n'); // descarta el resto de la entrada
            cout << "Error: Ingresa un número entero válido.\n";
            cout << "Presione cualquier tecla para continuar \n";
        } 

         cin.ignore();

        switch(opcion){
     
            case 1: {  
                cout << "Nuevo usuario" << endl;
                cout << "Ingrese su nombre: ";
                getline(cin, nombre);

           
                ifstream archivoIn("usuarios.txt");  // abrir el archivo en modo lectura y comprobar si el usuario ya existe
                bool existe = false;
                if (archivoIn.is_open()) {
                    while (getline(archivoIn, linea)) {
                        size_t pos = linea.find(':');          // ya que separaremos el nombre y la contraseña con ':', usamos esto para encontrar la posición
                        string usuarioExistente;
                        if (pos != string::npos) { 
                            usuarioExistente = linea.substr(0, pos); //si se encuentra ':', separamos el nombre y la contraseña
                        } else {
                            usuarioExistente = linea; // si no se encuentra ':' se asume que la línea es solo el nombre
                        }
                        if (usuarioExistente == nombre) {   // si el nombre ingresado coincide con el nombre existente en el archivo
                            existe = true;
                        break;
                        }
                    }
                    archivoIn.close();
                } else {
                    cout << "Error al abrir usuarios.txt para lectura" << endl;
                return 1;
                }

                if (existe) {
                    cout << "El usuario ya existe" << endl;
                } else {
                    // pedimos y confirmamos contraseña
                    cout << "Ingrese una contraseña: ";
                    getline(cin, password);
                    cout << "Confirme la contraseña: ";
                    getline(cin, password2);

                    if (password != password2) {
                        cout << "Las contraseñas no coinciden, vuelva a intentarlo" << endl;
                    } else {
                        ofstream archivoOut("usuarios.txt", ios::app);
                    if (archivoOut.is_open()) {
                            archivoOut << nombre << ':' << password << endl; // guardamos el nombre y la contraseña separados por ':'
                            archivoOut.close();
                            cout << "Usuario creado exitosamente" << endl;
                    } else {
                        cout << "Error al abrir el archivo" << endl;
                    }
                }
            }
            break;
        }

            case 2: {  
                cout << "Iniciar sesion" << endl;
                cout << "Ingrese su nombre: ";
                getline(cin, nombre);
                cout << "Ingrese su contraseña: ";
                getline(cin, password);

                Usuario usuario(nombre); // Initialize the 'usuario' object after successful login

                ifstream archivoIn("usuarios.txt");
                bool coincide = false;
                if (archivoIn.is_open()) {
                    while (getline(archivoIn, linea)) {
                        size_t pos = linea.find(':');
                        if (pos == string::npos) continue;                    // si no se encuentra ':', continuamos con la siguiente línea
                            string usuarioExistente = linea.substr(0, pos);              //misma lógica que antes, se busca el nombre y la contraseña
                            string passExistente   = linea.substr(pos + 1);
                            if (usuarioExistente == nombre && passExistente == password) { // si el nombre y la contraseña coinciden, el bool coincide se vuelve true
                                coincide = true;
                                break;
                            }
                        }
                    archivoIn.close();
                    } else {
                    cout << "Error al abrir el archivo" << endl;
                        return 0;
                    }

                    if (coincide) {
                        cout << "Inicio de sesion exitoso, bienvenido " << nombre << "!" << endl;
                    } else {
                        cout << "Usuario o contraseña incorrectos" << endl;
                    }
                    do{
                        menuUsuario();
                        cin >> opcionUsuario;
                        if (cin.fail()) {
                                    cin.clear(); // limpia el estado de error
                                    cin.ignore(10000, '\n'); // descarta el resto de la entrada
                                    cout << "Error: Ingresa un número entero válido.\n";
                                    cout << "Presione cualquier tecla para continuar \n";
                        } 
                        cin.ignore();

                         switch (opcionUsuario){
                            case 1: {
                            cout << "Ejercicios" << endl;
                            cout << "1. Aritmetica" << endl;
                            cout << "2. Logica" << endl;
                            cout << "3. Combinado " << endl;
                            cout << "Seleccione una opcion: ";
                            int tipoEjercicio;
                            int dificultad;
                            cin >> tipoEjercicio;
                            cin.ignore();
                            if (tipoEjercicio == 1) {
                                cout << "Aritmetica" << endl;
                                cout << "Dificultad" << endl;
                                cout << "1. Facil" << endl;
                                cout << "2. Intermedio" << endl;
                                cout << "3. Dificil" << endl;
                                cout << "Seleccione una opcion: ";
                                cin >> dificultad;
                                cin.ignore();
                                if (dificultad == 1) {
                                    vector<EjercicioAritmetica*> ejercicios = obtenerEjerciciosFacilAritmetica();
                                    for (auto* e : ejercicios) {
                                    e->mostrarEjercicio();
                                    string resp;
                                    cout << "Tu respuesta: ";
                                    getline(cin, resp);

                                    if (resp == e->getRespuesta()) {
                                        cout << "Correcto!" << endl;
                                        usuario.getHistorial().agregarRespuestaCorrecta();
                                    } else {
                                        cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                        usuario.getHistorial().agregarRespuestaIncorrecta();
                                    }
                                }
                                usuario.getHistorial().calcularPromedio(); // Update the user's history
                                for (auto* e : ejercicios) delete e; // liberar memoria
                                break;
                            }
                                } else if (dificultad == 2) {
                                    vector<EjercicioAritmetica*> ejercicios = obtenerEjerciciosIntermedioAritmetica();
                                    for (auto* e : ejercicios) {
                                    e->mostrarEjercicio();
                                    string resp;
                                    cout << "Tu respuesta: ";
                                    getline(cin, resp);

                                    if (resp == e->getRespuesta()) {
                                        cout << "Correcto!" << endl;
                                        usuario.getHistorial().agregarRespuestaCorrecta();
                                    } else {
                                        cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                        usuario.getHistorial().agregarRespuestaIncorrecta();
                                    }
                                }
                                usuario.getHistorial().calcularPromedio();
                                for (auto* e : ejercicios) delete e; // liberar memoria
                                break;

                                } else if (dificultad == 3) {
                                    vector<EjercicioAritmetica*> ejercicios = obtenerEjerciciosDificilAritmetica();
                                    for (auto* e : ejercicios) {
                                    e->mostrarEjercicio();
                                    string resp;
                                    cout << "Tu respuesta: ";
                                    getline(cin, resp);
                                    if (resp == e->getRespuesta()) {
                                        cout << "Correcto!" << endl;
                                        usuario.getHistorial().agregarRespuestaCorrecta();
                                    } else {
                                        cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                        usuario.getHistorial().agregarRespuestaIncorrecta();
                                    }
                                }
                                usuario.getHistorial().calcularPromedio();
                                for (auto* e : ejercicios) delete e; // liberar memoria
                                break;
                            }
                             else if (tipoEjercicio == 2) {
                                cout << "Logica" << endl;
                                cout << "Dificultad" << endl;
                                cout << "1. Facil" << endl;
                                cout << "2. Intermedio" << endl;
                                cout << "3. Dificil" << endl;
                                cout << "Seleccione una opcion: ";
                                cin >> dificultad;
                                cin.ignore();
                                if (dificultad == 1) {
                                    vector<EjercicioLogica*> ejercicios = obtenerEjerciciosFacilLogica();
                                    for (auto* e : ejercicios) {
                                    e->mostrarEjercicio();
                                    string resp;
                                    cout << "Tu respuesta: ";
                                    getline(cin, resp);
                                    if (resp == e->getRespuesta()) {
                                        cout << "Correcto!" << endl;
                                        usuario.getHistorial().agregarRespuestaCorrecta();
                                    } else {
                                        cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                        usuario.getHistorial().agregarRespuestaIncorrecta();
                                    }
                                }
                                usuario.getHistorial().calcularPromedio();
                                for (auto* e : ejercicios) delete e; // liberar memoria
                                break;

                                } else if (dificultad == 2) {
                                    vector<EjercicioLogica*> ejercicios = obtenerEjerciciosIntermedioLogica();
                                    for (auto* e : ejercicios) {
                                    e->mostrarEjercicio();
                                    string resp;
                                    cout << "Tu respuesta: ";
                                    getline(cin, resp);
                                    if (resp == e->getRespuesta()) {
                                        cout << "Correcto!" << endl;
                                        usuario.getHistorial().agregarRespuestaCorrecta();
                                    } else {
                                        cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                        usuario.getHistorial().agregarRespuestaIncorrecta();
                                    }
                                }
                                } else if (dificultad == 3) {
                                    vector<EjercicioLogica*> ejercicios = obtenerEjerciciosDificilLogica();
                                    for (auto* e : ejercicios) {
                                    e->mostrarEjercicio();
                                    string resp;
                                    cout << "Tu respuesta: ";
                                    getline(cin, resp);
                                    
                                    if (resp == e->getRespuesta()) {
                                        cout << "Correcto!" << endl;
                                        usuario.getHistorial().agregarRespuestaCorrecta();
                                    } else {
                                        cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                        usuario.getHistorial().agregarRespuestaIncorrecta();
                                    }
                                    usuario.getHistorial().calcularPromedio();
                                    for (auto* e : ejercicios) delete e; // liberar memoria
                                    break;
                                }
                                }
                            } else if (tipoEjercicio == 3) {
                                cout << "Ejercicios Combinados" << endl;
                                cout << "Dificultad" << endl;
                                cout << "1. Facil" << endl;
                                cout << "2. Intermedio" << endl;
                                cout << "3. Dificil" << endl;
                                cout << "Seleccione una opcion: ";
                                cin >> dificultad;
                                cin.ignore();
                                if (dificultad == 1) {
                                    vector<EjercicioAritmetica*> ejerciciosAritmetica = obtenerEjerciciosFacilAritmetica();
                                    vector<EjercicioLogica*> ejerciciosLogica = obtenerEjerciciosFacilLogica();
                                    for (auto* e : ejerciciosAritmetica) {
                                        e->mostrarEjercicio();
                                        string resp;
                                        cout << "Tu respuesta: ";
                                        getline(cin, resp);
                                        if (resp == e->getRespuesta()) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }
                                    }
                                    for (auto* e : ejerciciosLogica) {
                                        e->mostrarEjercicio();
                                        string resp;
                                        cout << "Tu respuesta: ";
                                        getline(cin, resp);
                                        if (resp == e->getRespuesta()) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }
                                    }
                                    usuario.getHistorial().calcularPromedio();
                                    for (auto* e : ejerciciosAritmetica) delete e; // liberar memoria
                                    for (auto* e : ejerciciosLogica) delete e; // liberar memoria
                                    break;
                                } else if (dificultad == 2) {
                                    vector<EjercicioAritmetica*> ejerciciosAritmetica = obtenerEjerciciosIntermedioAritmetica();
                                    vector<EjercicioLogica*> ejerciciosLogica = obtenerEjerciciosIntermedioLogica();
                                    for (auto* e : ejerciciosAritmetica) {
                                        e->mostrarEjercicio();
                                        string resp;
                                        cout << "Tu respuesta: ";
                                        getline(cin, resp);
                                        if (resp == e->getRespuesta()) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }
                                    }
                                    for (auto* e : ejerciciosLogica) {
                                        e->mostrarEjercicio();
                                        string resp;
                                        cout << "Tu respuesta: ";
                                        getline(cin, resp);
                                        if (resp == e->getRespuesta()) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }
                                    }
                                    usuario.getHistorial().calcularPromedio();
                                    for (auto* e : ejerciciosLogica) delete e; // liberar memoria
                                    break;
                                   
                                }
                                else if (dificultad == 3) {
                                } else if (dificultad == 3) {
                                    vector<EjercicioAritmetica*> ejerciciosAritmetica = obtenerEjerciciosDificilAritmetica();
                                    vector<EjercicioLogica*> ejerciciosLogica = obtenerEjerciciosDificilLogica();
                                    for (auto* e : ejerciciosAritmetica) {
                                        e->mostrarEjercicio();
                                        string resp;
                                        cout << "Tu respuesta: ";
                                        getline(cin, resp);
                                        if (resp == e->getRespuesta()) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }
                                    }
                                    for (auto* e : ejerciciosLogica) {
                                        e->mostrarEjercicio();
                                        string resp;
                                        cout << "Tu respuesta: ";
                                        getline(cin, resp);
                                        if (resp == e->getRespuesta()) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }
                                    }
                                    usuario.getHistorial().calcularPromedio();
                                    for (auto* e : ejerciciosAritmetica) delete e; // liberar memoria
                                    for (auto* e : ejerciciosLogica) delete e; // liberar memoria
                                    break;
                                   
                                }
                            }
                            else {
                                cout << "Opcion no valida, intente de nuevo." << endl;
                            }
                        }
                        break;

                        case 2:
                            cout << "Historial" << endl;
                            cout << "Nombre: " << usuario.getNombre() << endl;
                            cout << "Respuestas correctas: " << usuario.getHistorial().getRespuestasCorrectas() << endl;
                            cout << "Respuestas incorrectas: " << usuario.getHistorial().getRespuestasIncorrectas() << endl;
                            cout << "Promedio: " << usuario.getHistorial().getPromedio() << "%" << endl;
                            break;
                        case 3:
                            // Salir
                            break;
                        default:
                            cout << "Opcion no valida, intente de nuevo." << endl;
                            break;
                        }
                    } while (opcionUsuario != 3);
            break;
                }
            case 3:
                cout << "Saliendo..." << endl;
                break;
            }
        } while (opcion != 3);
    return 0;
}
                
            

            



                       

        
