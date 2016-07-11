#ifndef CABECA
#define CABECA

#include <GL/glut.h>

class Cabeca {

public:
	void desenhar(const bool caminhada, const int estagio) {
		glPushMatrix();
		glScalef(0.35, 0.35, 0.35);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();

		// fucinho
		if (caminhada) {
			glRotatef(110, 0, 1, 0);
		} else {
			glRotatef(70, 0, 1, 0);
		}

		glTranslatef(0.1, 0, 0.2);
		glColor3f(1, 0, 0);
		gluCylinder(gluNewQuadric(), 0.38, 0.18, 0.8, 30, 30);
		glTranslatef(0, 0, 0.8);
		glScalef(0.18, 0.18, 0.18);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();
	}
};

#endif
