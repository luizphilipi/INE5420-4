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
		glColor3f(0, 0, 0);
		gluCylinder(gluNewQuadric(), 0.06, 0.1, 0.3, 30, 30);
		glTranslatef(0, 0, 0.2);

		glPopMatrix();
	}

private:
	float angulosCaminhando[4][6] = { { 30, 30, 30, -10, -30, -5 }, /* FRENTE DIREITO */
	{ -10, -30, -5, 30, 30, 30 }, /* FRENTE ESQUERDO */
	{ 0, -20, -50, -30, 10, 5 }, /* TRÁS DIREITO */
	{ -30, 10, 5, 0, -20, -50 } /* TRÁS ESQUERDO */};

	float angulosCorrendo[4][8] = { { 45, 22.5, 0, 22.5, 45, 22.5, 0, 22.5 }, /* FRENTE DIREITO */
	{ 45, 22.5, 0, 22.5, 45, 22.5, 0, 22.5 }, /* FRENTE ESQUERDO */
	{ -45, -22.5, 0, -22.5, -45, -22.5, 0, -22.5 }, /* TRÁS DIREITO */
	{ -45, -22.5, 0, -22.5, -45, -22.5, 0, -22.5 } /* TRÁS ESQUERDO */};

};

#endif
