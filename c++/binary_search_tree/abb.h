/*
 * @file abb.h
 * @brief Material de entrega la Practica 5 de EDA (GIM).
 * 
 * Interfaz de un Arbol binario de busqueda
 * 
 * @author Gabriel Chaparro Villaescusa
 * @author María Navarro Silvestre
 * @date 21/10/2018
 * @version 1.0
 */
 
#ifndef _ABB_H
#define _ABB_H

#include "alumno.h"

using namespace std;

class ABB
{
    public:
        typedef unsigned TipoClave;
        typedef Alumno TipoDato;
            
        ABB(); 
        ~ABB();
        bool BuscarSuperior(unsigned id);
        bool Insertar(const TipoClave &, const TipoDato&); 
        void Inorden(ostream & sal) const;
        unsigned GetAltura();
        unsigned GetTamanyo();
        
    private:
        class NodoBin;
        typedef NodoBin * PtrNodoBin;
        class NodoBin
        {
            public:
                TipoClave clave; 
                TipoDato  dato;
                PtrNodoBin izq;
                PtrNodoBin der;
        
                NodoBin(): izq(nullptr), der(nullptr) {};
                NodoBin(TipoClave c, TipoDato d)
                : clave(c), dato(d), izq(nullptr), der(nullptr) {};
                ~NodoBin();
        };
       
        bool BuscarRecursivo(PtrNodoBin, const TipoClave &, TipoDato &) const; 
        bool BuscarSuperiorRecursivo(PtrNodoBin, unsigned int); 
        bool InsertarRecursivo(PtrNodoBin &, const TipoClave &, const TipoDato&); 
        void InordenRecursivo(ostream  & sal, PtrNodoBin, int nivel) const;
        unsigned GetAlturaRecursivo(PtrNodoBin &);
        
        PtrNodoBin raiz;
        unsigned tamanyo_arbol = 0;
};

#endif


