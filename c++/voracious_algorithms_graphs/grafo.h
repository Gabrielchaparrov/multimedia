/**
 *  @file grafo.h
 *  @brief representacion de un grafo
 *  Practica 7 Programacion con Grafos
 *  Curso 2018-2019
 *
 *  @author Gabriel Chaparro y María Navarro
 *  @date 10/10/2018
 *  @version 1.0
 **/
 
# ifndef __GRAFO_H
# define __GRAFO_H

#include <vector>

using namespace std ;

//Tipo del peso de los arcos del grafo
typedef unsigned int TipoPeso; 

// Constante para marcar los arcos del grafo inexistentes
const TipoPeso PESO_MINIMO = 0;

class Grafo
{
    public :
        // Constructor, n=numero de nodos del grafo
        Grafo(size_t n);
        // Asignacion y consulta de arco dirigido entre dos nodos
        TipoPeso & operator()(size_t origen, size_t destino);
        // Consulta de arco dirigido entre dos nodos para objetos constantes
        const TipoPeso & operator()(size_t origen, size_t destino) const;
        // Numero de nodos del grafo
        size_t size() const;
        // Imprimir grafo (matriz)
        void print() const;
        // Asignacion de arco no dirigido entre dos nodos
        void addArcoNoDirigido(size_t origen, size_t destino, TipoPeso peso);
        // Nodo conectado con arco de menor peso con origen
        size_t conexionMinima(size_t origen) const;
        // Generar grafo no dirigido con peso aleatorio en un rango
        void generarGrafoNoDirigido(TipoPeso min, TipoPeso max);
        
        Grafo getRutaDijkstra (size_t origen);
        
    private :
        // Matriz de adyacencia del grafo .
        vector< vector<TipoPeso> > matriz;
        // Establece arco no dirigido entre dos nodos con peso aleatorio en un rango
        TipoPeso addArcoNoDirigidoAleatorio(size_t origen, size_t destino, TipoPeso min, TipoPeso max);
        
        vector< pair<size_t,size_t> > Factibles (vector<bool> b);
        pair<size_t,size_t> Seleccion ( vector<pair<size_t,size_t>> f, vector<TipoPeso> p);
           
};

# endif
