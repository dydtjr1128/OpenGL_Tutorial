#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int IsSphere = 1;
GLint r = 5;//그냥인트는 어떤컴퓨터에서는 2바이트일수도 4,8일수도있으므로 이것은 표준으로 정해놓음

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	//p184
	//glutWireCone(0.4, 0.2, 20,20);
	//glutWireIcosahedron();
	if (IsSphere == 0)//시험!! 파라메터가 의미하는것은?		
		glutSolidSphere(0.8, 6, 130);//첫번째는 크기,몇각형인지(위도를 몇등분할지),경도를 몇등분할지
	else if (IsSphere == 1)
		glutSolidTorus(0.5, 0.5, 5, 50);//가운데뺀 지름, 지름, 정밀함(위도), 촘촘함(몇각형인지)
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
