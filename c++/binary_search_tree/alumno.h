/*
 * @file alumno.h
 * @brief Material de entrega la Practica 5 de EDA (GIM).
 * 
 * Interfaz de un Alumno
 * 
 * @author Gabriel Chaparro Villaescusa
 * @author María Navarro Silvestre
 * @date 21/10/2018
 * @version 1.0
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef _ALUMNO_H_
#define _ALUMNO_H_

class Alumno
{
    string dni;
    string nombre;
    string apellidos;
    unsigned curso;
    unsigned telefono;
    
    static const unsigned NUM_NOMBRE = 15;
    static string list_nombre[];
    static string list_apellido[];


public:
    Alumno() {};
    Alumno(unsigned );
    string GetDNI() const 
    {
        return dni;
    };
    unsigned GetId(); 
    friend ostream & operator<<(ostream &, const Alumno &);
             
};

#endif


