#ifndef CORPO
#define CORPO

#include <GL/glut.h>
#include "Perna.cpp"
#include "Pescoco.cpp"
#include "Cabeca.cpp"
#include <iostream>

class Corpo {
private:
	static constexpr double COMPRIMENTO_TRONCO = 3;
	static constexpr double LARGURA_TRONCO = 1;
	static constexpr double LARGURA_NADEGAS = 1;

	Perna perna;
	Pescoco pescoco;
	Cabeca cabeca;

public:
	void desenhar(const bool caminhada, const double estagio) {
		glPushMatrix();
		glColor3f(0.855f, 0.784f, 0.682f);

		double alturaTronco = 0;
		double metadeTronco = COMPRIMENTO_TRONCO / (double) 2;
		double metadeNadegas = LARGURA_NADEGAS / (double) 2;

		if (caminhada) {
			alturaTronco = this->alturaTroncoCaminhada[(int) estagio];
		} else {
			alturaTronco = this->alturaTroncoTrote[(int) estagio];
		}

		glTranslatef(metadeTronco, alturaTronco, 0);

		glRotatef(90, 0, 1, 0);
		gluCylinder(gluNewQuadric(), LARGURA_TRONCO, LARGURA_TRONCO,
				COMPRIMENTO_TRONCO, 30, 30); // Parte frontal

		glRotatef(90, 0, 1, 0);

		glTranslatef(-metadeTronco * 2, 0, 0);
		glScalef(1.2, 1.1, LARGURA_NADEGAS);
		glutSolidSphere(1, 20, 20);

		glTranslatef(0, -alturaTronco, 0);

		glTranslatef(0, 0, -metadeNadegas * 0.9);
		perna.desenhar(caminhada, estagio, 3);
		glColor3f(0.855f, 0.784f, 0.682f);

		glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
		perna.desenhar(caminhada, estagio, 2);
		glColor3f(0.855f, 0.784f, 0.682f);

		glTranslatef(0, alturaTronco, 0);
		glTranslatef(COMPRIMENTO_TRONCO * 0.8, 0, -metadeNadegas * 0.9);
		glScalef(1.2, 1, LARGURA_NADEGAS);
		glutSolidSphere(1, 20, 20); // Peitoral
		glTranslatef(0, -alturaTronco, 0);

		glTranslatef(0, 0, -metadeNadegas * 0.9);
		perna.desenhar(caminhada, estagio, 1);
		glColor3f(0.855f, 0.784f, 0.682f);

		glTranslatef(0, 0, LARGURA_NADEGAS * 0.9);
		perna.desenhar(caminhada, estagio, 0);
		glColor3f(0.855f, 0.784f, 0.682f);

		glTranslatef(0, 0, -metadeNadegas * 0.9);

		glTranslatef(0, alturaTronco, 0);

		pescoco.desenhar(caminhada, estagio);

		cabeca.desenhar(caminhada, estagio);
	}

private:
	const double alturaTroncoCaminhada[6] =
			{ 0.1, 0.05, 0.025, 0.1, 0.05, 0.025 };

	const double alturaTroncoTrote[8] = { 0.1, 0.075, 0.05, 0.025, 0.05, 0.075,
			0.1, 0.075 };

};

#endif
