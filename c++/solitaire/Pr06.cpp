/******* Pr06.cpp ***************************************************/ /**
 *
 * @file Pr06.cpp
 * @brief Prácticas de Programacion. Práctica 6.
 *
 * @version 1.0
 * @author Gabriel Chaparro y María Navarro
 * @date 28/04/2018
 *  
 ***************************************************************************/
#include<string>
#include<iostream>
using namespace std;

#include "Pr06_Solitario.h"
#include "Pr06_Pila.h"
#include "Pr06_Carta.h"

/*
 * Programa principal.
 */
int main()
{
    Solitario partida;
    int opcion = 0;
    partida.IniciarJuego();
    char seguir;
    
    while(opcion != 4)
    {
        partida.MostrarTapete();
        
        cout << endl << "* * * MENU * * *" << endl;
        cout << "1. Mover una carta." << endl;
        cout << "2. Sacar 5 mas de la baraja." << endl;
        cout << "3. Iniciar un nuevo juego." << endl;
        cout << "4. Finalizar el juego" << endl;
        
        cin >> opcion;
        
        switch(opcion)
        {
            case 1:
                partida.MoverCarta();
                break;
            case 2:
                partida.Sacar5Mas();
                break;
            case 3:
                partida.IniciarJuego();
                break;
        }
        
        if(partida.JuegoFinalizado())
        {
            partida.MostrarTapete();
            
            cout << endl << "*******HAS GANADO*******" << endl << endl;
            cout << "Desea iniciar una nueva partida? (s/n)" << endl;
            cin >> seguir;
            
            if(seguir == 's')
                partida.IniciarJuego();
            else
                opcion = 4;
        }
        
    }
    
}
