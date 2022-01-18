/******* Pr06_Carta.h ****************************************************/ /**
 *
 * @file Pr06_Carta.h
 *
 * Fichero de cabecera de la clase Carta
 *
 * @version 1.0
 * @author Gabriel Chaparro y Mar�a Navarro
 * @date 28/04/2018
 *  
 ***************************************************************************/
#ifndef _CARTA_H
#define _CARTA_H

#include<iostream>
using namespace std;

/**
 * @brief Clase para el manejo de Carta
 *
 * Clase para manejar la informacion de Carta.
 * Estan implementadas las operaciones basicas y se ha a�adido la sobrecarga
 * del operador '<<' para poder mostrar el contenido completo de la carta por
 * pantalla
 */
class Carta
{
    public:
        Carta(); //constructor
        void PutPalo(char); //asigna palo a la carta
        void PutNumero(int);//asigna n�mero a la cara
        char GetPalo(); //devuelve el palo de la carta
        int GetNumero(); //devuelve el n�mero de la carta
        
        //muestra por pantalla la carta seg�n formato PaloNumero
        friend ostream & operator << (ostream &, Carta);

    private:
        char palo; ///<'O'=oros, 'C'=copas, 'E'=espadas, 'B'=bastos
        int numero; ///<1..12
};



#endif
