#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat Delta = 0.0;
int XX = 300;
int YY = 300;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();//더블 버퍼링에 쓰임,  프론트 버퍼와 백 버퍼를 바꾸는데  서로서로 채워지면 바꿔서 채우고 하는 방식
}

void MyTimer(int Value) {
	Delta = Delta + 0.001;
	glutPostRedisplay();
	glutTimerFunc(1, MyTimer, 1);
}
void res(int w, int h) {
	XX = w;
	YY = h;
	glViewport(0, 0, XX,YY);
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
	glutReshapeFunc(res);
	
	glutTimerFunc(40, MyTimer, 1);  //40ms마다 timer을 깨움 idelfunc는 컴퓨터 성능에 좌우됨, 그리고 노는 시간이 없음 균일한 속도등을 원한다면 timerfunc 사용
	//timer은 쉬는시간에 쉬고 그시간에 다른자원할당가능
	//하드코어로 최대한 부드럽게하려면 idle이 나음
	glutMainLoop();
	return 0;
}
