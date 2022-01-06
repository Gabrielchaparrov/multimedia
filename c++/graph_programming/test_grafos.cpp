/**
 *  @file test_grafos.cpp
 *  @brief Funcion para probar la clase grafo
 *  Practica 7 Programacion con Grafos
 *  Curso 2018-2019
 *
 *  @author Gabriel Chaparro y María Navarro
 *  @date 10/10/2018
 *  @version 1.0
 **/

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <limits>
#include "grafo.h"
 
using namespace std;

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
void GenerarGrafoGuion(Grafo &);
void ConexionesMinimas (const Grafo &); 

/*
 * Programa principal.
 */
int main() 
{
    srand(time(NULL));
    
    cout << "* Tarea 1: Definicion e impresion del grafo de ejemplo *" << endl << endl;
    Grafo grafo_guion(8);
    GenerarGrafoGuion (grafo_guion);
    grafo_guion.print();
    
    cout << endl << "* Tarea 2: Conexiones minimas del grafo de ejemplo *" << endl << endl;
    ConexionesMinimas (grafo_guion);  
  
    cout << endl << "* Tarea 3: Grafo aleatorio de tamaño 10 *" << endl << endl;
    Grafo test_grafo10(10);
    test_grafo10.generarGrafoNoDirigido(1, 100);
	test_grafo10.print();
	
    cout << endl << "* Conexiones minimas del grafo aleatorio *" << endl << endl;
    ConexionesMinimas (test_grafo10);

   return EXIT_SUCCESS;
 }

/*** void GenerarGrafoGuion(Grafo & grafo) ************************************/ /**
 *
 *  Genera un grafo similar al del guion de la practica
 *
 *  @param [in]  grafo  El grafo sobre el cual se crean los nodos y arcos del guion
 *
*/ /************************************************************************/
void GenerarGrafoGuion(Grafo & grafo)
{
    try
    {
        grafo.addArcoNoDirigido(0,1,3);
        grafo.addArcoNoDirigido(0,2,5);
        grafo.addArcoNoDirigido(0,3,2);
        grafo.addArcoNoDirigido(0,7,10);
        
        grafo.addArcoNoDirigido(1,2,5);
        grafo.addArcoNoDirigido(1,3,8);
        grafo.addArcoNoDirigido(1,4,8);
        grafo.addArcoNoDirigido(1,6,6);
        grafo.addArcoNoDirigido(1,7,6);
        
        grafo.addArcoNoDirigido(2,4,1);
        grafo.addArcoNoDirigido(2,5,7);
        grafo.addArcoNoDirigido(2,6,9);
        
        grafo.addArcoNoDirigido(3,4,12);
        grafo.addArcoNoDirigido(3,7,14);
        
        grafo.addArcoNoDirigido(4,6,15);
        
        grafo.addArcoNoDirigido(5,7,9);
        
        grafo.addArcoNoDirigido(6,7,3);
    }
    catch(out_of_range e)
    {
        cout << e.what() << endl;
    }
}

/*** void ConexionesMinimas (const Grafo & grafo) ************************************/ /**
 *
 *  Muestra para cada nodo el nodo destino cuyo arco tiene el menor peso
 *
 *  @param [in]  grafo  Grafo en el que se ejecuta la funcion
 *
*/ /************************************************************************/
void ConexionesMinimas (const Grafo & grafo)
{
    size_t min;
    
    for(size_t i = 0; i < grafo.size(); i++)
    {
        min = grafo.conexionMinima(i);
        
        cout << "Nodo " << i << " => Nodo " << min << endl; 
        
    }
}






















