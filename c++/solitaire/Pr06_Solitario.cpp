/******* Pr06_Solitario.cpp **************************************************/ /**
 *
 * @file Pr06_Solitario.cpp
 *
 * Implementación de los métodos de la clase Solitario
 *
 * @version 1.0
 * @author Gabriel Chaparro y María Navarro
 * @date 28/04/2018
 *  
 ***************************************************************************/
#include<cstdlib>
#include<ctime>

#include "Pr06_Solitario.h"

/*** Solitario::Solitario() ****************************************************/ /**
 *
 *  Crea las cartas necesarias para jugar
 *
 */ /**********************************************************************/
Solitario::Solitario()
{
    char palo;
    Carta aux;
    v_pilas.reserve(13);    
    
    for(int i = 0; i < 4; i++)
    {
        switch(i)
        {
            case 0:
                palo = 'O';
                break;
            case 1:
                palo = 'C';
                break;
            case 2:
                palo = 'E';
                break;
            case 3:
                palo = 'B';
                break;
        }

        for(int j = 1; j < 13; j++ )
        {
            aux.PutPalo(palo);
            aux.PutNumero(j);
            
            //cout << aux.GetNumero() << " " << palo << endl;
            
            v_pilas[0].Apilar(aux);
        }
    }
}

/*** void Solitario::IniciarJuego() ****************************************************/ /**
 *
 *  Mueve las cartas a la baraja auxiliar y pone una en cada mazo.
 *
 */ /**********************************************************************/
void Solitario::IniciarJuego()
{
    Carta aux;
    
    for(int i = 1; i < 13; i++)
    {
        while(!v_pilas[i].PilaVacia())
        {
            v_pilas[i].CimaPila(aux);
            v_pilas[0].Apilar(aux);
            v_pilas[i].Desapilar();
        }
    }
    
    Barajar();
    
    
    for(int i = 1; i < 8; i++)
    {
        v_pilas[0].CimaPila(aux);
        v_pilas[i].Apilar(aux);
        v_pilas[0].Desapilar();
    }
    
    Sacar5Mas();
    
    //MostrarTapete();
    
    
}

/*** void Solitario::Barajar() ****************************************************/ /**
 *
 *  Baraja las cartas usando numeros aleatorios.
 *
 */ /**********************************************************************/
void Solitario::Barajar()
{
    srand (time (NULL) );

    vector<Carta> v_aux;
    Carta carta;
    size_t pos_1, pos_2, pos;
    
    while (v_pilas[0].CimaPila (carta) )
    {
        v_aux.push_back (carta);
        v_pilas[0].Desapilar ();
    }
    for (unsigned int i = 0; i < 1000; i++)
    {
        pos_1 = rand () % v_aux.size ();
        pos_2 = rand () % v_aux.size ();
        carta = v_aux[pos_1];
        v_aux[pos_1] = v_aux[pos_2];
        v_aux[pos_2] = carta;
    }
    
    for (pos = 0; pos < v_aux.size (); pos++)
        v_pilas[0].Apilar (v_aux[pos]);

    return;
}

/*** void Solitario::MoverCarta() ****************************************************/ /**
 *
 *  Realiza el cambio de posición de la carta del tapete introducido.
 *
 */ /**********************************************************************/
void Solitario::MoverCarta()
{
    int num_pila, num_pilafin;
    Carta aux;
    
    cout << "Introduce la pila de la carta que desea mover: " << endl;
    cin >> num_pila;
    cout << "Introduce la pila a la que desea mover la carta: " << endl;
    cin >> num_pilafin;
    
    if (Validar(num_pila, num_pilafin))
    {
        v_pilas[num_pila].CimaPila(aux);
        v_pilas[num_pilafin].Apilar(aux);
        v_pilas[num_pila].Desapilar();
    }
    else
        cout << endl << "* * MOVIMIENTO NO VALIDO * *" << endl << endl;;

                
}

/*** void Solitario::Sacar5Mas() ****************************************************/ /**
 *
 *  Mueve 5 cartas a la baraja auxiliar.
 *
 */ /**********************************************************************/
