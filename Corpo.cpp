#ifndef CORPO
#define CORPO

#include <GL/glut.h>
#include "Perna.cpp"
#include "Pescoco.cpp"
#include "Cabeca.cpp"
#include <iostream>

using namespace std;

class Corpo {
private:
	static constexpr double COMPRIMENTO_TRONCO = 3.2;
	static constexpr double LARGURA_TRONCO = 1;
	static constexpr double LARGURA_NADEGAS = 1.15;

	Perna perna;
	Pescoco pescoco;
	Cabeca cabeca;

public:
	void desenhar(const bool caminhada, const int estagio) {
		glPushMatrix();
		glColor3f(0.72f, 0.65f, 0.13f);

		double alturaTronco = 0;
		double metadeTronco = COMPRIMENTO_TRONCO / (double) 2;
		double metadeNadegas = LARGURA_NADEGAS / (double) 2;

		if (caminhada) {
			alturaTronco = this->alturaTroncoCaminhada[estagio];
		} else {
			alturaTronco = this->alturaTroncoTrote[estagio];
		}

		glTranslatef(0, alturaTronco, 0);

		glRotatef(90, 0, 1, 0);
		gluCylinder(gluNewQuadric(), LARGURA_TRONCO * 0.92, LARGURA_TRONCO * 1,
				metadeTronco, 30, 30); // Parte frontal

		glRotatef(-180, 0, 1, 0);

		gluCylinder(gluNewQuadric(), LARGURA_TRONCO * 0.92,
				LARGURA_TRONCO * 1.07, metadeTronco, 30, 30); // Parte traseira
		glRotatef(90, 0, 1, 0);

		glTranslatef(-metadeTronco * 0.95, 0, 0);
		glScalef(1.5, 1.2, LARGURA_NADEGAS);
		glutSolidSphere(1, 20, 20);

		glPushMatrix();
		// Desenhar rabo
		glPopMatrix();

		glTranslatef(0, -alturaTronco, 0);

		glTranslatef(0, 0, -metadeNadegas * 0.9);
		perna.desenhar(caminhada, estagio, 3);
		glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
		perna.desenhar(caminhada, estagio, 2);

		glTranslatef(0, alturaTronco, 0);
		glTranslatef(COMPRIMENTO_TRONCO * 0.8, 0, -metadeNadegas * 0.9);
		glScalef(1.2, 1, LARGURA_NADEGAS);
		glutSolidSphere(1, 20, 20); // Peitoral
		glTranslatef(0, -alturaTronco, 0);

		glTranslatef(0, 0, -metadeNadegas * 0.9);
		perna.desenhar(caminhada, estagio, 1);
		glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
		perna.desenhar(caminhada, estagio, 0);
		glTranslatef(0, 0, -metadeNadegas * 0.9);

		glTranslatef(0, alturaTronco, 0);

		pescoco.desenhar(caminhada, estagio);

		cabeca.desenhar(caminhada, estagio);
	}

private:
	const double alturaTroncoCaminhada[6] =
			{ 0.09, 0.05, 0.02, 0.09, 0.05, 0.02 };

	const double alturaTroncoTrote[4] = { 0, 0.1, 0, 0.1 };

};

#endif
