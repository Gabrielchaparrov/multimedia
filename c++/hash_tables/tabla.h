/*
 * @file tabla.h
 * @brief Material de la Practica 6 de EDA (GIM).
 * 
 * Archivo de cabecera de la clase Tabla
 *
 * @author Gabriel Chaparro Villaescusa
 * @author Maria Navarro Silvestre
 * @date 19/11/2018
 * @version 1.0
 */

#ifndef _TABLA_H
#define _TABLA_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** 
 * @brief  Tabla Hash cuyos elementos solo poseen clave, no tienen dato asociado
 */
class Tabla
{
    public:    
        
        typedef string TipoClave;
        typedef size_t (Tabla::*TipoHash)(string) const; //puntero a funcion miembro, tipo Hash 
        //Explicacion: Puntero a un metodo de la clase Hash que tenga como argumento string y mantenga el objeto constante
        
       /** 
        * @brief  Constructor con argumentos
        */
        Tabla(size_t); 
    
        /** 
        * @brief  Buscar un dato dada la clave
        */
        bool Buscar(TipoClave, TipoHash) const; 
        
        /** 
        * @brief  Insertar un dato
        */    
        void Insertar(const TipoClave &, TipoHash);
                
        /** 
        * @brief  Muestra el contenido de la Tabal
        */
        void Mostrar(ostream &) const;
        
        /** 
        * @brief  Funcion de dispersion
        */
        size_t Hash1(TipoClave) const;
        
        /** 
        * @brief  Funcion de dispersion
        */
        size_t Hash2(TipoClave) const;
        
        /** 
        * @brief  Devuelve las colisiones
        */
        int ObtenNColisiones();
        
        /** 
        * @brief  Devuelve el factor carga
        */
        int ObtenFactorCarga();
    
    private:
        vector< vector<TipoClave> > t;  
        
        int colisiones;
        int elementos;
};
#endif
