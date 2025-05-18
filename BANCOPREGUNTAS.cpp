#include <iostream>
#include <vector>

using namespace std;


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
