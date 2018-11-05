#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
int key = 0;
int keyx = 0;
int keyy = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (key == 1) {
		glColor3f(1.0, 0.0, 0.0);
	}
	else if (keyx != 0) {
		glColor3f(keyx/255.0,keyy/255.0,0.0);
	}
	else {
		glColor3f(0.5, 0.5, 0.5);
	}
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {//�Ķ���� ������ �Ծ��̱⶧���� �״�� ����� �Լ��̸��� �ٲܼ� ����
	//x,y�� ���콺��ġ�� �� ����Ű���ĵ� ���콺��ġ������ �ٸ��� �۵��ϰ��Ҽ� ���� xy�� glut��ǥ�� �Ʒ�,���������ΰ����� Ŀ��
	switch (KeyPressed) {
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:                //'esc' Ű�� �ƽ�Ű �ڵ� ��
		exit(0); break;
	case 'c':	
		key = 1;
		glutPostRedisplay();
		break;
	case 'd':
		keyx = X;
		keyy = Y;		
		glutPostRedisplay();
		printf("%c %d  %d\n",KeyPressed, X, Y);
		break;
	}
	printf("%c %d",KeyPressed, X);
}

int main(int argc, char** argv) {// cmd�������� gl(exe�̸�) arg1 arg2 ���� ġ�� ��2���� main �Ű������� ���޵� �̰��� ����������� 0��
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutCreateWindow("dd");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	/*glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();*/
	return 0;
}
