#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

GLfloat x1, y1;
GLsizei tamanhoQuadrado = 50;

GLfloat xMove = 5.5f;
GLfloat yMove = 5.5f;

GLfloat LarguraJanela = 500.0f;
GLfloat AlturaJanela = 300.0f;

void desenha(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(x1, y1+tamanhoQuadrado);
		glVertex2i(x1, y1);
		
		glVertex2i(x1+tamanhoQuadrado, y1);
		glVertex2i(x1+tamanhoQuadrado, y1+tamanhoQuadrado);
	glEnd();
	glFlush();
}
void Iniciar(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	x1 = 180.0f;
	y1 = 100.0f;
}
void MudarTamanhoJanela(GLsizei LarguraJanela, GLsizei AlturaJanela){
	if(LarguraJanela == 0)AlturaJanela = 1;
	glViewport(0,0, LarguraJanela, AlturaJanela);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(LarguraJanela<=AlturaJanela){
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*AlturaJanela/LarguraJanela);
	}else{
		gluOrtho2D(0.0f, 250.0f*LarguraJanela/AlturaJanela, 0.0f, 250.0f);
	}
}
void MoveSozinho(int valor){
	if(x1>LarguraJanela-tamanhoQuadrado||x1<0){
		xMove = -xMove;
	}
	if(y1>AlturaJanela-tamanhoQuadrado||y1<0){
		yMove = -yMove;
	}
	x1 += xMove;
	y1 += yMove;

    glutPostRedisplay();
    glutTimerFunc(33,MoveSozinho, 1);
}
void Movimenta(int key, int x, int y){
	if(key == GLUT_KEY_UP){
		//y1+=yMove;
		if(yMove<0){
			yMove = -yMove;
		}
	}
	if(key == GLUT_KEY_DOWN){
		//y1-=yMove;
		if (yMove>0){
			yMove = -yMove;
		}
	}
	if(key == GLUT_KEY_RIGHT){
		//x1+=xMove;
		if(xMove<0){
			xMove = -xMove;
		}
	}
	if(key == GLUT_KEY_LEFT){
		//x1-=xMove;
		if (xMove>0){
			xMove = -xMove;
		}
	}
	glutPostRedisplay();
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(LarguraJanela, AlturaJanela);
	glutInitWindowPosition(100, 80);
	glutCreateWindow("QUADRADO");
	glutDisplayFunc(desenha);
	glutReshapeFunc(MudarTamanhoJanela);
	glutTimerFunc(33,MoveSozinho, 1);
	glutSpecialFunc(Movimenta);
	Iniciar();
	glutMainLoop();
}
