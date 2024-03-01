#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include "scrabble.h"
using namespace std;


int main()
{
    
    vector<string> comando = {"inicializar", "diccionario.txt", "iniciar_inverso", "puntaje_palabra", "iniciar_arbol", "iniciar_arbol_inverso", "palabras_por_prefijo prefijo", "palabras_por_sufijo sufijo", "grafo_de_palabras", "posibles_palabras", "salir", "ayuda"};
    string input;
    do
    {
        cout << "$ "; // Indicador
        getline(cin, input);
        vector<string> tokens; // Tokenizar
        int pos = 0;
        while ((pos = input.find(" ")) != string::npos)
        {
            tokens.push_back(input.substr(0, pos));
            input.erase(0, pos + 1);
        }
        tokens.push_back(input);
        if (tokens[0] == "inicializar")
        {
            // Función para inicializar
           printinicilaizar(tokens[1]);
        }
        else if (tokens[0] == "iniciar_inverso")
        {
            // Función para iniciar inverso
            printiniciar_inverso(tokens[1]);
        }
        else if (tokens[0] == "puntaje_palabra")
        {
            int puntaje = puntaje_palabra();
            cout << "El puntaje de la palabra es: " << puntaje << endl;
        }
        else if (tokens[0] == "palabras_por_prefijo")
        {
            // Función para palabras por prefijo
            printpalabras_por_prefijo();
        }
        else if (tokens[0] == "palabras_por_sufijo")
        {
            // Función para palabras por sufijo
            printpalabras_por_sufijo();
        }
        else if (tokens[0] == "grafo_de_palabras")
        {
            // Función para grafo de palabras
            printgrafo_de_palabras();
        }
        else if (tokens[0] == "posibles_palabras")
        {
            // Función para posibles palabras
            printposibles_palabras();
        }
        else if (tokens[0] == "ayuda")
        {
            // Mostrar lista de comandos disponibles
            printayuda();
        }
    } while (input != "salir");

    cout << "Saliendo de la interfaz..." << endl;

    return 0;
}
