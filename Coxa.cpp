#ifndef COXA
#define COXA

#include <GL/glut.h>

class Coxa {

public:
	void desenhar(const bool caminhada, const int estagio, const int perna) {
		if (caminhada) {
			glRotatef(angulosCaminhando[perna][estagio], 0, 0, 1);
		} else {
			glRotatef(angulosCorrendo[perna][estagio], 0, 0, 1);
		}
		glRotatef(90, 1, 0, 0);
		gluCylinder(gluNewQuadric(), 0.5, 0.17, 1.4, 30, 30);
		glTranslatef(0, 0, 1.4);

		glPushMatrix();
		glScalef(0.17, 0.17, 0.17);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();
	}

private:
	float angulosCaminhando[4][6] = { { 4, -4, -15, -4, 20, 37 }, /* FRENTE DIREITA */
	{ -4, 20, 37, 4, -4, -15 }, /* FRENTE ESQUERDA */
	{ -28, -37, -34, -6, -8, -18 }, /* TRÁS DIREITA */
	{ -6, -8, -18, -28, -37, -34 }, /* TRÁS ESQUERDA */};

	float angulosCorrendo[4][6] = { { -15, 20, 48, 22 }, /* FRENTE DIREITA */
	{ 48, 22, -15, 20 }, /* FRENTE ESQUERDA */
	{ -28, -2, -30, -56 }, /* TRÁS DIREITA */
	{ -30, -56, -28, -2 } /* TRÁS ESQUERDA */};

};

#endif