void Solitario::Sacar5Mas()
{
    Carta aux;
    int cont = 0;
    
    if(v_pilas[0].PilaVacia())
    {
        while(!v_pilas[12].PilaVacia())
        {
            v_pilas[12].CimaPila(aux);
            v_pilas[0].Apilar(aux);
            v_pilas[12].Desapilar();
        }
    }
    
    while(!v_pilas[0].PilaVacia() && cont < 5)
    {
        v_pilas[0].CimaPila(aux);
        v_pilas[12].Apilar(aux);
        v_pilas[0].Desapilar();
        cont++;
    }
    
}

/*** bool Solitario::JuegoFinalizado() ******************************************/ /**
 *
 *  Nos dice si el juego ha acabado
 *
 *  @retval  True  Ha acabado
 *  @retval  False  No ha acabado
 *
 */ /**********************************************************************/
bool Solitario::JuegoFinalizado()
{
    int cont = 0;
    bool flag = false;
    
    for(int i = 0; i <= 7; i++)
    {
        if(v_pilas[i].PilaVacia())
            cont++;
    }

    if(v_pilas[12].PilaVacia())
        cont++;

    if(cont == 9)
        flag = true;


    return flag;
}

/*** void Solitario::MostrarTapete() ****************************************************/ /**
 *
 *  Muestra el tapete completo
 *
 */ /**********************************************************************/
void Solitario::MostrarTapete()
{
    cout << "TAPETE" << endl;
    cout << "===============================" << endl;
    cout << "(01) Mazo1: " << v_pilas[1] << endl;
    cout << "(02) Mazo2: " << v_pilas[2] << endl;
    cout << "(03) Mazo3: " << v_pilas[3] << endl;
    cout << "(04) Mazo4: " << v_pilas[4] << endl;
    cout << "(05) Mazo5: " << v_pilas[5] << endl;
    cout << "(06) Mazo6: " << v_pilas[6] << endl;
    cout << "(07) Mazo7: " << v_pilas[7] << endl;
    cout << "===============================" << endl;
    cout << "(08) Palo1: " << v_pilas[8] << endl;
    cout << "(09) Palo2: " << v_pilas[9] << endl;
    cout << "(10) Palo3: " << v_pilas[10] << endl;
    cout << "(11) Palo4: " << v_pilas[11] << endl;
    cout << "===============================" << endl;
    cout << "(12) Auxiliar: " << v_pilas[12] << endl;
    cout << "(00) Baraja: " << v_pilas[0] << endl;
}

/*** bool Solitario::Validar(int, int) ******************************************/ /**
 *
 *  Nos dice si el movimiento es válido
 *
 *  @param [in]  num_pila  La pila inicial.
 *
 *  @param [in]  num_pilafin  La pila final.
 *
 *  @retval  True  Es valido
 *  @retval  False  No es valido
 *
 */ /**********************************************************************/
bool Solitario::Validar(int num_pila, int num_pilafin)
{
    Carta ini, fin, aux;
    bool valido = false;
    
    v_pilas[num_pila].CimaPila(ini);
    v_pilas[num_pilafin].CimaPila(fin);
    
    if(num_pila != 0 && ini.GetNumero() != 0)
    {    
        if(num_pilafin >= 8 && num_pilafin <= 11)
        {
            if(ini.GetPalo() == fin.GetPalo() && ini.GetNumero() == (fin.GetNumero() + 1))
            {
                valido = true;
            }
            
            else if(v_pilas[num_pilafin].PilaVacia())
            {
                if(ini.GetNumero() == 1)
                {
                    valido = true;
                }
            }
        }
        
        else if(num_pilafin >= 1 && num_pilafin <= 7)
        {
            if(ini.GetPalo() != fin.GetPalo() && fin.GetNumero() == (ini.GetNumero() + 1))
            {
                valido = true;
            }
            
            else if(v_pilas[num_pilafin].PilaVacia())
            {
                valido = true;
            }
        }            
    }

    return (valido);

}














