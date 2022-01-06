/*
Practica 1 Informática Gráfica
*/

#include <windows.h>

#include <stdlib.h>
#include <stdio.h>
//#include <sys/time.h>

#include <ctime>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

struct linea {
	double x1, y1, x2, y2;
};

linea segmento[100];
int tam = 0;

float L = 15.5;
int screenWidth = 640;
int screenHeight = 480;
const int TAM_VENTANA_X = screenWidth;
const int TAM_VENTANA_Y = screenHeight;

int posx, posy;

float angulo = 0.0; //angulo inicial
float posicion[2] = { TAM_VENTANA_X / 2.0, TAM_VENTANA_Y / 2.0 }; //pos inicial


//extremos de la ventana de recorte
float xmin, ymin, xmax, ymax;

void configuraventana()
{
	xmin = TAM_VENTANA_X / 3.0;
	ymin = TAM_VENTANA_Y / 3.0;
	xmax = 2 * TAM_VENTANA_X / 3.0;
	ymax = 2 * TAM_VENTANA_Y / 3.0;
}

/************************************************************************/
/* ALGORITMO DE RECORTE DE COHEN SUTHERLAND *****************************/
/* SI DEVUELVE TRUE, ES ACEPTADO Y SE DEBE DIBUJAR **********************/
/* SI DEVUELVE FALSE, NO LO ES Y NO SE DIBUJA******************************/
/* EN LOS ARGUMENTOS PASADOS POR REFERENCIA *******************************/
/* SE PASAN LOS VALORES INICIALES Y LUEGO SE ENCUENTRAN LOS NUEVOS PUNTOS DEL SEGMENTO*/
/************************************************************************/
struct code {
	int u, d, r, l;
};

code calcula_codigo(float x, float y)
{
	code codigo = { 0,0,0,0 };
	if (y > ymax)
		codigo.u = 1;
	else if (y < ymin)
		codigo.d = 1;
	if (x > xmax)
		codigo.r = 1;
	else if (x < xmin)
		codigo.l = 1;
	return(codigo);
}

bool cohen_suth(double & x0, double & y0, double & x1, double & y1)
{
	bool accept = false, done = false;
	code code0, code1, codeout;
	double x, y;
	code0 = calcula_codigo(x0, y0);

	code1 = calcula_codigo(x1, y1);
	do {
		if (!((code0.u || code1.u) || (code0.d || code1.d) || (code0.r || code1.r) || (code0.l || code1.l)))
		{
			accept = true; done = true;
		} //ACEPTO TRIVIAL

		else if ((code0.u&&code1.u) || (code0.d&&code1.d) || (code0.r&&code1.r) || (code0.l&&code1.l))
			done = true; //RECHAZO TRIVIAL

		else
		{ //HACEMOS RECORTE
			if (code0.u + code0.d + code0.r + code0.l > 0)
				codeout = code0;
			else
				codeout = code1;
			if (codeout.u == 1) {
				x = x0 + (x1 - x0)*(ymax - y0) / (y1 - y0);
				y = ymax;
			}
			else if (codeout.d == 1) {
				x = x0 + (x1 - x0)*(ymin - y0) / (y1 - y0);
				y = ymin;
			}
			else if (codeout.r == 1) {
				y = y0 + (y1 - y0)*(xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else {
				y = y0 + (y1 - y0)*(xmin - x0) / (x1 - x0);
				x = xmin;
			}
			if ((codeout.u == code0.u) &&
				(codeout.d == code0.d) &&
				(codeout.r == code0.r) &&
				(codeout.l == code0.l)) {
				x0 = x; y0 = y;
				code0 = calcula_codigo(x0, y0);
			}
			else {
				x1 = x; y1 = y;
				code1 = calcula_codigo(x1, y1);
			}
		}//del else HACEMOS RECORTE
	} while (done == false);
	return(accept);
}

void lineTo(float x, float y, float aux, float aux2) {
	//Variables de entrada/salida del algoritmo
	bool resul;
	double xdef0, ydef0, xdef1, ydef1;
	xdef0 = x;
	ydef0 = y;
	xdef1 = aux;
	ydef1 = aux2;

	//rellena aquí los vertices xdef0,etc con los valores de los
	// vertices que definen el segmento, es decir, con
	// posicion[0],posicion[1],x,y
	//Llama aquí a la función de recorte que has implementado
	resul = cohen_suth(xdef0, ydef0, xdef1, ydef1);
	//Tras la llamada se analiza el valor de resul y se dibuja (no tocar
	// nada)
	if (resul == TRUE)
	{
		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(x, y);
		glVertex2f(xdef0, ydef0);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(xdef0, ydef0);
		glVertex2f(xdef1, ydef1);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(xdef1, ydef1);
		glVertex2f(aux, aux2);
		glEnd();
	}
	else {
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(xdef0, ydef0);
		glVertex2f(aux, aux2);
		glEnd();
	}
	glFlush();
	posicion[0] = aux;
	posicion[1] = aux2;
}


void generalinea()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 1.0, 1.0);

	segmento[tam].x1 = rand() % screenWidth; 
	segmento[tam].y1 = rand() % screenHeight;
	segmento[tam].x2 = rand() % screenWidth;
	segmento[tam].y2 = rand() % screenHeight;

	glVertex2f(segmento[tam].x1, segmento[tam].y1);
	glVertex2f(segmento[tam].x2, segmento[tam].y2);

	tam++;

	glEnd();

}

