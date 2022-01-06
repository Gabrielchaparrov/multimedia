/*
 * @file Tabla.cpp
 * @brief Material de la Practica 6 de EDA (GIM).
 * 
 * Implementación de la clase Tabla
 *
 * @author Gabriel Chaparro Villaescusa
 * @author Maria Navarro Silvestre
 * @date 19/11/2018
 * @version 1.0
 */

#include "tabla.h"
#include<iostream>

using namespace std;

/** 
* Constructor con argumentos
*  @param [in] tam tamaño de la tabla
*/
Tabla::Tabla(size_t tam)
{
    t.resize(tam);
    colisiones = 0;
    elementos = 0;
}

/** 
* Inserta un dato
* 
* @param [in]  clave la clave
* @param [in]  p puntero a una función miembro Hash
*/
void Tabla::Insertar(const TipoClave & clave, TipoHash p )
{    
    size_t indice;
    indice = (this->*p)(clave);

    if(!t[indice].empty())
        colisiones++;

    if(!Buscar(clave,p))
    {
        t[Hash1(clave)].push_back(clave);
        elementos++;
    }
    
}

/** 
* Busca un dato dado la clave
* 
* @param [in]  clave la clave
* @param [in]  p puntero a una función miembro Hash
* @return verdadero encontrado
*/
bool Tabla::Buscar(TipoClave clave, TipoHash p) const
{
    size_t indice;
    size_t j = 0;
    bool encontrado = false;
    
    indice = (this->*p)(clave);
    
    while (j < t[indice].size() && !encontrado)
       if (t[indice][j] == clave)
           encontrado = true;
       else
        	j++;
        
    return encontrado;
}

/** 
* Muestra la tabla
* 
* @param [in]  sal flujo de salida
*/
void Tabla::Mostrar(ostream & sal) const
{
    for(size_t i = 0; i < t.size(); i++)
    {
        sal << i << ":" << t[i].size() << ":" ;
        for(unsigned j = 0; j < t[i].size(); j++)
            sal << t[i][j] << "-";
        sal << endl;
    }
}

/** 
* Funcion Hash1
* 
* @param [in]  clave la clave
* @return indice en la tabla
*/
size_t Tabla::Hash1(TipoClave clave) const
{
    size_t suma = 0;
    
    for(unsigned int i = 0; i < clave.length(); i++)    
        suma = suma + clave[i];
    
    return suma % t.size();
}

/** 
* Funcion Hash2
* 
* @param [in]  clave la clave
* @return indice en la tabla
*/
size_t Tabla::Hash2(TipoClave clave) const
{
    size_t suma = 0;
    
    for(unsigned int i = 0; i < clave.length(); i++)    
        suma = (suma << 1) + clave[i];
    
    return suma % t.size();
}

/*** int Tabla::ObtenFactorCarga() ************************************/ /**
 *
 *  Devuelve el factor de carga
 *
 *  @return  El factor de carga
 *
*/ /************************************************************************/
int Tabla::ObtenFactorCarga()
{
    return elementos / t.size();
}

/*** int Tabla::ObtenNColisiones() ************************************/ /**
 *
 *  Devuelve el numero de colisiones
 *
 *  @return  Numero de colisiones
 *
*/ /************************************************************************/
int Tabla::ObtenNColisiones()
{
    return colisiones;
}









