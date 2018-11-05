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
	//glEnableClientState(GL_VERTEX_ARRAY);//�迭�� ����ϰڴ� ����
	//glColorPointer(3, GL_FLOAT, 0, MyColors);
	//glVertexPointer(3, GL_FLOAT, 0, MyVertices);//3����,float���о��, �̰����� �迭�� ������ �̰ɷ� 0����, 1���� �� �˼� ����
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glRotatef(30.0, 1.0, 1.0, 1.0);
	//opengl �Լ� �ϳ��θ��°��� ���������� �ʿ��� �ִ��� ���Ժθ��°�����
	/*glColor3fv(MyColors[0]); glVertex3fv(MyVertices[0]);
	glColor3fv(MyColors[3]); glVertex3fv(MyVertices[3]);
	glColor3fv(MyColors[2]); glVertex3fv(MyVertices[2]);
	glColor3fv(MyColors[1]); glVertex3fv(MyVertices[1]);*///���� �̷��� ���ߵǴµ� �Ʒ��Լ��� �̿��� ���� ����

	//for (GLint i = 0; i < 6; i++)
	//	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);//�����ܱ׸��ڴ�,4���� ���,����Ʈ��,�迭������ �׷���
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