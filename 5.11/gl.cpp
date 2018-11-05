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
	glutSwapBuffers();//���� ���۸��� ����,  ����Ʈ ���ۿ� �� ���۸� �ٲٴµ�  ���μ��� ä������ �ٲ㼭 ä��� �ϴ� ���
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
	
	glutTimerFunc(40, MyTimer, 1);  //40ms���� timer�� ���� idelfunc�� ��ǻ�� ���ɿ� �¿��, �׸��� ��� �ð��� ���� ������ �ӵ����� ���Ѵٸ� timerfunc ���
	//timer�� ���½ð��� ���� �׽ð��� �ٸ��ڿ��Ҵ簡��
	//�ϵ��ھ�� �ִ��� �ε巴���Ϸ��� idle�� ����
	glutMainLoop();
	return 0;
}
