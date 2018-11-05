#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int IsSphere = 1;
GLint r = 5;//�׳���Ʈ�� ���ǻ�Ϳ����� 2����Ʈ�ϼ��� 4,8�ϼ��������Ƿ� �̰��� ǥ������ ���س���

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	//p184
	//glutWireCone(0.4, 0.2, 20,20);
	//glutWireIcosahedron();
	if (IsSphere == 0)//����!! �Ķ���Ͱ� �ǹ��ϴ°���?		
		glutSolidSphere(0.8, 6, 130);//ù��°�� ũ��,�������(������ ��������),�浵�� ��������
	else if (IsSphere == 1)
		glutSolidTorus(0.5, 0.5, 5, 50);//����� ����, ����, ������(����), ������(�������)
	else if (IsSphere == 2)
		glutSolidTeapot(0.5);
	
	//glutSwapBuffers();
	glFlush();
}

void MyMainMenu(int entryID) {
	if (entryID == 1)
		IsSphere = 0;
	else if (entryID == 2)
		IsSphere = 1;
	else if (entryID == 3) {
		IsSphere = 2;
	}
	else if (entryID == 4)
		exit(0);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddMenuEntry("Draw Tipot", 3);
	glutAddMenuEntry("Exit", 4);	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
