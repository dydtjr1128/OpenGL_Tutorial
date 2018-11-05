#include <gl/glut.h>
/*void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);	
	glVertex3f(1.0, 0.0, 0.0);	
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);	
	glEnd();
	glColor3f(1.0, 0.7, 1.0);

	glBegin(GL_TRIANGLES);	
	glVertex3f(0.3, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.3, 0.0, 0.0);
	

	glVertex3f(0.3, 0.0, 0.0);
	glVertex3f(0.9, 0.0, 0.0);
	glVertex3f(0.4, -0.4, 0.0);

	glVertex3f(-0.3, 0.0, 0.0);
	glVertex3f(-0.9, 0.0, 0.0);
	glVertex3f(-0.4, -0.4, 0.0);

	glVertex3f(0.4, -0.4, 0.0);
	glVertex3f(0.6, -0.9, 0.0);
	glVertex3f(0.0, -0.7, 0.0);

	glVertex3f(-0.4, -0.4, 0.0);
	glVertex3f(-0.6, -0.9, 0.0);
	glVertex3f(0.0, -0.7, 0.0);
	
	glEnd();
	glFlush();
}*/

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);       //GL ���º��� ���� ����°�,
	glViewport(100, 0, 150, 150);	//100��ŭ��� �ű⼭ 150��ŭ �� 100~250
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(45, 0, 1, 0);
	glTranslatef(0.3, 0.1, 0);
	glutWireSphere(0.2, 10, 10);
	glBegin(GL_POLYGON);                //�Է� �⺻��� ����	
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {//glut�Լ��� �»���� ����  opengl�� ���ϴ� ���� ����Ʈ������ ���ϴܱ���, glut �����������,��ġ������ �»�ܱ���
	//glutCreateWindow("OpenGL Drawing Example");
	//glutDisplayFunc(myDisplay);
	//glutMainLoop();
	//return 0;
	glutInit(&argc, argv);               //GLUT ������ �Լ�
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(1.0, 0.0, 0.0, 1.0);   //GL ���º��� ���� r,g,b,alpa
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT �ݹ��Լ� ���
	glutMainLoop();                     //�̺�Ʈ ���� ����
	return 0;
}