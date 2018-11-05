#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat MyVertices[8][3] = {//xyz
	{ -0.25, -0.25, 0.25 },
	{ -0.25, 0.25, 0.25 },
	{ 0.25, 0.25, 0.25 },
	{ 0.25, -0.25, 0.25 },
	{ -0.25, -0.25, -0.25 },
	{ -0.25, 0.25, -0.25 },
	{ 0.25, 0.25, -0.25 },
	{ 0.25, -0.25, -0.25 }
};
GLfloat MyColors[8][3] = {
	{ 0.2, 0.2, 0.2 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};
GLubyte MyVertexList[24] = {
	0, 3, 2, 1,
	2, 3, 7, 6,
	0, 4, 7, 3,
	1, 2, 6, 5,
	4, 5, 6, 7,
	0, 1, 5, 4
};
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glColorPointer(3,GL_FLOAT,0,MyColors);
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(30.0, 1.0, 1.0, 1.0);	

	for (int i = 0; i < 6; i++) {
		glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,&MyVertexList[4*i]);
	}
	glFlush();
	

	//glClear(GL_COLOR_BUFFER_BIT);
	//glFrontFace(GL_CCW);
	//glEnable(GL_CULL_FACE);
	//glEnableClientState(GL_COLOR_ARRAY);
	//glEnableClientState(GL_VERTEX_ARRAY);//배열을 사용하겠다 선언
	//glColorPointer(3, GL_FLOAT, 0, MyColors);
	//glVertexPointer(3, GL_FLOAT, 0, MyVertices);//3개씩,float로읽어라, 이것으로 배열을 던지고 이걸로 0번점, 1번점 을 알수 있음
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glRotatef(30.0, 1.0, 1.0, 1.0);
	//opengl 함수 하나부르는것은 많은연산이 필요함 최대한 적게부르는게좋음
	/*glColor3fv(MyColors[0]); glVertex3fv(MyVertices[0]);
	glColor3fv(MyColors[3]); glVertex3fv(MyVertices[3]);
	glColor3fv(MyColors[2]); glVertex3fv(MyVertices[2]);
	glColor3fv(MyColors[1]); glVertex3fv(MyVertices[1]);*///원래 이렇게 찍어야되는데 아래함수를 이용해 쉽게 찍음

	//for (GLint i = 0; i < 6; i++)
	//	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);//폴리콘그리겠다,4개씩 묶어서,바이트로,배열가지고 그려라
	//glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}