/*PROYECTO OOP: LOGIC: TUTOR*/
//Karim Herrera, Montse Sanchez, Sergio Barajas Jr.

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
#include "lib_logic.h" // liberia propia


using namespace std;



vector<EjercicioLogica*> obtenerEjerciciosFacilLogica() {
    vector<EjercicioLogica*> ejercicios;
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero, ¿cuál es el valor de ¬p?", "falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si q es falso, ¿cuál es el valor de ¬q?", "verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p y q son verdaderos, ¿cuál es el valor de p ∧ q?", "verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p ∧ q?", "falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de p v q?", "falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p v q?", "verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p y q son verdaderos, ¿cuál es el valor de ¬(p ∧ q)?", "falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de ¬(p v q)?", "verdadero", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si p es falso, ¿cuál es el valor de ¬(¬p)?", "falso", "facil", "logica", 1));
    ejercicios.push_back(new EjercicioLogica("Si q es verdadero, ¿cuál es el valor de ¬(¬q)?", "verdadero", "facil", "logica", 1));
    return ejercicios;
}


vector<EjercicioLogica*> obtenerEjerciciosIntermedioLogica() {
    vector<EjercicioLogica*> ejercicios;
    ejercicios.push_back(new EjercicioLogica("Si p y q son verdaderos, ¿cuál es el valor de p → q?", "verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p → q?", "falso", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p es falso y q es verdadero, ¿cuál es el valor de p → q?", "verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de p → q?", "verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p y q son verdaderos, ¿cuál es el valor de p ↔ q?", "verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p ↔ q?", "falso", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de ¬p V q?", "falso", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de ¬p V q?", "verdadero", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de ¬(p ∧ ¬q)?", "falso", "intermedio", "logica", 2));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p V (¬q ∧ p)?", "verdadero", "intermedio", "logica", 2));
    return ejercicios;
}

