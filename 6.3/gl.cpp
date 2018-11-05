#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
float theta = 0.0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.5+0.2, 0.5, 0.0);
	//glVertex3f(-0.5 + 0.2, -0.5, 0.0);
	//glVertex3f(0.5 + 0.2, -0.5, 0.0);
	//glVertex3f(0.5 + 0.2, 0.5, 0.0);
	//glEnd();
	glTranslatef(0.25, 0.25, 0.0);//�����̵��ؼ�
	glRotatef(theta, 0.0, 0.0, 1.0);//45��ȸ���ؼ� ���Ʒ� �ٲٸ� ��ġ�ٸ�		
	//glTranslatef(-0.25, -0.25, 0.0);//�����̵��ؼ�
	
	
	glutSolidCube(0.5);//solidcube�� �׷���
	glFlush();
}
void MyIdle() {
	theta += 0.1;
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}
