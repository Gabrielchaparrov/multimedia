/*
 * @file test.cpp
 * @brief Programa de test de la Practica 6 de EDA (GIM).
 * 
 * Pruebas con tablas
 * 
 * @author Gabriel Chaparro Villaescusa
 * @author María Navarro Silvestre
 * @date 21/10/2018
 * @version 1.0
 */
 
#include<iostream>
#include<fstream>
#include<string>

#include"tabla.h"

using namespace std;

/**
 * Tipo Hash para elegir entre la funcion Hash1 o Hash2
 */ 
typedef size_t (Tabla::*TipoHash)(string) const; 

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
string EraseDigits(string c);
bool Count1Digit(string c);
string Quitar(string str);
void Comprobar(string contrasena, Tabla t, TipoHash p);
void diccionario(int tam, TipoHash p);

/*
 * Programa principal.
 */
int main()
{
    Tabla::TipoHash p = & Tabla::Hash1;
    
    Tabla t(10);
    string cad;
    
    cout << "Espere mientras se carga el diccionario..." << endl;   //Carga el diccionario con tamaño 10 para poder realizar la tarea 2, el tamaño qui no importa.
    ifstream f;
    f.open("spanish-lex.lex");
    
        while(!f.eof())
        {
            f >> cad;
            cad = Quitar(cad);
            t.Insertar(cad, p);
        }
    
    f.close();
        
      
    cout << endl << "********** TAREA 2 **********" << endl;
    
    string contrasena = "locomotora1";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);    
    
    contrasena = "agu25a";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);
    
    contrasena = "ordena2dor";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);
    
    contrasena = "sssssss22ss";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);
    
    contrasena = "4rarbrcrd";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);
    
    contrasena = "sal9ypimienta";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);
    
    contrasena = "programmer2";
    cout << endl << "Contrasena: " << contrasena << endl;
    Comprobar(contrasena, t, p);
    
    
    cout << endl << "********** TAREA 3 **********" << endl << endl;
        
    cout << endl << "***** Hash 1 *****" << endl;   //Se rellenan los arboles con los tamaños determinados con Hash1 y se muestra por pantalla su información
    p = & Tabla::Hash1;
    diccionario(281, p);
    diccionario(541, p);
    diccionario(1069, p);
    diccionario(2903, p);
    diccionario(5939, p);
    
    cout << endl << "***** Hash 2 *****" << endl;   //Se rellenan los arboles con los tamaños determinados con Hash2 y se muestra por pantalla su información
    p = & Tabla::Hash2;
    diccionario(281, p);
    diccionario(541, p);
    diccionario(1069, p);
    diccionario(2903, p);
    diccionario(5939, p);    
    
}

/*** void diccionario(int tam, TipoHash p) ************************************/ /**
 *
 *  ellena la tabla con las palabras del diccionario
 *
 *  @param [in]  tam  Tamano de la tabla
 *
 *  @param [in]  p  Tipo de Hash (Hash1 o Hash2)
 *
*/ /************************************************************************/
void diccionario(int tam, TipoHash p)
{
    cout << "Tamano: " << tam << endl;
    
    Tabla t(tam);
    string cad;
    
    ifstream f;
    f.open("spanish-lex.lex");
    
        while(!f.eof())
        {
            f >> cad;
            cad = Quitar(cad);
            t.Insertar(cad, p);
        }
    
    f.close();
    
    cout << "Colisiones: " << t.ObtenNColisiones() << endl;
    cout << "Factor de carga: " << t.ObtenFactorCarga() << endl << endl;
}

/*** void Comprobar(string contrasena, Tabla t, TipoHash p) ************************************/ /**
 *
 *  omprueba que la contrasena sea valida
 *
 *  @param [in]  contrasena  Cadena a analizar
 *
 *  @param [in]  t  Tabla con el diccionario
 *
 *  @param [in]  p  Tipo de Hash (Hash1 o Hash2)
 *
*/ /************************************************************************/
void Comprobar(string contrasena, Tabla t, TipoHash p)
{    
    if(contrasena.length() >= 8)
    {
        if(Count1Digit(contrasena))
        {
            contrasena = EraseDigits(contrasena);
                
                if(!t.Buscar(contrasena, p))
                    cout << "Es valida" << endl;
                else
                    cout << "No valida. Pertence al diccionario de la lengua espanola." << endl;            
        }
        else
            cout << "No valida. La contrasena debe tener un y solo un digito." << endl;
    }
    else
        cout << "No valida. La contraseña debe tener almenos 8 caracteres." << endl;
    
}

/*** string Quitar(string str) ************************************/ /**
 *
 *  limina los caracteres especiales de una cadena
 *
 *  @param [in]  str  Cadena de la que se eliminan los caracteres especiales
 *
 *  @return  Cadena sin caracteres especiales
 *
*/ /************************************************************************/
string Quitar(string str)
{
    unsigned int i = 0;
    
    do{
        if(ispunct(str[i]))
            str.erase(i, 1);
        else
            i++;
        
    }while(i < str.length());
    
    return str;
}

string EraseDigits(string c)
{
    unsigned int i = 0;
    
    do{
        if (isdigit(c[i])) 
            c.erase(i,1); 
        else
            i++;
    }while (i < c.length());

    return c;
} 

bool Count1Digit(string c)
{
    unsigned int i, cont = 0;

    for (i=0; i<c.length()&&cont<=1; i++)
        if (isdigit(c[i])) 
            cont ++;

    return cont == 1;
}


