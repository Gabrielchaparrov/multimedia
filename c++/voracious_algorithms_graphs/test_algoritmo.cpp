/**
 *  @file test_algoritmo.cpp
 *  @brief Funcion para probar el algoritmo de Dijkstra
 *  Practica 8 Algoritmos Voraces con Grafos
 *  Curso 2018-2019
 *
 *  @author Gabriel Chaparro y María Navarro
 *  @date 10/12/2018
 *  @version 1.0
 **/

#include "grafo.h"
#include <iostream>
#include <stack>

using namespace std;

Grafo generarGrafoInicial()
{
    Grafo g(7);
    
    g.addArcoNoDirigido(0, 1, 32);
    g.addArcoNoDirigido(0, 2, 43);
    g.addArcoNoDirigido(0, 3, 28);
    
    g.addArcoNoDirigido(1, 0, 32);
    g.addArcoNoDirigido(1, 4, 42);
    
    g.addArcoNoDirigido(2, 0, 43);
    g.addArcoNoDirigido(2, 4, 26);
    
    g.addArcoNoDirigido(3, 0, 28);
    g.addArcoNoDirigido(3, 5, 64);

    g.addArcoNoDirigido(4, 1, 42);
    g.addArcoNoDirigido(4, 2, 26);
    g.addArcoNoDirigido(4, 5, 33);
    g.addArcoNoDirigido(4, 6, 71);
    
    g.addArcoNoDirigido(5, 3, 64);
    g.addArcoNoDirigido(5, 4, 33);
    g.addArcoNoDirigido(5, 6, 28);
    
    g.addArcoNoDirigido(6, 4, 71);
    g.addArcoNoDirigido(6, 5, 28);
    
    return g;    
}

void mostrarRutaDijkstra (Grafo g, size_t origen, size_t destino)
{
    cout << "Ruta desde " << origen << " hasta " << destino << ":" << endl;
    
    stack <size_t> pila; 
    pila.push(destino);
    TipoPeso peso = 0;
    
    while(origen != destino)
    {
        for(size_t i = 0; i < g.size(); i++)
        {
            if(g(i, destino) != 0)
            {
                peso += g(i, destino);
                pila.push(i);
                destino = i;
            }
        }
    }
    
    cout << pila.top();
    pila.pop();
    while(!pila.empty())
    {
        cout << " ---> " << pila.top();
        pila.pop();
    }
    
    cout << endl << "Peso total de la ruta = " << peso;
}

int main() 
{
    Grafo g = generarGrafoInicial();
    Grafo rutas(g.size());
    size_t destino;

/* Verificar Tarea 1 */
    cout << "Grafo inicial" << endl;
    cout << "-------------------" << endl;
    g.print();

/* Verificar Tarea 2 */
    cout << endl << "Grafo dirigido de Dijkstra desde nodo 0" << endl;
    cout << "-------------------" << endl;
    rutas = g.getRutaDijkstra(0);
    rutas.print();
    
/* Verificar Tarea 3 */
    cout << "-------------------" << endl;
    cout << "Mostrar ruta de menor coste desde 0." << endl;
    cout << "\tNodo destino:";
    cin >> destino;
    mostrarRutaDijkstra(rutas,0,destino);
        
    return 0;
}




