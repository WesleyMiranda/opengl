#include<glut.h>
#include"cg.h"
#include"spline.h"
#include"lagrange.h"
#include<cstdlib>
#include<cmath>
#include<string>
#include <sstream>

using std::string;

// -lglut32 -lglu32 -lopengl32
using namespace std;

double xmin=-5;
double xmax=5;
double ymin=-2;
double ymax=2;

int nPts=5;
Pontos nos; // Guarda os nos

string intToString(int number){

	//this function has a number input and string output
	std::stringstream ss;
	ss << number;
	return ss.str();
}


double fx(double x)
{
	return cos(sin(3.0*x));
	//return sin(2*x);
	//return 1/(2+cos(x)*cos(x));
	//return 1/(1.0+x*x);
}

Funcao f=fx;
	

void teclado(unsigned char tcl, //guarda a tecla pressionada
					int x, int y) {    //Coordenadas do Mouse 
	switch (tcl) {
		case 27: //Escape key
			exit(0); //Exit the program			
	}
}


void criaPts(int botao, int status, int x, int y)
{
	if(botao==GLUT_LEFT_BUTTON)
		if(status==GLUT_DOWN)
			if(nPts<50)
				nPts++;
	
	if(botao==GLUT_RIGHT_BUTTON)
		if(status==GLUT_DOWN)
			if(nPts>5)
				nPts--;
	glutPostRedisplay();	
}


void iniciaDesenho()
{
	// Desenha Eixos
	MyRGB corEixo(0,0,1);
	cgDesenhaEixos(xmin,xmax,ymin,ymax, corEixo);
	//Desenha Moldura(retângulo)
	glBegin(GL_LINE_LOOP);
		glVertex2f(xmin,ymin);
		glVertex2f(xmax,ymin);
		glVertex2f(xmax,ymax);
		glVertex2f(xmin,ymax);		
	glEnd();
	
	
	// Plota os Pontos
	MyRGB corPts(1.0,0,0);// Pts Vermelhos
	cgPlotPontos(nos, corPts);
		
	// Desenha Função
	MyRGB corFuncao(0.0,0.6,0.4);
	glLineWidth(2.0);
	cgPlotFunc(f, xmin, xmax,corFuncao,150);	
	
	
}

void desenha()
{
	// Fundo Branco
	MyRGB backcolor(1,1,1);
	glClearColor(backcolor.R,backcolor.G,backcolor.B,0); 
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	// Cria os Pontos
	cgCriaPontos(f,nPts,nos,xmin,xmax);
	
	glViewport(0,0,600,600);				
	iniciaDesenho();
	// Imprime os Textos na Tela
	string mensagem = "Lagrange com "+ intToString(nPts)+" pontos";
	cgText(mensagem,xmin+0.1, ymax-0.5);
	//cgText(grauText,0.5, ymin);
	
	lagrangeInterpola(nos);
	
	glViewport(600,0,600,600);	
	iniciaDesenho();
	// Imprime os Textos na Tela
	mensagem = "Spline Quad com "+ intToString(nPts)+" pontos";
	cgText(mensagem,xmin+0.1, ymax-0.5);
	
	splineInterpola(nos);	
	
	
	// Imprime os Textos na Tela
//	std::string grauText = "Grau "+ intToString(nPts);
//	myText(funcText[index],0.5, ymax);
//	myText(grauText,0.5, ymin);
	//glFlush();
	glutSwapBuffers();
}




int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1200,600);
	glutCreateWindow("Spline Quadratico");
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin-0.2,xmax+0.2,ymin-0.2, ymax+0.2);
	
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutMouseFunc(criaPts);
	//glutTimerFunc(1000/FPS,idle,0);
	glutMainLoop();
		
	return 0;
}
