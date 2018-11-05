#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
int MyListID;
void MyCreateList() {
	MyListID = glGenLists(1);//gl에서 리스트관리해서 번호 하나 리턴해서 발급해줌 할당 
	glNewList(MyListID, GL_COMPILE);//여기부터 endList까지 하나의 명령어로 생각해라glNewList(1, GL_COMPILE) 이건 1번 명령이고 실행하지말고 컴파일만 해라 
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
	glCallList(MyListID);//똑같은명령 반복실행시 이렇게하면 효율적 색바뀌거나해야되면 안됨
	glFlush();//싱글버퍼링
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
