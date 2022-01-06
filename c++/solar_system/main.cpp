/*
Practica Informática Gráfica
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

int screenWidth = 800;
int screenHeight = 600;

float angulo_tierra = 0.0;
float angulo_luna = 0.0;
float angulo_marte = 0.0;
float angulo_phobos = 0.0;
float angulo_deimos = 0.0;

//Rota el eje Z

void RotarZ(float cambio) {
	float Z[16] = { cos(cambio), sin(cambio), 0, 0, -sin(cambio), cos(cambio), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

	glMultMatrixf(Z);  //Multiplica la matriz de rotación Z con la pila MODELVIEW

}

//Translada la figura

void Mover(float x, float y) {
	float Movimiento[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, 0, 1 };

	glMultMatrixf(Movimiento);  //Multiplica la matriz de movimiento con la pila MODELVIEW

}

//FUNCIONES DE DIBUJADO DE LOS SISTEMAS PLANETARIOS
void dibuja_sol() {

	glColor3f(1.0, 0.8, 0.0);
	glutWireSphere(0.8, 20, 20);

}

void dibuja_sistema_tierra_luna() {

	glPushMatrix();   //Junto con el último glPopMatrix encapsula los movimientos de todo el sistema (TIERRA + LUNA)
	//TIERRA

	RotarZ(angulo_tierra);  //Rota a la Tierra sobre el Sol (TRANSLACIÓN)
	Mover(-2.5, 0.0);       //Posiciona a la Tierra a su distancia del Sol

	//Somete a la Tierra a una translacion Tierra: R(angulo_tierra) * T(6.0) * Geometria()
	glColor3f(0, 0.5, 0.5);
	glutWireSphere(0.5, 20, 20);  //Dibuja la Tierra

	//LUNA

	RotarZ(angulo_luna);   //Rota a la Luna sobre la Tierra (TRANSLACIÓN)
	Mover(1.0, 0.0);	   //Posiciona a la Luna a su distancia de la Tierra

	//Somete a la Luna a la translacion compuesta Luna: R(angulo_tierra) * T(6.0) * R(angulo_luna) * T(1.0) * Geometria()
	glColor3f(1, 1, 1);
	glutWireSphere(0.1, 20, 20);  //Dibuja la Luna

	glPopMatrix();

	angulo_tierra += 0.0523599;        //Velocidad de translación de la Tierra  (Unidades cambiadas de grados a radianes)
	angulo_luna += 0.174533;           //Velocidad de translación de la Luna    (Unidades cambiadas de grados a radianes)
}

void dibuja_sistema_marte_phobos_deimos() {

	glPushMatrix();   //Junto con el último glPopMatrix encapsula los movimientos de todo el sistema (MARTE + 2 SATEÍTES)
	//MARTE

	RotarZ(angulo_marte);    //Rota a Marte sobre el Sol (TRANSLACIÓN)
	Mover(6.0, 0.0);         //Posiciona a Marte a su distancia del Sol

	//Somete a Marte a una translacion Marte: R(angulo_marte) * T(-2.5) * Geometria()
	glColor3f(0.90, 0.26, 0.06);
	glutWireSphere(0.4, 20, 20);  //Dibuja Marte

	glPushMatrix(); //Crea una nueva composición

	RotarZ(angulo_phobos);    //Rota a Phobos sobre Marte (TRANSLACIÓN)
	Mover(-1.25, 0.0);        //Posiciona a Phobos a su distancia de Marte

	//Somete a Phobos a la translacion compuesta Phobos: R(angulo_marte) * T(-2.5) * R(angulo_phobos) * T(-1.25) * Geometria()
	glColor3f(0.0, 0.80, 0.80);
	glutWireSphere(0.1, 20, 20);  //Dibuja a Phobos

	glPopMatrix();   //Elimina esta composición 

	RotarZ(angulo_deimos);    //Rota a Deimos sobre Marte (TRANSLACIÓN)
	Mover(-0.75, 0.0);        //Posiciona a Deimos a su distancia de Marte

	//Somete a Deimos a la translacion compuesta Deimos: R(angulo_marte) * T(-2.5) * R(deimos) * T(-0.75) * Geometria()
	glColor3f(0.97, 0.57, 0.1);
	glutWireSphere(0.1, 20, 20);  //Dibuja a Deimos

	glPopMatrix();

	angulo_marte += 0.0174533;       //Velocidad de translación de Marte  (Unidades cambiadas de grados a radianes)
	angulo_phobos += 0.10472;        //Velocidad de translación de Phobos (Satélite morado, órbita exterior)
	angulo_deimos += 0.139626;       //Velocidad de translación de Deimos (Satélite naranja, órbita interior)
}

//DEFINICION DE FUNCIONES DE CALLBACK

  //Coloca la imagen raster en la posicion del puntero del raton al pulsar boton izdo. Limpia la ventana co el boton derecho
void myMouse(int button, int state, int mx, int  my) {

	if (button == GLUT_LEFT_BUTTON)
	{

	}
	if (button == GLUT_RIGHT_BUTTON) {

	}
	glutPostRedisplay();
}


//Cambia las dimensiones de la pantalla

void myReshape(int w, int h) {
	screenWidth = w;
	screenHeight = h;

}

//Dibuja el raster

void myDisplay(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	dibuja_sol();

	dibuja_sistema_tierra_luna();

	dibuja_sistema_marte_phobos_deimos();

	glFlush();

}

//Control por teclado

void myKeys(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'q': exit(0);

	}
	glutPostRedisplay();
}


void myIdle() {
	//usleep(1000); 
	Sleep(50); // milisegundos

	glutPostRedisplay();

}

int main(int argc, char ** argv) {

	//CREACION DEL ENTORNO GRAFICO
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(30, 30);
	glutInit(&argc, argv);
	glutCreateWindow("Lab. Informatica Grafica");
	//--------------------


	//Damos de alta a las funciones de Callback
	glutKeyboardFunc(myKeys);
	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	//--------------------

	//Funciones de limpieza de la pantalla
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//---------------------

	glFlush();
	glMatrixMode(GL_PROJECTION);
	//izda,dcha,abajo,arriba
	glLoadIdentity();
	glOrtho(-8.0, 8.0, -8.0, 8.0, -2.5, 2.5);
	glMatrixMode(GL_MODELVIEW);
	//x,y,anchura,altura
	glViewport(0, 0, screenWidth, screenHeight);



	//Llamada al bucle principal de recoleccion de eventos
	glutMainLoop();
}