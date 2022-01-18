/******* Pr06_Solitario.h ****************************************************/ /**
 *
 * @file Pr06_Solitario.h
 *
 * Fichero de cabecera de la clase Solitario
 *
 * @version 1.0
 * @author Gabriel Chaparro y María Navarro
 * @date 28/04/2018
 *  
 ***************************************************************************/
#ifndef _SOLITARIO_H
#define _SOLITARIO_H

#include "Pr06_Pila.h"
#include "Pr06_Carta.h"

#include<vector>

/**
 * @brief Clase para el manejo de Solitario
 *
 * Clase para manejar la informacion de Solitario.
 * 
 */
class Solitario
{
    public:
        
        // Constructores
        Solitario();
        
        //Modifican el solitario
        void IniciarJuego();
        void MoverCarta();
        void Sacar5Mas();
        bool JuegoFinalizado();
        void MostrarTapete();


    private:
        vector<Pila> v_pilas; ///< Vector con las pilas de cartas
        
        //Funciones auxiliares
        void Barajar();
        bool Validar(int, int);
};



#endif
