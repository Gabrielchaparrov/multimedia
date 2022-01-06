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

/**
 *  @brief Aplicar algoritmo de Dijkstra para generar rutas de peso minimo
 *  @param[in] origen Inicio de las rutas
 *  @return Grafo dirigido que representa la solucion al problema
 */
Grafo Grafo::getRutaDijkstra (size_t origen)
{
    //Pesos de la ruta minima desde origen a todos los nodos (vector P del algoritmo)
    //Estado inicial = Pesos de rutas a infinito = maximo TipoPeso
    vector<TipoPeso> p_distancias( this->size(), numeric_limits<TipoPeso>::max() ); 
	
    //Nodos para los que ya se ha calculado una ruta (conj. B del algoritmo)
    //Estado inicial = Sin ruta para ningún nodo
    vector<bool> b_nodos (this->size(),false);
    
	size_t contador_nodos=0; //Contador de nodos con rutas, true en b_nodos
    
	//Arcos factibles en cada iteracion del algoritmo (conj. F del algoritmo)
    vector< pair<size_t,size_t> > arcos_factibles;
    
    //Grafo solucion, contiene solo arcos seleccionados y todos los nodos del grafo original
    Grafo solucion (this->size()); 
    
    //Peso de ruta origen-->origen = 0
    p_distancias[origen] = 0;
    //origen ya tiene ruta origen-->origen
    b_nodos[origen] = true;
    contador_nodos = 1;
    
    while ( contador_nodos < this->size() ) 
    {
		//Buscar arcos factibles
        arcos_factibles = Factibles(b_nodos);
        if ( arcos_factibles.size() > 0 )
        {
			//Seleccionar el mejor arco de los factibles
            pair<size_t,size_t> a;
            a = Seleccion (arcos_factibles,p_distancias);

			//Actualizar distancia/peso acumulado al destino del arco
            p_distancias[a.second] = p_distancias[a.first] + matriz[a.first][a.second];

			//Guardar el arco seleccionado en el Grafo solucion
            solucion(a.first,a.second) = matriz[a.first][a.second];
			
			//Indicar que el nodo destino del arco ya tiene una ruta
            b_nodos[a.second] = true;
			
			//Incrementar contador de nodos con ruta encontrada
            contador_nodos++;
        }
    }
    
    return solucion;
}

/**
* @brief Metodo auxiliar del algoritmo de Dijkstra.
* Busca el conjunto de arcos factibles en cada iteracion
* @param[in] b Conjunto de nodos que ya tienen una ruta
* @return Vector con los arcos (pares de nodos) que son factibles
*/
vector< pair<size_t,size_t> > Grafo::Factibles (vector<bool> b)
{
    vector< pair<size_t,size_t> > factibles;
    
    for(size_t i = 0; i < this->size(); i++)
    {
        if(b[i] == true)
        {        
            for(size_t j = 0; j < this->size(); j++)
            {                
                if(matriz[i][j] > PESO_MINIMO && b[j] == false)
                {
                    factibles.push_back( pair<size_t ,size_t> (i, j) ); 
                }
            }
        }
    }
        
    return factibles;
}

/**
* @brief Metodo auxiliar del algoritmo de Dijkstra.
* Seleccionar el mejor arco de un conjunto de arcos factibles
* @param[in] f Conjunto de arcos (pares de nodos) factibles
* @param[in] p Vector de pesos de las rutas obtenidas hasta este momento
* @return Arco seleccionado (indeterminado si f esta vacio)
*/
pair<size_t,size_t> Grafo::Seleccion (vector<pair<size_t,size_t>> f, vector<TipoPeso> p)
{
    pair<size_t,size_t> solucion;
    size_t actual = 0;
    
    for(size_t i = 1; i < f.size(); i++)
    {        
        if((matriz[f[i].first][f[i].second] + p[f[i].first]) < (matriz[f[actual].first][f[actual].second] + p[f[actual].first]))
        {
            actual = i;
        }
    }
    
    solucion.first = f[actual].first;
    solucion.second = f[actual].second;
    
    return solucion;
}







