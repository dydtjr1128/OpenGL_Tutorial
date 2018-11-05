#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
int FlatShaded = 0; int Wireframed = 0;
//flatshading과 wireframe을 토글링하기 위한 부울 변수

int ViewX = 0, ViewY = 0;
//마우스 움직임에 따라 시점을 바꾸기 위한 변수

void InitLight() {
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyMouseMove(GLint X, GLint Y) {
	//마우스 움직임 X,Y를 전역 변수인 ViewX, ViewY에 할당
	ViewX = X;
	ViewY = Y;	 
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q': case 'Q': case '\033':
		exit(0);
		break;
	case 's':
		if (FlatShaded) {
			FlatShaded = 0;
			glShadeModel(GL_SMOOTH);
		}
		else {
			FlatShaded = 1;
			glShadeModel(GL_FLAT);
		}
		glutPostRedisplay();
		break;
		//여기에 와이어 프레임 토글링을 위한 코드를 삽입할 것
		//위의 전역 변수 Wireframed를 사용할 것
	}
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//단위행렬로 만들어라 translate 초기화 아래 또써도 초기화됨

	//gluLookAt((ViewX-200)/400.0, (ViewY-200)/400.0, 1.0,//3개씩 끊어서 읽음 내눈이 여기를 봄
	//		0.0, 0.0, 0.0, 
	//		1.0, 1.0, 0.0);
	gluLookAt(0.0, 1.0, 0.000000,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0
	);
	//마우르 움직임에 따라 시점을 변화 시키려면
	//MyMouseMove함수에서 입력되는 변화량을 참고하여
	//gluLookAt 명령어 파라미터를 변경해볼 것 (교재 참조)
	//아래에 필요한 물체 드로잉 명령을 삽입할 것
	glutSolidTeapot(0.2);	//예
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-0.5, -0.15, -0.5);
	glVertex3f(0.5, -0.15, -0.5);
	glVertex3f(0.5, -0.15, 0.5);
	glVertex3f(-0.5, -0.15, 0.5);
	glEnd();
	glTranslatef(0.4, -0.05, 0.0);
	glutSolidSphere(0.1, 20, 20);
	glTranslatef(-0.1, -0.02, 0.2);
	glutSolidTorus(0.05, 0.03, 20, 20);
	glTranslatef(0.1, 0.0, -0.39);
	glutSolidCone(0.08, 0.05, 20, 20);
	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 2.0, -3.0, 3.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMotionFunc(MyMouseMove);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}

/*
삼각형 매시가 더안정적임 하지만 사각형메시보다 다각형수가 더필요
와이어프레임이빠르고 솔리드프레임이 느리고 별로안중요
어파인공간 = 점과 벡터를 동족처럼 취급함으로써 벡터공간을 확장
점끼리 덧셈은 안되고(계수의 합이 1일때만 예외로 허용함 어파인Sum이라고함) 점끼리 뺄셈은 됨
V = P + (1/2)(Q - P)  : 점 = 점 + 벡터
V = P + t (Q - P)  = (1 - t)P + (t)Q  (0 ≤ t ≤ 1) : 점 = 점 + 점?

(1, 2, 1, 1) = (2, 4, 2, 2) = (3, 6, 3, 3)
(6, 4, 8, 2) 의 실제 좌표는? 3,2,4,1
같은점이 다른좌표계에서는 다른점으로 표현됨
전단 안함
*/