#include <iostream>
#include <GL/freeglut.h>
using namespace std;

void Tri(float a, float b, float c, float d, float e, float f)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glVertex2f(e, f);
	glEnd();
}

void Poly(float a, float b, float c, float d, float e, float f, float g, float h)
{
	glBegin(GL_POLYGON);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glVertex2f(e, f);
	glVertex2f(g, h);
	glEnd();
}

void Tree(float a, float b, float c, float d, float e, float s)
{
	float t = 0;
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < s; i++)
	{
		glVertex2f(a, b - t);
		glVertex2f(c, b - t);
		glVertex2f(d, e);
		t = t + 0.05;
	}
	glEnd();
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sky
	glColor3ub(0, 191, 255);
	Poly(1.0, 1.0, -1.0, 1.0, -1.0, -0.2, 1.0, -0.2);

	// Ground
	glColor3ub(25, 150, 21);
	Poly(1.0, -0.2, -1.0, -0.2, -1.0, -1.0, 1.0, -1.0);

	// Mountains back
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(139, 69, 19, 220);
	Tri(-1.0, -0.2, -0.8, -0.2, -1.0, 0.2);

	Tri(-0.8, -0.2, -0.4, -0.2, -0.6, 0.3);

	Tri(-0.4, -0.2, 0.0, -0.2, -0.2, 0.3);

	Tri(0.0, -0.2, 0.4, -0.2, 0.2, 0.3);

	Tri(0.4, -0.2, 0.8, -0.2, 0.6, 0.3);

	Tri(0.8, -0.2, 1.0, -0.2, 1, 0.2);

	// Mountains front
	//glColor3ub(165, 42, 42);
	glColor4ub(165, 42, 42, 250);
	Tri(-1, -0.2, -0.6, -0.2, -0.8, 0.2);

	Tri(-0.6, -0.2, -0.2, -0.2, -0.4, 0.2);

	Tri(-0.2, -0.2, 0.2, -0.2, 0, 0.2);

	Tri(0.2, -0.2, 0.6, -0.2, 0.4, 0.2);

	Tri(0.6, -0.2, 1.0, -0.2, 0.8, 0.2);

	// House
	glColor3ub(224, 145, 8);
	Poly(0.7, 0.1, 0.3, 0.1, 0.3, -0.65, 0.7, -0.65);

	glColor3ub(255, 0, 29);
	Tri(0.2, 0.1, 0.8, 0.1, 0.5, 0.4);

	// Windows
	glColor3ub(15, 29, 224);
	Poly(0.65, 0.0, 0.55, 0.0, 0.55, -0.1, 0.65, -0.1);

	Poly(0.45, 0.0, 0.35, 0.0, 0.35, -0.1, 0.45, -0.1);

	// Door
	glColor3ub(138, 26, 163);
	Poly(0.55, -0.35, 0.45, -0.35, 0.45, -0.65, 0.55, -0.65);

	// Chimney
	Poly(0.65, 0.4, 0.6, 0.4, 0.6, 0.3, 0.65, 0.25);

	// Grass
	glColor3ub(90, 204, 20);
	Poly(0.8, -0.65, 0.2, -0.65, 0.2, -0.75, 0.8, -0.75);

	Poly(0.5, -0.75, -0.0, -0.75, -0.0, -0.85, 0.5, -0.85);

	// Sun
	glColor3ub(255, 255, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++) {
		float angle = 6.2832 * i / 64;  // 6.2832 represents 2*PI
		float x = 0.15 * cos(angle);
		float y = 0.2 * sin(angle);
		glVertex2f(x - 0.6, y + 0.7);
	}
	glEnd();

	// Pond
	glColor3ub(9, 155, 196);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++) {
		float angle = 6.2832 * i / 64;  // 6.2832 represents 2*PI
		float x = 0.3 * cos(angle);
		float y = 0.25 * sin(angle);
		glVertex2f(x - 0.5, y - 0.6);
	}
	glEnd();

	// Tree
	glColor3ub(14, 99, 12);
	Tree(-0.95, -0.4, -0.8, -0.87, -0.25, 3);

	Tree(0.95, -0.05, 0.8, 0.87, 0.1, 5);

	glColor3ub(188, 92, 18);
	Poly(-0.85, -0.5, -0.90, -0.5, -0.90, -0.65, -0.85, -0.65);

	Poly(0.85, -0.25, 0.90, -0.25, 0.90, -0.45, 0.85, -0.45);

	glutSwapBuffers();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutSetOption(GLUT_MULTISAMPLE, 4);
	glEnable(GLUT_MULTISAMPLE);
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize(1366, 768);
	glutCreateWindow("Assignment - 1");
	glutDisplayFunc(renderScene);
	glutMainLoop();

	return 1;
}