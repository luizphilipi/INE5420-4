#ifndef MAIN
#define MAIN

#include <GL/glut.h>
#include <unistd.h>
#include "Corpo.cpp"

int janela;
unsigned int larguraJanela = 800;
unsigned int alturaJanela = 600;

bool modoCaminhada = true;
double anguloModelo = 0;
int estagioAtual = 0;
int quantEstagios = 6;

void desenharChao() {
	glPushMatrix();
	glColor3f(0.004f, 0.651f, 0.067f);
	glTranslatef(0, -190, -550);
	glRotatef(90, 1.0, 0.0, 0.0);
	glRectf(-10000, -10000, 10000, 10000);
	glPopMatrix();
}

void redesenharMundo() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat luz[] = { 0.5f, 0.5f, 0.5f, 1.0 };
	GLfloat posicaoLuz[] = { 0, 50, 0, 0.0f };

	glLightfv(GL_LIGHT0, GL_SPECULAR, luz);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luz);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	desenharChao();

	glTranslatef(0, 0, -8);
	glRotatef(anguloModelo, 0.0f, 1.0f, 0.0f);

	Corpo cavalo;
	cavalo.desenhar(modoCaminhada, estagioAtual);

	glutSwapBuffers();

	usleep(150000);

	estagioAtual++;
	estagioAtual = estagioAtual % quantEstagios;
}

/**
 * Redimensionar a janela.
 */
void redimensionarJanela(int largura, int altura) {
	larguraJanela = largura;
	alturaJanela = altura;

	glViewport(0, 0, larguraJanela, alturaJanela);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (float) larguraJanela / (float) alturaJanela, 1.0,
			5000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
 * Tecla comum pressionada.
 */
void tecla(unsigned char tecla, int x, int y) {
	switch (tecla) {
	case 27: // Tecla ESC
		glutDestroyWindow(janela);
		exit(0);
		break;
	case 97: // Tecla A
		anguloModelo += 5;
		break;
	case 100: // Tecla D
		anguloModelo -= 5;
		break;
	case 114: // Tecla R
		if (modoCaminhada) {
			quantEstagios = 8;
		} else {
			quantEstagios = 6;
		}
		modoCaminhada = !modoCaminhada;
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(larguraJanela, alturaJanela);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - larguraJanela) / 2,
			(glutGet(GLUT_SCREEN_HEIGHT) - alturaJanela) / 2);
	janela = glutCreateWindow("Modelo Hierárquico de um Cavalo");

	glutReshapeFunc(redimensionarJanela);
	glutDisplayFunc(redesenharMundo);
	glutKeyboardFunc(tecla);
	glutIdleFunc(redesenharMundo);

	glClearColor(0.0f, 0.749f, 1.0f, 0.0);
	glClearDepth(5.0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glMatrixMode(GL_MODELVIEW);

	glutFullScreen();

	glutMainLoop();
	return 0;
}

#endif
