#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <stdio.h>
float mx = 0.0;
float mx2 = 0.0;
int right = 1;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);       //컬러버퍼에 초기화 색을 가함
	glColor3f(0.5, 0.5, 0.5);           //회색
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, -0.7, 0.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 1.0
	);
	glPushMatrix();
	glBegin(GL_POLYGON);                //사각형
		glVertex3f(-0.5, -0.5, 0.0);    //좌하단 좌표
		glVertex3f(0.5, -0.5, 0.0);     //좌하단 좌표
		glVertex3f(0.5, 0.5, 0.0);      //우상단 좌표
		glVertex3f(-0.5, 0.5, 0.0);     //좌상단 좌표
	glEnd();
	glPopMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(0.0+mx, 0.0, 0.3);
		glutWireSphere(0.3,30,10);
		glPushMatrix();
			glTranslatef(0.3, 0.0, 0.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			glutWireCone(0.05, 0.4, 30, 10);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.18);
			glRotatef(50, 0.0, 1.0, 0.0);
			glutWireCone(0.05, 0.4, 30, 10);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0+mx2, 0.0, 0.75);
		glutWireSphere(0.15, 30, 10);	
		glPushMatrix();
			glTranslatef(0.15, 0.0, 0.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			glutWireCone(0.05, 0.15, 30, 10);
		glPopMatrix();
	glPopMatrix();
	glFlush();
}
void myTimer(int val) {
	//mx += 0.01;
	
	if (mx2 < 0.07 && mx2 > -0.07) {
		printf("%f  %d \n", mx2,right);
		if (right == 1) {
			mx2 += 0.01;
		}
		else if(right==0) {
			
			mx2 -= 0.01;
		}
	}
	else if (mx2 <= -0.07) {
		mx2 += 0.01;
		right = 1;
	}
	else if (mx2 >= 0.07) {
		printf("rrrrrrrrrrrrrrrrrr");
		right = 0;
		mx2 -= 0.01;
		
	}

	if (mx >= 0.5)
		mx = 0.0;
	glutPostRedisplay();
	glutTimerFunc(40, myTimer, val);
}

int main(int arg, char **arg2) {
	glutInit(&arg, arg2);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	glutCreateWindow("OepnGL Review");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, myTimer, 1);
	glutMainLoop();
}