void recorte()
{
	int i;
	for (i = 0; i <= tam; i++)
	{
		lineTo(segmento[i].x1, segmento[i].y1, segmento[i].x2, segmento[i].y2);
	}
}

//DEFINICION DE FUNCIONES DE CALLBACK

//Función del callback del ratón
void myMouse(int button, int state, int mx, int  my)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			posx = mx;
			posy = screenHeight - my;
			//polyespiral();
		}

		else if (button == GLUT_RIGHT_BUTTON)
		{

		}
		glutPostRedisplay();
	}
}


//Función de callback de cambio del tamaño de la ventana
void myReshape(int w, int h)
{
	screenWidth = w;
	screenHeight = h;
}

//Función de callback del teclado
void myKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		generalinea();
		break;

	case 'd':
		recorte();
		break;
	}

	glutPostRedisplay();
}

void dibujaVentana()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 0.0);

	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymin);
	glVertex2f(xmin, ymin);
	glVertex2f(xmin, ymax);
	glVertex2f(xmax, ymax);

	glEnd();
}


void myDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);

	configuraventana();

	dibujaVentana();

	glFlush();
}

//Funcion de actualizacion automatica
//Es la función que se ejecuta siempre que no ocurran otros eventos

void myIdle()
{
	// Número de milisegundos que han pasado desde que se inicio el programa
	long int currentTime = glutGet(GLUT_ELAPSED_TIME);
	glutPostRedisplay();
	Sleep(1);  // Esto si no tienes habilitado el vSync
}


int main(int argc, char ** argv)
{
	srand(time(NULL));

	//Inicialización de GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(30, 30);
	glutInit(&argc, argv);
	glutCreateWindow("Uso Basico OpenGl. Lab. Informatica Grafica");
	//--------------------

	//Damos de alta a las funciones de Callback
	glutKeyboardFunc(myKeys);
	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	//--------------------

	//Configurar el color de borrado de la pantalla y borrar la pantalla
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//---------------------

	glFlush();

	//Configuración de la vista
	glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
								 //izda,dcha,abajo,arriba
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
	glMatrixMode(GL_MODELVIEW);  // To operate on the model-view matrix
								 //x,y,anchura,altura
	glViewport(0, 0, screenWidth, screenHeight);

	//Llamada al bucle principal de recoleccion de eventos
	glutMainLoop();
}
