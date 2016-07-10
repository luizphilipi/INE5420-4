#ifndef CANELA
#define CANELA

#include <GL/glut.h>

class Canela {

public:
	void desenhar(const bool caminhada, const int estagio, const int perna) {
		if (caminhada) {
			glRotatef(angulosCaminhando[perna][estagio], 0, 1, 0);
		} else {
			glRotatef(angulosCorrendo[perna][estagio], 0, 1, 0);
		}
		gluCylinder(gluNewQuadric(), 0.13, 0.08, 1, 30, 30);
		glTranslatef(0, 0, 1);

		glPushMatrix();
		glScalef(0.08, 0.08, 0.08);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();
	}

private:
	float angulosCaminhando[4][6] = { { 2, 0, 0, -28, -71, -37 }, /* FRENTE DIREITA */
	{ -28, -71, -37, 2, 0, 0 }, /* FRENTE ESQUERDA */
	{ 36, 42, 67, 53, 37, 30 }, /* TRÁS DIREITA */
	{ 53, 37, 30, 36, 42, 67 } /* TRÁS ESQUERDA */};

	float angulosCorrendo[4][6] = { { -1, -63, -55, -2 }, /* FRENTE DIREITA */
	{ -55, -2, -1, -63 }, /* FRENTE ESQUERDA */
	{ 80, 46, 49, 72 }, /* TRÁS DIREITA */
	{ 49, 72, 80, 46 } /* TRÁS ESQUERDA */};

};

#endif
