#include "Scrabble.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

// Definición del arreglo de comandos
string comando[] = {
    "inicializar",
    "iniciar inverso",
    "palabras por prefijo",
    "palabras por sufijo",
    "grafo de palabras",
    "posibles palabras",
    "ayuda",
};
stack<string> diccionario;
struct PuntuacionLetra {
    char letra;
    int puntaje;
};

void crearArchivoSiNoExiste(const string &nombre_archivo)
{
    ifstream file(nombre_archivo);
    if (!file.is_open())
    {
        ofstream nuevoArchivo(nombre_archivo);
        nuevoArchivo.close();
        cout << "Se ha creado el archivo " << nombre_archivo << endl;
    }
    else
    {
        cout << "El archivo " << nombre_archivo << " ya existe." << endl;
    }
}
void printinicilaizar(const string &nombre_archivo)
{
    cout << "Inicializando..." << endl;
    ifstream file(nombre_archivo);

    if (!file.is_open())
    {
        cout << "El archivo " << nombre_archivo << " no existe o no puede ser leído." << endl;
        crearArchivoSiNoExiste(nombre_archivo);
        return;
    }

    string palabra;
    while (file >> palabra)
    {
        // Verificar si la palabra contiene símbolos inválidos
        bool valida = all_of(palabra.begin(), palabra.end(), [](char c)
                             { return isalpha(c); });
        if (valida)
        {
            diccionario.push(palabra);
        }
    }
    file.close();

    cout << "El diccionario se ha inicializado correctamente." << endl;
}

void printiniciar_inverso(const string &nombre_archivo)
{
    cout << "Iniciando inverso..." << endl;
    ifstream file(nombre_archivo);
    if (!file.is_open())
    {
        cout << "El archivo " << nombre_archivo << " no existe o no puede ser leído." << endl;
        crearArchivoSiNoExiste(nombre_archivo);
        return;
    }

    string palabra;
    while (file >> palabra)
    {
        // Verificar si la palabra contiene símbolos inválidos
        bool valida = all_of(palabra.begin(), palabra.end(), [](char c)
                             { return isalpha(c); });
        if (valida)
        {
            reverse(palabra.begin(), palabra.end());
            diccionario.push(palabra);
        }
    }
    file.close();

    cout << "El diccionario inverso se ha inicializado correctamente." << endl;
}

int puntaje_palabra() {
    string palabra;
    cout << "Ingrese la palabra: ";
    cin >> palabra;

    // Lista de puntuaciones de letras
    list<PuntuacionLetra> puntuaciones = {
        {'a', 1}, {'b', 3}, {'c', 3}, {'d', 2}, {'e', 1}, {'f', 4}, {'g', 2}, {'h', 4}, {'i', 1}, {'j', 8},
        {'k', 5}, {'l', 1}, {'m', 3}, {'n', 1}, {'o', 1}, {'p', 3}, {'q', 10}, {'r', 1}, {'s', 1}, {'t', 1},
        {'u', 1}, {'v', 4}, {'w', 4}, {'x', 8}, {'y', 4}, {'z', 10}
    };

    // Verificar si la palabra existe en el diccionario original o inverso
    bool palabra_valida = false;
    stack<string> temp = diccionario; // Supongo que diccionario es una variable global
    while (!temp.empty()) {
        if (temp.top() == palabra || temp.top() == palabra) {
            palabra_valida = true;
            break;
        }
        temp.pop();
    }

    if (!palabra_valida) {
        cout << "La palabra no existe en el diccionario." << endl;
        return 0;
    }

    // Verificar si la palabra contiene símbolos inválidos
    bool valida = all_of(palabra.begin(), palabra.end(), [](char c) { return isalpha(c); });
    if (!valida) {
        cout << " La palabra contiene símbolos inválidos." << endl;
        return 0;
    }

    int puntaje = 0;
    for (char letra : palabra) {
        // Convertir la letra a minúscula (el puntaje es caso insensible)
        letra = tolower(letra);
        // Buscar la puntuación de la letra en la lista de puntuaciones
        for (const auto& puntuacion : puntuaciones) {
            if (puntuacion.letra == letra) {
                puntaje += puntuacion.puntaje;
                break;
            }
        }
    }

    cout << "La palabra tiene un puntaje de " << puntaje << "." << endl;
    return puntaje;
}

void printpalabras_por_prefijo()
{
    cout << "Buscando palabras por prefijo: " << endl;
}

void printpalabras_por_sufijo()
{
    cout << "Buscando palabras por sufijo: " << endl;
}

void printgrafo_de_palabras()
{
    cout << "Generando grafo de palabras..." << endl;
}

void printposibles_palabras()
{
    cout << "Buscando posibles palabras..." << endl;
}

void printayuda()
{
    // Mostrar lista de comandos disponibles
    cout << "Lista de comandos disponibles:" << endl;
    for (int i = 0; i < sizeof(comando) / sizeof(comando[0]); i++)
    {
        cout << comando[i] << endl;
    }
}
