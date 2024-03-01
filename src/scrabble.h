#ifndef __SCRABBLE__H__
#define __SCRABBLE__H__
#include <string>
using namespace std;


class Scrabble {
	public:
	void printinicilaizar(const string& nombre_archivo);
	void printiniciar_inverso();
    void printpalabras_por_prefijo();
    void printpalabras_por_sufijo();
    void printgrafo_de_palabras();
    void printposibles_palabras();
    void printayuda();

};

#include "Scrabble.hxx"

#endif
