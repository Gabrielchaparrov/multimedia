/******* Pr6_Carta.cpp **************************************************/ /**
 *
 * @file Pr6_Carta.cpp
 *
 * Implementación de los métodos de la clase Carta
 *
 * @version 1.0
 * @author Gabriel Chaparro y María Navarro
 * @date 28/04/2018
 *  
 ***************************************************************************/
#include<iostream>
using namespace std;

#include "Pr06_Carta.h"

/*** Carta::Carta() ****************************************************/ /**
 *
 *  Inicia la carta con valores nulos
 *
 */ /**********************************************************************/
Carta::Carta()
{
    palo = ' ';
    numero = 0;
}

/*** int Carta::GetNumero() ****************************************************/ /**
 *
 *  Devuelve el número de la carta.
 *
 *  @return El número de la carta.
 *
 */ /**********************************************************************/
int Carta::GetNumero()
{
    return numero;
}

/*** char Carta::GetPalo() ****************************************************/ /**
 *
 *  Devuelve el palo de la carta.
 *
 *  @return El palo de la carta.
 *
 */ /**********************************************************************/
char Carta::GetPalo()
{
    return palo;
}

/*** void Carta::PutNumero(int) ****************************************************/ /**
 *
 *  Escribe el nuevo numero
 *
 *  @param [in]  n  El nuevo numero.
 *
 */ /**********************************************************************/
void Carta::PutNumero(int n)
{
    numero = n;
}

/*** void Carta::PutPalo(char) ****************************************************/ /**
 *
 *  Escribe el nuevo palo
 *
 *  @param [in]  p  El nuevo palo.
 *
 */ /**********************************************************************/
void Carta::PutPalo(char p)
{
    palo = p;
}

/*** ostream & operator << (ostream &, Carta) ********************/ /**
 *
 *  Sobrecarga del operador '<<' para llevar al stream de salida la
 *  informacion de todo el contenido de la carta
 *
 *  @return  El stream modificado
 *
 */ /**********************************************************************/
ostream & operator << (ostream &out, Carta c)
{
    out << c.GetNumero() << c.GetPalo();
    
    return out;
}







