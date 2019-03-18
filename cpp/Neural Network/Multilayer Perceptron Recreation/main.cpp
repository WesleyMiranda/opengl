#include <GL\freeglut.h>
#include<iostream>
#include <vector>

using namespace std;


float xmin = -80;
float xmax = 80;
float ymin = -60;
float ymax = 60;
float c = 5;
int l, totalDatas = 100;
const int DIMENSION = 2;
vector<float> W;
vector<bool> hypothesis;

struct Data {
	vector<float> X;
	bool h;
	Data(float x_, float y_, bool h_)
	{
		X.clear();
		X.push_back(x_);
		X.push_back(y_);
		h = h_;
	}
};

struct Classification
{
	int pos;
	bool b;
	Classification(int pos_, bool b_)
	{
		pos = pos_;
		b = b_;
	}
};

typedef vector<Data>Space;
typedef vector<Classification>Misclassified;

Misclassified misclassified_examples;
Space A;

vector<float> vectorSum(vector<float>& A, vector<float>& B)
{
	vector<float> Sum;
	for (unsigned int i = 0; i < A.size(); i++)
	{
		float C = A[i] + B[i];
		Sum.push_back(C);
	}
	return Sum;
}

void scalarMultiplication(int x, vector<float>& A)
{
	for (unsigned int i = 0; i < A.size(); i++)
	{
		A[i] *= x;
	}
}

float dotProduct(vector<float>& W, vector<float>& X)
{
	float scalar = 0;
	for (unsigned int i = 0; i < W.size(); i++)
	{
		scalar += W[i] * X[i];
	}
	return scalar;
}

float f(float x)
{
	return c + x / 2;
}

void drawFunc(float xmin, float xmax, float a, float b)
{
	float ymin = a * xmin + b;
	float ymax = a * xmax + b;
	glBegin(GL_LINES);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymax);
	glEnd();
}

void Eixo(float x1, float y1, float x2, float y2)
{
	glColor3f(0, 0, 0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();

}

void esc(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
	case 27:
		exit(0);
	}
}

void list(Space& Vec)
{

	for (int i = 0; i < totalDatas; i++)
	{
		int x = rand() % 160 - 80;
		int y = rand() % 120 - 60;
		bool h = ((y - (int)f(x)) > 0) ? true : false;

		Data D((float)x, (float)y, h);
		Vec.push_back(D);
	}

	l = glGenLists(1);
	glNewList(l, GL_COMPILE);

	for (unsigned int i = 0; i < Vec.size(); i++)
	{

		if (Vec[i].h)
			glColor3f(1, 0, 0);
		else
			glColor3f(0, 0, 1);
		glPointSize(3);
		glBegin(GL_POINTS);
		glVertex2f(Vec[i].X[0], Vec[i].X[1]);
		glEnd();
	}
	glEndList();
}

void random(vector<float>& W)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		int x = rand() % 9 + 1;
		W.push_back((float)x);
	}
}

void predict()
{
	misclassified_examples.clear();
	float u;
	for (int i = 0; i < totalDatas; i++)
	{
		u = dotProduct(A[i].X, W);
		bool b = (u >= 0) ? true : false;
		if (A[i].h != b)
		{
			Classification C(i, b);
			misclassified_examples.push_back(C);
		}
	}
}

vector<float> perceptron()
{
	random(W);
	predict();

	while (0 != misclassified_examples.size())
	{
		int i = rand() % misclassified_examples.size();
		int j = (misclassified_examples[i].b) ? 1 : -1;
		scalarMultiplication(j, W);
		W = vectorSum(W, A[i].X);
		predict();
	}
	return W;
}

void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);

	Eixo(xmin, 0, xmax, 0); //Eixo X desenhado em Preto
	Eixo(0, ymin, 0, ymax); //Eixo Y desenhado em Preto

	glColor3f(0, 0, 0);
	drawFunc(xmin, xmax, 0.5, 0); //Desenho da reta esperada em PRETO

	//perceptron();

	float a = -(W[0] / W[1]);
	glColor3f(0, 1, 0);
	glLineWidth(3);
	drawFunc(xmin, xmax, a, 0); //Desenho da reta gerada pelo Perceptron em VERDE

	glCallList(l);

	glutSwapBuffers();
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
	gluOrtho2D(xmin, xmax, ymin, ymax);

	list(A);

	glutDisplayFunc(desenha);
	glutKeyboardFunc(esc);
	glutMainLoop();

	return 0;
}