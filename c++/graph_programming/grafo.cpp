/**
 *  @file grafo.cpp
 *  @brief Funciones para representar el grafo.
 *  Practica 7 Programacion con Grafos
 *  Curso 2018-2019
 *
 *  @author Gabriel Chaparro y María Navarro
 *  @date 10/10/2018
 *  @version 1.0
 **/
#include "grafo.h"
#include <stdlib.h>
#include <iostream>
#include <limits>
#include <vector>
#include <ctime>
#include <assert.h>

using namespace std;

/**
 *  @brief Crea una instancia del grafo de dimension n
 *  @param[in] Dimension del grafo (numero de nodos)
 *  @post Inicializa todos los pesos a 0
 **/
Grafo::Grafo(size_t n)
{
    assert(n > 0);
    matriz.resize(n); //dimensionar filas
    for (size_t i = 0; i < matriz.size() ; i++)
        matriz[i].resize(n,PESO_MINIMO); //dimensionar columnas e inicializar a peso = 0
}

/**
 *  @brief Sobrecarga del operador () para devolver (modificable) el peso 
 *  de un arco del grafo   
 *  @param origen Inicio del arco, fila de la matriz
 *  @param destino Final del arco, columna de la matriz
 *  @return Referencia al peso del arco (origen,destino)
 */
TipoPeso & Grafo::operator()(size_t orig, size_t dest)
{
    return matriz.at(orig).at(dest); 
}

/**
 *  @brief Sobrecarga del operador () para devolver el peso 
 *  de un arco del grafo. El grafo es const y valor devuelto tambien.
 *  @param origen Inicio del arco, fila de la matriz
 *  @param destino Final del arco, columna de la matriz
 *  @return Referencia al peso del arco (origen,destino)
 */
const TipoPeso & Grafo::operator()(size_t orig, size_t dest) const
{
    return matriz.at(orig).at(dest); 
}

/**
 *  @brief Devuelve la dimension del grafo 
 *  @return numero de nodos del grafo
 */
size_t Grafo::size() const
{
    return matriz.size();
}

/**
 *  @brief Muestra la matriz del grafo por pantalla
 */
void Grafo::print() const
{    
    for(size_t i = 0; i < (*this).size(); i++)
    {
        cout << "Nodo " << i << ": ";
        
        for(size_t j = 0; j < (*this).size(); j++)
        {
            if((*this)(i, j) != 0)
            {
                cout << "(" << i << "," << j << "):" << (*this)(i, j) << " ";
            }
                
        }
        
        cout << endl;
    }
}

/**
 * @brief Establece arco no dirigido desde origen a destino con un peso
 * @param origen Inicio del arco
 * @param destino Final del arco
 * @param peso Peso del arco
 */
void Grafo::addArcoNoDirigido(size_t origen, size_t destino, TipoPeso peso)
{    
    (*this)(origen,destino) = peso;
    (*this)(destino,origen) = peso;
}

/**
 *  @brief Devuelve el nodo conectado con arco de menor peso con origen
 *  @param[i] origen Nodo a inspeccionar
 *  @return  Nodo conectado con origen con arco de peso minimo
 */
size_t Grafo::conexionMinima(size_t origen) const
{
    TipoPeso menor = numeric_limits<TipoPeso>::max();
    size_t resultado;
    
    for(size_t i = 0; i < (*this).size(); i++)
    {
        if(((*this)(origen, i) < menor) && ((*this)(origen, i) != 0))
        {
            resultado = i;
            menor = ((*this)(origen, i));
        }
    }
    
    return resultado;
}

/**
 *  @brief Genera un grafo no dirigido aleatorio cuyos arcos tienen pesos 
 *  entre min y max incluidos
 *  @param[in] min Valor minimo para el peso de un arco
 *  @param[in] max valor maximo para el peso de un arco
 */
void Grafo::generarGrafoNoDirigido(TipoPeso min, TipoPeso max) 
{   
    size_t tamanyo = (*this).size();

    for(size_t i = 0; i < tamanyo; i++)
    {
        size_t num_arcos = 1 + rand() % ((tamanyo-1) - 1);   // Entre 1 y el tamaño, para asegurar que siempre haya arco
        
        for(size_t j = 0; j < num_arcos; j++)
        {
            size_t destino = 1 + rand() % ((tamanyo-1) - 0);
            
            (*this).addArcoNoDirigidoAleatorio(i, destino, min, max);
        }
    }
}

/**
 *  @brief Establece un nuevo arco no dirigido entre dos nodos con peso aleatorio
 *  @param[in] origen Inicio del arco
 *  @param[in] destino Final del arco
 *  @param[in] min Peso minimo
 *  @param[in] max Peso maximo
 *  @return Peso del arco generado
 */
TipoPeso Grafo::addArcoNoDirigidoAleatorio(size_t origen, size_t destino, TipoPeso min, TipoPeso max)
{
    TipoPeso peso;
    
    peso = 1 + rand() % (max - min);
    
    (*this)(origen, destino) = peso;
    
    return peso;    
}

