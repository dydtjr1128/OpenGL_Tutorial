#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
static int Day = 0, Time = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 20, 16);

	glPushMatrix();
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
		glTranslatef(0.7, 0.0, 0.0);
		//glPushMatrix();
			//glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);//자전
			glColor3f(0.5, 0.6, 0.7);
			glutWireSphere(0.1, 10, 8);//지구
		//glPopMatrix();
		glPushMatrix();
			glRotatef((GLfloat)Time*2, 0.0, 1.0, 0.0);//지구 자전의영향으로 z축 들어짐 지구에도 팝푸쉬하면 자전안걸림
			glTranslatef(0.2, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'd':
		Day = (Day + 10) % 360;
		glutPostRedisplay();
		break;
	case 't':
		Time = (Time + 5) % 360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void myIdele(int val) {
	Day++;
	Time++;
	glutPostRedisplay();
	glutTimerFunc(10, myIdele, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	//glutIdleFunc(myIdele);
	glutTimerFunc(10, myIdele, 1);	
	glutMainLoop();
	return 0;
}