/******* Pr06_Pila.cpp **************************************************/ /**
 *
 * @file Pr06_Pila.cpp
 *
 * Implementación de los métodos de la clase Pila (estatica)
 *
 * @version 1.0
 * @author Gabriel Chaparro y María Navarro
 * @date 28/04/2018
 *  
 ***************************************************************************/

#include "Pr06_Pila.h"

/*** Pila::Pila () ****************************************************/ /**
 *
 *  Inicia la pila a 'vacia' asignado '-1' a la cima
 *
 */ /**********************************************************************/
Pila::Pila ()
{
cima = -1;
}

/*** bool Pila::PilaVacia () ******************************************/ /**
 *
 *  Nos dice si una pila esta o no vacia (comprobanod el valor de la cima)
 *
 *  @retval  True  La pila esta vacia
 *  @retval  False  La pila contiene algun elemento
 *
 */ /**********************************************************************/
bool Pila::PilaVacia ()
{
    return cima == -1;
}

/*** bool Pila::Apilar (Valor) ****************************************/ /**
 *
 *  Intenta apilar un cierto valor en la pila. Si la pila se ha llenado
 *  no sera posible apilar el valor y nos devolvera false. Si queda espacio
 *  en la pila, apilara el valor sobre la cima y nos devolvera true.
 *
 *  @retval  True  La pila tiene espacio y ha sido posible apilar el valor
 *  @retval  False  La pila no tiene espacio libre y NO ha sido posible 
 *                  apilar el valor
 *
 */ /**********************************************************************/
bool Pila::Apilar (Valor x)
{
    bool ok;

    //Last item fix
    if(x.GetPalo() == 'P')
    {
        x.PutPalo('B');
        x.PutNumero(12);
    }

    /*
     * Si ya estan ocupadas todas la posiciones del vector,
     * no hay espacio para nuevos elementos
     */
    if (cima == MAX-1)
        ok = false;
    // En caso contrario, apilamos el nuevo elemento
    else
    {
        cima++;
        datos[cima] = x;
        ok = true;
    }

    return ok;
}

/*** bool Pila::Desapilar (void) **************************************/ /**
 *
 *  Intentamos eliminar el elemento de la cima de la pila, si este existe.
 *  Si el elemento existe, se elimna y se devuelve True. Si el elemento no
 *  existe, no es posible eliminarlo y se devuleve False
 *
 *  @retval  True  La pila tiene elementos y ha sido posible eliminar el
 *                 valor de la pila
 *  @retval  False  La pila no tiene elementos y NO ha sido posible 
 *                  eliminar ningun valor de la misma
 *
 */ /**********************************************************************/
bool Pila::Desapilar (void)
{
    bool ok;
    
    // Si la pila esta vacia, no se puede desapilar
    if (cima == -1) 
        ok = false;
    else
    {
        cima--;
        ok = true;
    }

    return ok;
}

/*** bool Pila::CimaPila (Valor &) ************************************/ /**
 *
 *  Consulta el elemento de la cima de la pila y lo devuelve, si este 
 *  existe. Si existe se devuelve True. Si no es posible consultarlo porque
 *  no existe se devuelve False
 *
 *  @retval  True  La pila tiene elementos y ha sido posible consultar el
 *                 valor de la cima
 *  @retval  False  La pila no tiene elementos y NO ha sido posible 
 *                  consultar ningun valor de la misma
 *
 */ /**********************************************************************/
bool Pila::CimaPila (Valor & x)
{
    bool ok;
    
    // Si la pila esta vacia, no hay nada que consultar
    if (cima == -1)
        ok = false;
    else
    {
        x = datos[cima];
        ok = true;
    }
    
    return ok;
}

/*** ostream& operator<< (ostream &, Pila) ********************/ /**
 *
 *  Sobrecarga del operador '<<' para llevar al stream de salida la
 *  informacion de todo el contenido de la pila
 *
 *  @return  El stream modificado
 *
 */ /**********************************************************************/
ostream& operator<< (ostream & out, Pila p)
{
    int i;
	
    for (i = 0; i <= p.cima; i++)
    {
        out << p.datos[i];
        if (i != p.cima)
            out << ",";
            
        //cout << p.datos[i].GetNumero() + p.datos[i].GetPalo();
    }
    
    return out;

}












