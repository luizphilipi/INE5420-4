#ifndef COXA
#define COXA

#include <GL/glut.h>

class Coxa {

public:
	void desenhar(const bool caminhada, const int estagio, const int perna) {
		glColor3f(0.855f, 0.784f, 0.682f);
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
	float angulosCaminhando[4][6] = { { 5, -5, -20, -10, 20, 25 }, /* FRENTE DIREITA */
	{ -10, 20, 25, 5, -5, -20 }, /* FRENTE ESQUERDA */
	{ -30, -35, -25, 15, 10, -10 }, /* TRÁS DIREITA */
	{ 15, 10, -10, -30, -35, -25 }, /* TRÁS ESQUERDA */};

	float angulosCorrendo[4][4] = { { 65, 30, -20, 20 }, /* FRENTE DIREITA */
	{ -20, 20, 65, 30 }, /* FRENTE ESQUERDA */
	{ -35, 15, -45, -55 }, /* TRÁS DIREITA */
	{ -45, -55, -35, 15 } /* TRÁS ESQUERDA */};

};

#endif
