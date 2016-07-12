#ifndef PERNA
#define PERNA

#include "Coxa.cpp"
#include "Casco.cpp"
#include "Canela.cpp"
#include <GL/glut.h>

/**
 * FRENTE_DIREITA = 0,
 * FRENTE_ESQUERDA = 1,
 * TRAS_DIREITA = 2,
 * TRAS_ESQUERDA = 3
 * */
class Perna {
public:
	Coxa coxa;
	Canela canela;
	Casco casco;

	void desenhar(const bool caminhada, const int estagio, const int idx) {
		glPushMatrix();

		coxa.desenhar(caminhada, estagio, idx);

		glPushMatrix();
		canela.desenhar(caminhada, estagio, idx);

		casco.desenhar(caminhada, estagio, idx);
		glPopMatrix();

		glPopMatrix();
	}
};

#endif
