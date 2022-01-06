/*
 * @file abb.cpp
 * @brief Material de entrega la Practica 5 de EDA (GIM).
 * 
 * Implementación de un Arbol binario de busqueda
 * 
 * @author Gabriel Chaparro Villaescusa
 * @author María Navarro Silvestre
 * @date 21/10/2018
 * @version 1.0
 */

#include<iostream>
#include "abb.h"

using namespace std;

/**
 * @brief Constructor de un ABB
 */
ABB::ABB()
{
    this->raiz = nullptr;
}

/**
 * @brief Destructor de un ABB
 */
ABB::~ABB()
{
    if(this->raiz != nullptr)
        delete this->raiz;
}

/**
 * @brief Destructor de los subarboles de un nodo del ABB
 */
ABB::NodoBin::~NodoBin()
{
    if(izq != nullptr)
        delete izq;
    if(der != nullptr)
        delete der;
}

/**
 * @brief InserciÃ³n recursiva de un nuevo valor en el arbol
 * @param clave identificador del nodo
 * @param valor dato a insertar en el ABB
 * @return cierto si se ha insertado correctamente, falso si ya existia un nodo
 * con la misma clave
 */
bool ABB::Insertar(const TipoClave & clave, const TipoDato & valor)
{ 
    return InsertarRecursivo(this->raiz, clave, valor); 
}

/**
 * @brief Llamada recursiva de Insertar
 * @param raiz nodo padre del subarbol actual
 * @param clave identificador del nodo
 * @param valor dato a insertar en el ABB
 * @return cierto si se ha insertado correctamente, falso si ya existia un nodo
 * con la misma clave
 */
bool ABB::InsertarRecursivo(ABB::PtrNodoBin & raiz, const TipoClave & clave, const TipoDato & valor)
{   
    bool ok = true;

    if(raiz == nullptr){
        raiz = new ABB::NodoBin(clave, valor);
        this->tamanyo_arbol++;
    }
    else if(clave < raiz->clave)
        ok = InsertarRecursivo(raiz->izq, clave, valor);
    else if(raiz->clave < clave)
        ok = InsertarRecursivo(raiz->der, clave, valor);
    else  // ya existe !
        ok = false;
    return ok;
}

/**
 * @brief Impresion en inorden del ABB
 * @param salida stream de salida sobre el cual imprimir el recorrido
 */
void ABB::Inorden(ostream & salida) const
{ 
    int nivel = 1;
    
    InordenRecursivo(salida, raiz, nivel);    
}

/**
 * @brief Llamada recursiva de Inorden
 * @param salida stream de salida sobre el cual imprimir el recorrido
 * @param raiz nodo padre del subarbol actual
 * @param nivel altura actual del arbol
 */
void ABB::InordenRecursivo(ostream & salida, ABB::PtrNodoBin raiz, int nivel) const
{   
    int Nivel_aux = nivel + 1;
    if ( raiz != nullptr )
    {
        InordenRecursivo(salida, raiz->izq, Nivel_aux);
        salida << raiz->dato << "  | Nivel " << nivel << endl << endl;
        InordenRecursivo(salida, raiz->der, Nivel_aux);
    }
}


/**
 * @brief Devuelve la altura del ABB
 * @return altura del ABB
 */
unsigned ABB::GetAltura()
{
    return GetAlturaRecursivo(raiz);
}

/**
 * @brief Llamada recursiva de GetAltura
 * @param raiz 
 * @return altura del ABB actual
 */
unsigned ABB::GetAlturaRecursivo(ABB::PtrNodoBin & raiz)
{
    int AlturaIzquierda, AlturaDerecha;
    int AlturaFinal;

    if(raiz == nullptr)
        AlturaFinal = 0;
    else
    {
        AlturaIzquierda = GetAlturaRecursivo(raiz->izq);
        AlturaDerecha = GetAlturaRecursivo(raiz->der);

        if(AlturaIzquierda > AlturaDerecha)
            AlturaFinal = AlturaIzquierda + 1;
        else
            AlturaFinal = AlturaDerecha + 1;
    }
    
    return AlturaFinal;
}

/**
 * Tamanyo actual del ABB
 * @return  tamanyo del ABB
 */
unsigned ABB::GetTamanyo()
{
    return this->tamanyo_arbol;
}

/**
 * @brief Busca un alumno con id superior al introducido
 * @param id a buscar
 * @return cierto si se ha encontrado algÃºn id superior, falso en caso contrario
 */
bool ABB::BuscarSuperior(unsigned id)
{
    return BuscarSuperiorRecursivo(raiz, id);
}

/**
 * @brief Llamada recursiva de BuscarSuperior
 * @param raiz nodo padre del subarbol actual
 * @param id a buscar
 * @return cierto si se ha encontrado algÃºn id superior, falso en caso contrario
 */
bool ABB::BuscarSuperiorRecursivo(ABB::PtrNodoBin raiz, unsigned id)
{
    bool ok = false;
    
    if(id == raiz->dato.GetId())
    {
        ok = true;
        cout << raiz->dato;
        
        if(raiz->der != nullptr)
            BuscarSuperiorRecursivo(raiz->der, id);
    }
    else if(id < raiz->dato.GetId())
    {
        ok = true;
        cout << raiz->dato;
        
        if(raiz->izq != nullptr)
            BuscarSuperiorRecursivo(raiz->izq, id);
            
        if(raiz->der != nullptr)
            BuscarSuperiorRecursivo(raiz->der, id);
    }
    else if(id > raiz->dato.GetId())
    {       
        if(raiz->der != nullptr)
            BuscarSuperiorRecursivo(raiz->der, id);
    }
    
    return ok;
}





