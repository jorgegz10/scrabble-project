#include "Scrabble.h"
#include <iostream>
#include <string>
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
    // Agrega aquí más comandos si es necesario
};

void printinicilaizar() {
    cout << "Inicializando..." << endl;
}

void printiniciar_inverso() {
    cout << "Iniciando inverso..." << endl;
}

void printpalabras_por_prefijo() {
    cout << "Buscando palabras por prefijo: " << endl;
}

void printpalabras_por_sufijo() {
    cout << "Buscando palabras por sufijo: " << endl;
}

void printgrafo_de_palabras() {
    cout << "Generando grafo de palabras..." << endl;
}

void printposibles_palabras() {
    cout << "Buscando posibles palabras..." << endl;
}

void printayuda() {
    // Mostrar lista de comandos disponibles
    cout << "Lista de comandos disponibles:" << endl;
    for (int i = 0; i < sizeof(comando) / sizeof(comando[0]); i++) {
        cout << comando[i] << endl;
    }
}
