///////////////////////////////////////////////
//Autores: María Navarro y Gabriel Chaparro //
//            PROYECTO FINAL                //
//////////////////////////////////////////////
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<fstream>
using namespace std;

//Declaración de vectores y matriz
const int MAX = 30000;
const int maxim = 13;
typedef string Vector[MAX];
typedef char v_palabra[maxim];
typedef string matriz[7][13];

//Estructura de la estadística
struct formato
{
	string palabra_intento;
	int n_partidas;
	int n_victorias;
};

//Funciones
void fich_palabra(Vector, int &);
void fich_estadistica(formato &);
void menu(int &);
void opcion1(formato);
void opcion2(formato &, matriz);
void opcion3(formato &, matriz, Vector, int);
void opcion4(formato);
void dibujo(matriz);
void ahorcado(matriz, string, formato &);
void mostrar_horca(matriz);


int main()
{
	Vector words;
	matriz horca;
	formato estadistica;
	int opcion = 0, totalpalabras = 0;
	fich_palabra(words, totalpalabras);
	fich_estadistica(estadistica);
	
	//Bucle de opciones
	do
	{
		menu(opcion);
		
		if(opcion == 1)
			opcion1(estadistica);
			
		else if(opcion == 2)
		{
			opcion2(estadistica, horca);
			estadistica.n_partidas++;
		}
			
		else if(opcion == 3)
		{
			opcion3(estadistica, horca, words, totalpalabras);
			estadistica.n_partidas++;
		}
		
		else if(opcion == 4)
		{
			opcion4(estadistica);
		}
		
	}while(opcion != 4);
	
	return 0;
}

//Funci�n que lee el fichero y rellena el vector "words" con todas las palabras
void fich_palabra(Vector words, int & totalpalabras)
{
	ifstream palabras;
	palabras.open("palabras.txt");

	if (!palabras) 
		cout << "Error"; 
	else 
	{
		while(!palabras.eof())
		{
			palabras >> words[totalpalabras];
			totalpalabras++;    //Número final de palabras
		}
	}
	
	palabras.close();
}

//Función que lee el fichero y inserta los datos en la estructura
void fich_estadistica(formato & estadistica)
{
	ifstream estadisticas;
	estadisticas.open("estadisticas.txt");

	if (!estadisticas) 
		cout << "Error"; 
	else 
	{
		//int i = 0;
		estadisticas >> estadistica.palabra_intento;
		estadisticas >> estadistica.n_partidas;
		estadisticas >> estadistica.n_victorias;	
	}
	
	estadisticas.close();
}

//Función que muestra por pantalla las opciones y recibe la seleccionada
void menu(int & opcion)
{
	cout << endl << "SELECCIONE UNA OPCION: " << endl << endl;;
	cout << "1 - Mostrar estadisticas." << endl;
	cout << "2 - Repetir la ultima partida." << endl;
	cout << "3 - Jugar una nueva partida." << endl;
	cout << "4 - Salir del programa." << endl;
	cin >> opcion;
	cout << endl;
}

//Función que muestra por pantalla las estad�sticas de las partidas anteriores
void opcion1(formato estadistica)
{
	cout << "Numero de partidas jugadas: " << estadistica.n_partidas << endl;
	cout << "Numero de partidas ganadas: " << estadistica.n_victorias << endl;
}

//Función que inicia el juego con la palabra de la partida anterior
void opcion2(formato & estadistica, matriz horca)
{
	string palabra_oculta = estadistica.palabra_intento;
		
	ahorcado(horca, palabra_oculta, estadistica);	
}

//Función que inicia el juego con una palabra nueva
void opcion3(formato & estadistica, matriz horca, Vector words, int totalpalabras)
{
	int N;
	string palabra_oculta;
	
	//Genera un n�mero aleatorio
	srand(time(0));
    N = rand() % (totalpalabras);
    
    //Guarda en la variable una palabra aleatoria del vector
    palabra_oculta = words[N];
    
    
    ahorcado(horca, palabra_oculta, estadistica);
    
    //Guarda la palabra utilizada en la estructura
    estadistica.palabra_intento = palabra_oculta;
	
}

//Función que escribe en el fichero los datos guardados en la estructura
void opcion4(formato estadistica)
{
	ofstream estadisticas;
	estadisticas.open("estadisticas.txt");

	if (!estadisticas) 
		cout << "Error"; 
	else 
	{
		estadisticas << estadistica.palabra_intento << endl;
		estadisticas << estadistica.n_partidas << endl;
		estadisticas << estadistica.n_victorias << endl;
	}
	
	estadisticas.close();
}

