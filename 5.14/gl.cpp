#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
int MyListID;
void MyCreateList() {
	MyListID = glGenLists(1);//gl���� ����Ʈ�����ؼ� ��ȣ �ϳ� �����ؼ� �߱����� �Ҵ� 
	glNewList(MyListID, GL_COMPILE);//������� endList���� �ϳ��� ��ɾ�� �����ض�glNewList(1, GL_COMPILE) �̰� 1�� ����̰� ������������ �����ϸ� �ض� 
		glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glEnd();
	glEndList();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	printf("%d",MyListID);
	glCallList(MyListID);//�Ȱ������ �ݺ������ �̷����ϸ� ȿ���� ���ٲ�ų��ؾߵǸ� �ȵ�
	glFlush();//�̱۹��۸�
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	MyCreateList();
	glutMainLoop();
	return 0;
}
