#include<GL/freeglut.h>
#include"Bola.h"
#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::vector;

int LARGURA=800;
int ALTURA=600;
int FPS=35;

static void desenha(void);
static void teclado(unsigned char key, int x, int y);
static void idle(int);
void mouse(int botao, int status, int x, int y);

float xc,yc;
bool fonte=false;

vector<Bola> bolas;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(LARGURA,ALTURA);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Bolas");

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0,LARGURA,0,ALTURA);


    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouse);
    glutTimerFunc(1000/FPS,idle,0);


    glutMainLoop();

    return 0;
}


static void desenha(void)
{
    glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);


    for(int i=0; i< bolas.size(); i++)
		{
		    bolas[i].update();
		    bolas[i].show();
		    if(bolas[i].continua())
                bolas.erase(bolas.begin()+i);
		}

    glutSwapBuffers();
}


static void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}