//Función que dibuja la horca inicial en una matriz
void dibujo(matriz horca)
{
	for(int j = 0; j < 13; j++)
		horca[0][j] = "=";
		
		
	for(int i = 1; i < 6; i++)
		{
			horca[i][0] = "|";
			horca[i][1] = "|";
		}
		
		
	for(int j = 0; j < 3; j++)
		horca[6][j] = "=";
		

	
	for(int j = 2; j< 13; j++)
		for(int i = 1; i < 5; i++)
			horca[i][j] = " ";
		
	
		
	horca[1][11] = "|";
		
}

//Función del juego
void ahorcado(matriz horca, string palabra_oculta, formato & estadistica)
{
	v_palabra oculto;
	int longitud = palabra_oculta.length();
	char letra;
	int acierto;
	int num_errores = 0;
	int total;
	int aux;
	
	dibujo(horca);
	
	//Escribe en el vector "oculto" la primera y la última letra de la palabra a adivinar y el resto se rellena con "_"
	oculto[0] = palabra_oculta[0];
	oculto[longitud - 1] = palabra_oculta[longitud-1];
	
	for(int i = 1; i < longitud - 1; i++)
		oculto[i] = '_';
		
	//Bucle que continua el juego mientras no se complete la horca
	while(horca[4][12] == " ")
	{
		total = 0;
		acierto = 0;
		aux = 0;
		
		cout << "Palabra a adivinar: " << endl << endl;
		
		for(int i = 0; i < longitud; i++)
			cout << oculto[i] << " ";
		cout << endl << endl;
			
		mostrar_horca(horca);
		
		cout << endl <<"Introduce una letra: ";
		cin >> letra;
		
		letra = tolower(letra);
	
		//Comprueba que la letra introducida no lo haya sido anteriormente
		for(int i = 1; i < longitud - 1; i++)
		{
			if(oculto[i] == letra)
				aux = 1;
		}
		
		//Comprueba si la letra introducida perteneze a la palabra a adivinar
		for(int i = 1; i < longitud - 1; i++)
		{
			if(palabra_oculta[i] == letra)
			{
				oculto[i] = letra;
				acierto++;
			}
		}
		
		//Comprueba el n�mero de casillas del vector resueltas
		for(int i = 0; i < longitud; i++)
		{
			if(oculto[i] != '_')
				total++;	
		}
		
		//Mensaje de victoria
		if(longitud == total)
		{
			
			cout << "Palabra a adivinar: " << endl << endl;
		
		for(int i = 0; i < longitud; i++)
			cout << oculto[i] << " ";
		cout << endl << endl;
			
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 13; j++)
				cout << horca[i][j];
			cout << endl;
		}
			
		cout << "Enhorabuena, has conseguido acertar la palabra oculta." << endl << endl;	
		estadistica.n_victorias++;
		return;
		}
		
		//Dibuja las partes del ahorcado cuando la letra introducida es errónea y muestra el mensaje de partida perdida cuando la horca se completa
		if(acierto == 0 || aux == 1)
		{
			num_errores++;
			
			
			if(num_errores == 1)
				horca[2][11] = "O";
				
			else if(num_errores == 2)
				horca[3][11] = "|";
				
			else if(num_errores == 3)
				horca[3][10] = "/";
				
			else if(num_errores == 4)
				horca[3][12] = "\\";
				
			else if(num_errores == 5)
				horca[4][10] = "/";
				
			else if(num_errores == 6)
			{
				horca[4][12] = "\\";
				
				cout << "Palabra a adivinar: " << endl << endl;
		
				for(int i = 0; i < longitud; i++)
					cout << oculto[i] << " ";
				cout << endl << endl;
			
				cout << ".............................................." << endl;
			
				mostrar_horca(horca);
				
				cout << endl << "Lo siento, no has conseguido acertar la palabra oculta." << endl << "Mas suerte la proxima vez." << endl;		
				
			}
					
		}
		cout << ".............................................." << endl;
	}	
		
}

//Función que muestra la matriz "horca" por pantalla
void mostrar_horca(matriz horca)
{
	for(int i = 0; i< 7; i++ )
	{
		for(int j = 0; j < 13; j++)
			cout << horca[i][j];
		cout << endl;
	}
}
