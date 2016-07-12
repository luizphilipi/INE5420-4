#ifndef PESCOCO
#define PESCOCO

#include <GL/glut.h>

class Pescoco {

public:
	void desenhar(const bool caminhada, const int estagio) {
		glRotatef(-90, 1, 0, 0);

		if (caminhada) {
			glRotatef(angulosCaminhando[estagio], 0, 1, 0);
		} else {
			glRotatef(angulosCorrendo[estagio], 0, 1, 0);
		}
		gluCylinder(gluNewQuadric(), 0.7, 0.35, 2.3, 30, 30);
		glTranslatef(0, 0, 2.3);
	}

	float angulosCaminhando[6] = { 35, 30, 25, 30, 35, 40 };

	float angulosCorrendo[8] = { 45, 42.5, 40, 38.5, 35, 38.5, 40, 42.5 };

};

#endif
