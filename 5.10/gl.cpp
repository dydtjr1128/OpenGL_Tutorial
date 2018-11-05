#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

GLfloat Delta = 0.0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + Delta, -0.5 + Delta, 0.0);
	glVertex3f(0.0 + Delta, -0.5 + Delta, 0.0);
	glVertex3f(0.0 + Delta, 0.5 +0.5*cos(50 * Delta), 0.0);
	glVertex3f(-1.0 + Delta, 0.5 +0.5*sin(50*Delta), 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyIdle() {//중요
	Delta = Delta + 0.000001;
	glutPostRedisplay();// MyDisplay() 부름
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyIdle);//중요 할일없을때 이거 돌림 애니메이션 만드는데 활용됨 할일 없으면 계속 불림
	glutMainLoop();
	return 0;
}
