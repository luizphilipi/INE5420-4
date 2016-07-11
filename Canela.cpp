#ifndef CANELA
#define CANELA

#include <GL/glut.h>

class Canela {

public:
	void desenhar(const bool caminhada, const int estagio, const int perna) {
		glColor3f(0.855f, 0.784f, 0.682f);
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
	float angulosCaminhando[4][6] = { { 0, 0, 0, -25, -60, -10 }, /* FRENTE DIREITA */
	{ -25, -60, -10, 0, 0, 0 }, /* FRENTE ESQUERDA */
	{ 30, 20, 65, 45, 25, 30 }, /* TRÁS DIREITA */
	{ 45, 25, 30, 30, 20, 65 } /* TRÁS ESQUERDA */};

	float angulosCorrendo[4][4] = { { -45, 0, 0, -80 }, /* FRENTE DIREITA */
	{ 0, -80, -45, 0 }, /* FRENTE ESQUERDA */
	{ 80, 45, 30, 60 }, /* TRÁS DIREITA */
	{ 30, 60, 80, 45 } /* TRÁS ESQUERDA */};

};

#endif
