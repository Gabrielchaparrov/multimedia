/*
 * @file test_arbol.cpp
 * @brief Programa de test de la Practica 5 de EDA (GIM).
 * 
 * Pruebas con arboles binarios de búsqueda
 * 
 * @author Gabriel Chaparro Villaescusa
 * @author María Navarro Silvestre
 * @date 21/10/2018
 * @version 1.0
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "abb.h"
#include "alumno.h"
#include <string>


using namespace std;

void prelab1(ABB&);

int main()
{
    ABB arbol;
    
    //Previo 1: Insercion e impresion de 10 alumnos
    cout << "****** PREVIO 1 ******" << endl;
    cout << "Altura arbol: " << arbol.GetAltura() << endl;
    
    prelab1(arbol);

    
    //Previo 2: Prueba del calculo del tamanyo
    cout << endl << endl << "****** PREVIO 2 ******" << endl << endl;
    
    cout << endl << "Tamanyo del arbol = " << arbol.GetTamanyo() << endl;;

    
    //Tarea 1: Impresion en inorden
    cout << endl << endl << "****** TAREA 1 ******" << endl << endl;
    
    arbol.Inorden(cout);

    
    //Tarea 2: Altura del ABB
    cout << endl << endl << "****** TAREA 2 ******" << endl << endl;
    
    cout << "Altura del arbol = " << arbol.GetAltura() << endl << endl;
	

    //Tarea 3 y 4: Busqueda por identificador con dos pruebas
    cout << endl << endl << "****** TAREA 3 ******" << endl << endl;
    arbol.BuscarSuperior(5705);
    
    cout << endl << endl << "****** TAREA 4 ******" << endl << endl;
    arbol.BuscarSuperior(40000);    //No muestra resultados
    
    cout << "No se muestran resultados";
    
    return EXIT_SUCCESS;
}


void prelab1(ABB& Arbol)
{
    for(int i = 0; i < 10; i++)
        {
            Alumno alumno(i);
            cout << alumno;
            
            Arbol.Insertar(alumno.GetId(), alumno);
        }
}
    
    
    
    
    
    
    
