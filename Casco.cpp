#ifndef CASCO
#define CASCO

#include <GL/glut.h>

class Casco {

public:
	void desenhar(const bool caminhada, const int estagio, const int perna) {
		glPushMatrix();

		if (caminhada) {
			glRotatef(angulosCaminhando[perna][estagio], 0, 1, 0);
		} else {
			glRotatef(angulosCorrendo[perna][estagio], 0, 1, 0);
		}
		gluCylinder(gluNewQuadric(), 0.06, 0.1, 0.2, 30, 30);
		glTranslatef(0, 0, 0.2);

		glPushMatrix();
		glScalef(0.05, 0.05, 0.05);
		glutSolidCube(1);
		glPopMatrix();

		glPopMatrix();
	}

private:
	float angulosCaminhando[4][6] = { { 10, 10, 10, -3, -13, -1 }, /* FRENTE DIREITO */
	{ -3, -13, -1, 10, 10, 10 }, /* FRENTE ESQUERDO */
	{ 0, -20, -50, -30, 10, 5 }, /* TRÁS DIREITO */
	{ -30, 10, 5, 0, -20, -50 } /* TRÁS ESQUERDO */};

	float angulosCorrendo[4][6] = { { 46, -4, -30, -2 }, /* FRENTE DIREITO */
	{ -30, -2, 46, -4 }, /* FRENTE ESQUERDO */
	{ -51, -6, 40, -40 }, /* TRÁS DIREITO */
	{ 40, -40, -51, -6 } /* TRÁS ESQUERDO */};

};

#endif
