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
	glClear(GL_COLOR_BUFFER_BIT);       //GL 상태변수 설정 지우는것,
	glViewport(100, 0, 150, 150);	//100만큼띄고 거기서 150만큼 즉 100~250
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(45, 0, 1, 0);
	glTranslatef(0.3, 0.1, 0);
	glutWireSphere(0.2, 10, 10);
	glBegin(GL_POLYGON);                //입력 기본요소 정의	
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {//glut함수는 좌상단이 기준  opengl은 좌하단 기준 뷰포트같은건 좌하단기준, glut 윈도우사이즈,위치같은건 좌상단기준
	//glutCreateWindow("OpenGL Drawing Example");
	//glutDisplayFunc(myDisplay);
	//glutMainLoop();
	//return 0;
	glutInit(&argc, argv);               //GLUT 윈도우 함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(1.0, 0.0, 0.0, 1.0);   //GL 상태변수 설정 r,g,b,alpa
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);         //GLUT 콜백함수 등록
	glutMainLoop();                     //이벤트 루프 진입
	return 0;
}