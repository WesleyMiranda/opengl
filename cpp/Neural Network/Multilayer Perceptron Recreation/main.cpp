#include<GL\freeglut.h>
#include<vector>
using namespace std;

struct Data
{
	int x;
	int y;
	bool h;
	Data(int x_,int y_,bool h_) 
	{
		x = x_;
		y = y_;
		h = h_;
	}
};

int LARGURA = 800, ALTURA = 600, ndados = 100;
double xmax = 5, ymax = 4;
int l;
typedef vector<Data> Amostra;
Amostra AM;

int func(int x)
{
	return (int)(x / 2);
}

void drawFunc(int r)
{
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0.1, 0.6);
	glEnd();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawFunc(xmax);

	glPointSize(4);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2d(5,2);
	glEnd();

	glutSwapBuffers();
}

int lista(Amostra &Vec)
{
	for (int i = 0; i < ndados; i++)
	{
		int x, y;
		bool h;

		x = rand() % 160 - 80;
		y = rand() % 120 - 60;
		h = ((y - func(x)) > 0) ? true : false;

		Data A(x, y, h);
		Vec.push_back(A);

	}

	int num = glGenLists(1);
	glNewList(num, GL_COMPILE);
	for (int i = 0; i < ndados; i++)
	{
		glBegin(GL_POINTS);
		glVertex2d(Vec[i].x, Vec[i].y);
		glEnd();
	}
	glEndList();
	return num;
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Desenha Funcao");
	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-2, xmax, 0, ymax);

	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}