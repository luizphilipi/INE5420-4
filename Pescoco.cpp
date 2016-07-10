#ifndef PESCOCO
#define PESCOCO

#include <GL/glut.h>

class Pescoco {

public:
	void desenhar(const bool caminhada, const int estagio) {
		glRotatef(-90, 1, 0, 0);

		if (caminhada) {
			glRotatef(25, 0, 1, 0);
		} else {
			glRotatef(55, 0, 1, 0);
		}
		gluCylinder(gluNewQuadric(), 0.7, 0.35, 2.3, 30, 30);
		glTranslatef(0, 0, 2.3);
	}
};

#endif