vector<EjercicioLogica*> obtenerEjerciciosDificilLogica() {
    vector<EjercicioLogica*> ejercicios;
    ejercicios.push_back(new EjercicioLogica("Si p es falso y q es verdadero, ¿cuál es el valor de ¬(p V ¬q)?", "falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de ¬(¬p ∧ q)?", "verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p ∧ (q V ¬p)?", "verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de ¬(p → q)?", "verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de ¬(p → q)?", "falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p es falso y q es verdadero, ¿cuál es el valor de (¬p ∧ q) → p?", "falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de (p ∧ ¬q) V (¬p ∧ q)?", "verdadero", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de ¬(¬p V ¬q)?", "falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p es verdadero y q es falso, ¿cuál es el valor de p ↔ (q V ¬p)?", "falso", "dificil", "logica", 3));
    ejercicios.push_back(new EjercicioLogica("Si p y q son falsos, ¿cuál es el valor de ¬(p ∧ q) V (¬p ∧ ¬q)?", "verdadero", "dificil", "logica", 3));
    return ejercicios;
}


vector<EjercicioAritmetica*> obtenerEjerciciosFacilAritmetica() {
    vector<EjercicioAritmetica*> ejercicios;
    ejercicios.push_back(new EjercicioAritmetica("8 + 6 - 3", "11", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("2 * 4 + 1", "9", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("9 - 3 + 2", "8", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("raiz(16)", "4", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("3^2", "9", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("12 / 3 + 2", "6", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("raiz(9) + 1", "4", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("2^3", "8", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("15 - 5 * 2", "5", "facil", "aritmetica", 1));
    ejercicios.push_back(new EjercicioAritmetica("6 + 2 * 2", "10", "facil", "aritmetica", 1));
    return ejercicios;
}


vector<EjercicioAritmetica*> obtenerEjerciciosIntermedioAritmetica() {
    vector<EjercicioAritmetica*> ejercicios;
    ejercicios.push_back(new EjercicioAritmetica("raiz(49) + 2", "9", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("4^2 - 5", "11", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("18 / 3 + 7", "13", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("6^2", "36", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("raiz(81) - 3", "6", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("3^3", "27", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("25 / 5 + 2^2", "9", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("raiz(64) + raiz(36)", "14", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("7^2 - 10", "39", "intermedio", "aritmetica", 2));
    ejercicios.push_back(new EjercicioAritmetica("2^4 + 3", "19", "intermedio", "aritmetica", 2));
    return ejercicios;
}


vector<EjercicioAritmetica*> obtenerEjerciciosDificilAritmetica() {
    vector<EjercicioAritmetica*> ejercicios;
    ejercicios.push_back(new EjercicioAritmetica("raiz(121) + 5^2", "36", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("raiz(100) + 3^3", "37", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("4^3 - raiz(81)", "55", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("2^5 + 6^2", "68", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("10^2 - 3^2", "91", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("raiz(144) + √49", "17", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("5^3 / 5", "25", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("raiz(169) + 2^4", "33", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("3^4 - 4^2", "65", "dificil", "aritmetica", 3));
    ejercicios.push_back(new EjercicioAritmetica("(2^3 + 4^2) / 2", "12", "dificil", "aritmetica", 3));
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
                    clearConsole();
                    
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
                        usuario.getHistorial().cargarHistorialGeneral(usuario.getNombre());
                    } else {
                        cout << "Usuario o contraseña incorrectos" << endl;
                        break;
                
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
                                cout << "Escriba '#' para salir de los ejercicios" << endl;
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
                                        shuffle(ejercicios.begin(), ejercicios.end(),default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

                                        int contador = 1; // Contador para el número de ejercicios
                                        for (auto* e : ejercicios) {
                                        cout << "Ejercicio # " << (contador++) << endl;
                                        e->mostrarEjercicio();
                                        string resp;
                                        do {
                                            cout << "Tu respuesta: ";
                                            getline(cin, resp);
                                            if (resp.empty()) {
                                                cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                            } else if (resp == "#") {
                                                break;
                                            }
                                        } while (resp.empty());

                                        if (resp == "#") {
                                            break; // salir del bucle de ejercicios
                                        } else if (e->validarRespuesta(resp)) {
                                            cout << "Correcto!" << endl;
                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                        } else {
                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                        }

                                        }
                                        usuario.getHistorial().calcularPromedio();
                                        usuario.getHistorial().guardarHistorial(usuario.getNombre());

                                        for (auto* e : ejercicios) delete e;
                                        } else if (dificultad == 2) {
                                            vector<EjercicioAritmetica*> ejercicios = obtenerEjerciciosIntermedioAritmetica();
                                            shuffle(ejercicios.begin(), ejercicios.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                            int contador = 1; // Contador para el número de ejercicios
                                            for (auto* e : ejercicios) {
                                                cout << "Ejercicio # " << (contador++) << endl;
                                                e->mostrarEjercicio();
                                                string resp;
                                                do {
                                                    cout << "Tu respuesta: ";
                                                    getline(cin, resp);
                                                    if (resp.empty()) {
                                                        cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                    } else if (resp == "#") {
                                                        break;
                                                    }
                                                } while (resp.empty());

                                                if (resp == "#") {
                                                    break; // salir del bucle de ejercicios
                                                } else if (e->validarRespuesta(resp)) {
                                                    cout << "Correcto!" << endl;
                                                    usuario.getHistorial().agregarRespuestaCorrecta();
                                                } else {
                                                    cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                    usuario.getHistorial().agregarRespuestaIncorrecta();
                                                }

                                                }
                                                usuario.getHistorial().calcularPromedio();
                                                usuario.getHistorial().guardarHistorial(usuario.getNombre());

                                                for (auto* e : ejercicios) delete e;
                                                } else if (dificultad == 3) {
                                                    vector<EjercicioAritmetica*> ejercicios = obtenerEjerciciosDificilAritmetica();
                                                    shuffle(ejercicios.begin(), ejercicios.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                    int contador = 1; // Contador para el número de ejercicios
                                                    for (auto* e : ejercicios) {
                                                        cout << "Ejercicio # " << (contador++) << endl;
                                                        e->mostrarEjercicio();
                                                        string resp;
                                                        do {
                                                            cout << "Tu respuesta: ";
                                                            getline(cin, resp);
                                                            if (resp.empty()) {
                                                                cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                            } else if (resp == "#") {
                                                                break;
                                                            }
                                                        } while (resp.empty());

                                                        if (resp == "#") {
                                                            break; // salir del bucle de ejercicios
                                                        } else if (e->validarRespuesta(resp)) {
                                                            cout << "Correcto!" << endl;
                                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                                        } else {
                                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                                        }

                                                    }
                                                usuario.getHistorial().calcularPromedio();
                                                usuario.getHistorial().guardarHistorial(usuario.getNombre());
                                                for (auto* e : ejercicios) delete e;
                                            }

                                                } else if (tipoEjercicio == 2) {
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
                                                        shuffle(ejercicios.begin(), ejercicios.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                        int contador = 1; // Contador para el número de ejercicios
                                                        for (auto* e : ejercicios) {
                                                            cout << "Ejercicio # " << (contador++) << endl;
                                                            e->mostrarEjercicio();
                                                            string resp;
                                                            do {
                                                                cout << "Tu respuesta: ";
                                                                getline(cin, resp);
                                                                if (resp.empty()) {
                                                                    cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                                } else if (resp == "#") {
                                                                    break;
                                                                }
                                                            } while (resp.empty());

                                                            if (resp == "#") {
                                                                break; // salir del bucle de ejercicios
                                                            } else if (e->validarRespuesta(resp,true)) {
                                                                cout << "Correcto!" << endl;
                                                                usuario.getHistorial().agregarRespuestaCorrecta();
                                                            } else {
                                                                cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                                usuario.getHistorial().agregarRespuestaIncorrecta();
                                                            }

                                                        }
                                                        usuario.getHistorial().calcularPromedio();
                                                        usuario.getHistorial().guardarHistorial(usuario.getNombre());
                                                        for (auto* e : ejercicios) delete e;

                                                    } else if (dificultad == 2) {
                                                        vector<EjercicioLogica*> ejercicios = obtenerEjerciciosIntermedioLogica();
                                                        shuffle(ejercicios.begin(), ejercicios.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                        int contador = 1; // Contador para el número de ejercicios
                                                        for (auto* e : ejercicios) {
                                                            cout << "Ejercicio # " << (contador++) << endl;
                                                            e->mostrarEjercicio();
                                                            string resp;
                                                            do {
                                                                cout << "Tu respuesta: ";
                                                                getline(cin, resp);
                                                                if (resp.empty()) {
                                                                    cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                                } else if (resp == "#") {
                                                                    break;
                                                                }
                                                            } while (resp.empty());

                                                            if (resp == "#") {
                                                                break; // salir del bucle de ejercicios
                                                            } else if (e->validarRespuesta(resp,true)) {
                                                                cout << "Correcto!" << endl;
                                                                usuario.getHistorial().agregarRespuestaCorrecta();
                                                            } else {
                                                                cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                                usuario.getHistorial().agregarRespuestaIncorrecta();
                                                            }

                                                        }
                                                        usuario.getHistorial().calcularPromedio();
                                                        usuario.getHistorial().guardarHistorial(usuario.getNombre());
                                                        for (auto* e : ejercicios) delete e;

                                                    } else if (dificultad == 3) {
                                                        vector<EjercicioLogica*> ejercicios = obtenerEjerciciosDificilLogica();
                                                        shuffle(ejercicios.begin(), ejercicios.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                        int contador = 1; // Contador para el número de ejercicios
                                                        for (auto* e : ejercicios) {
                                                            cout << "Ejercicio # " << (contador++) << endl;
                                                            e->mostrarEjercicio();
                                                            string resp;
                                                            do {
                                                                cout << "Tu respuesta: ";
                                                                getline(cin, resp);
                                                                if (resp.empty()) {
                                                                    cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                                } else if (resp == "#") {
                                                                    break;
                                                                }
                                                            } while (resp.empty());

                                                            if (resp == "#") {
                                                                break; // salir del bucle de ejercicios
                                                            } else if (e->validarRespuesta(resp,true)) {
                                                                cout << "Correcto!" << endl;
                                                                usuario.getHistorial().agregarRespuestaCorrecta();
                                                            } else {
                                                                cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                                usuario.getHistorial().agregarRespuestaIncorrecta();
                                                            }

                                                        }
                                                        usuario.getHistorial().calcularPromedio();
                                                        usuario.getHistorial().guardarHistorial(usuario.getNombre());
                                                        for (auto* e : ejercicios) delete e;
                                                    }

                                                } else if (tipoEjercicio == 3) {
                                                    int contador = 1; // Contador para el número de ejercicios
                                                    cout << "Ejercicios Combinados" << endl;
                                                    cout << "Dificultad" << endl;
                                                    cout << "1. Facil" << endl;
                                                    cout << "2. Intermedio" << endl;
                                                    cout << "3. Dificil" << endl;
                                                    cout << "Seleccione una opcion: ";
                                                    cin >> dificultad;
                                                    cin.ignore();

                                                    vector<EjercicioAritmetica*> ejerciciosAritmetica;
                                                    vector<EjercicioLogica*> ejerciciosLogica;

                                                    if (dificultad == 1) {
                                                        ejerciciosAritmetica = obtenerEjerciciosFacilAritmetica();
                                                        shuffle(ejerciciosAritmetica.begin(), ejerciciosAritmetica.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                        ejerciciosLogica = obtenerEjerciciosFacilLogica();
                                                        shuffle(ejerciciosLogica.begin(), ejerciciosLogica.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                    } else if (dificultad == 2) {
                                                        ejerciciosAritmetica = obtenerEjerciciosIntermedioAritmetica();
                                                        shuffle(ejerciciosAritmetica.begin(), ejerciciosAritmetica.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                        ejerciciosLogica = obtenerEjerciciosIntermedioLogica();
                                                        shuffle(ejerciciosLogica.begin(), ejerciciosLogica.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                    } else if (dificultad == 3) {
                                                        ejerciciosAritmetica = obtenerEjerciciosDificilAritmetica();
                                                        shuffle(ejerciciosAritmetica.begin(), ejerciciosAritmetica.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                        ejerciciosLogica = obtenerEjerciciosDificilLogica();
                                                        shuffle(ejerciciosLogica.begin(), ejerciciosLogica.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
                                                    
                                                        
                                                    }
                                                   
                                                    for (auto* e : ejerciciosAritmetica) {
                                                        cout << "Ejercicio # " << (contador++) << endl;
                                                        e->mostrarEjercicio();
                                                        string resp;
                                                        do {
                                                            cout << "Tu respuesta: ";
                                                            getline(cin, resp);
                                                            if (resp.empty()) {
                                                                cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                            } else if (resp == "#") {
                                                                break;
                                                            }
                                                        } while (resp.empty());

                                                        if (resp == "#") {
                                                            break; // salir del bucle de ejercicios
                                                        } else if (e->validarRespuesta(resp)) {
                                                            cout << "Correcto!" << endl;
                                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                                        } else {
                                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                                        }

                                                    }
                                                    
                                                    for (auto* e : ejerciciosLogica) {
                                                        cout << "Ejercicio # " << (contador++) << endl;
                                                        e->mostrarEjercicio();
                                                        string resp;
                                                        do {
                                                            cout << "Tu respuesta: ";
                                                            getline(cin, resp);
                                                            if (resp.empty()) {
                                                                cout << "No puedes dejar la respuesta vacía. Intenta de nuevo." << endl;
                                                            } else if (resp == "#") {
                                                                break;
                                                            }
                                                        } while (resp.empty());

                                                        if (resp == "#") {
                                                            break; // salir del bucle de ejercicios
                                                        } else if (e->validarRespuesta(resp,true)) {
                                                            cout << "Correcto!" << endl;
                                                            usuario.getHistorial().agregarRespuestaCorrecta();
                                                        } else {
                                                            cout << "Incorrecto. La respuesta era: " << e->getRespuesta() << endl;
                                                            usuario.getHistorial().agregarRespuestaIncorrecta();
                                                        }

                                                    }

                                                    usuario.getHistorial().calcularPromedio();
                                                    usuario.getHistorial().guardarHistorial(usuario.getNombre());
                                                    for (auto* e : ejerciciosAritmetica) delete e;
                                                    for (auto* e : ejerciciosLogica) delete e;

                                                    } else {
                                                        cout << "Opcion no valida, intente de nuevo." << endl;
                                                    }

                                                    break; 
                                                }       

                                                case 2:
                                                cout << "Historial" << endl;
                                                cout << "Nombre de usuario: " << usuario.getNombre() << endl;
                                                cout << "Respuestas correctas: " << usuario.getHistorial().getRespuestasCorrectas() << endl;
                                                cout << "Respuestas incorrectas: " << usuario.getHistorial().getRespuestasIncorrectas() << endl;
                                                cout << "Promedio: " << usuario.getHistorial().getPromedio() << "%" << endl;

                                                                                                 
                                            
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