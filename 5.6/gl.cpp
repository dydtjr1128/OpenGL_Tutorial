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

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {//파라미터 갯수는 규약이기때문에 그대로 써야함 함수이름만 바꿀수 있음
	//x,y는 마우스위치임 즉 같은키를쳐도 마우스위치에따라 다르게 작동하게할수 있음 xy는 glut좌표계 아래,오른쪽으로갈수록 커짐
	switch (KeyPressed) {
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:                //'esc' 키의 아스키 코드 값
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

int main(int argc, char** argv) {// cmd같은데서 gl(exe이름) arg1 arg2 엔터 치면 값2개가 main 매개변수로 전달됨 이경우는 선언되있지만 0값
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
