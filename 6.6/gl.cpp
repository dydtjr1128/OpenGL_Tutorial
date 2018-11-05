#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
static int Day = 0, Time = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);//빨간색
	glutWireSphere(0.2, 20, 16);//태양
	glPushMatrix();//	
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);//공전
		glTranslatef(0.7, 0.0, 0.0);//평행이동
		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);//자전
		glColor3f(0.5, 0.6, 0.7);//푸른색		
		glutWireSphere(0.1, 10, 8);//지구

		glPushMatrix();//지구를 기준으로 한 추가 변환
			glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
			glTranslatef(0.2, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);//누런색
			glutWireSphere(0.04, 10, 8);//달			
			//달이 지구자전과 겹치므로 상대적으로 한번더
		glPopMatrix();//1번달 변화 무효화, 지구변환만 유지

		glPushMatrix();//지구를 기준으로 한 추가 변환
			glRotatef((GLfloat)Time*1.2, 0.5, 1.0, 0.0);
			glTranslatef(-0.2, 0.15, 0.0);
			glColor3f(0.5, 0.3, 0.8);//보라
			glutWireSphere(0.05, 10, 8);//달
		glPopMatrix();
		
		glPushMatrix();
			glRotated((GLfloat)Time*1.7,-1.0, 1.0, 0.0);
			glTranslated(0.15, 0.2, 0.0);
			glColor3f(0.1, 0.6, 0.3);
			glutWireSphere(0.06,15,10);
		glPopMatrix();

	glPopMatrix();//태양에대한 팝

	glPushMatrix();//
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);//공전
		glTranslatef(0.35, 0.0, 0.0);//평행이동
		//glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);//자전
		glColor3f(0.7, 0.1, 0.7);//푸른색
		glutWireSphere(0.06, 10, 8);//금성
		glPushMatrix();
			glRotatef((GLfloat)Time*1.6,-1.0, 1.0, 0.0);
			glTranslatef(-0.1, -0.1, 0.0);
			glColor3f(0.8, 0.8, 0.8);
			glutWireSphere(0.04,10,10);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glRotated((GLfloat)Time*0.8, 1.0, -0.2, 0.0);
		glTranslated(0.2, 0.5, 0.0);
		glColor3f(0.5, 0.6, 0.3);
		glutWireSphere(0.1, 15, 10);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat)Time*1.1, -0.5, 0.5, 0.0);
		glTranslatef(-0.4, -0.35, 0.0);
		glColor3f(0.8, 0.8, 0.8);
		glutWireSphere(0.08, 10, 10);
	glPopMatrix();
	glutSwapBuffers();
}
void MyKeyboard(unsigned char key, int x, int y) {
	printf("%d\n", Day);
	switch (key) {		
	case 'd':
		Day = (Day + 10);
		glutPostRedisplay();
		break;
	case 't':
		Time = (Time + 5);
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void myIdele(int val) {
	Day++;
	Time++;
	glutPostRedisplay();
	glutTimerFunc(10, myIdele, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	//glutIdleFunc(myIdele);
	glutTimerFunc(40, myIdele, 1);
	glutMainLoop();
	return 0;
}