#include<stdlib.h>

#ifdef __APPLE__
#include<GLUT/glut.h>
#include<openGL/openGL.h>

#else
#include<GL/glut.h>
#endif

float x=0.0f;

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}


void handleResize(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}


void drawWheel1()
{
	glColor3f(0.0,0.0,1.0);
	glTranslatef(-1.60,0.0,-5.0);

	glutSolidSphere(0.3,20,20);




}



void drawWheel2()
{
	glColor3f(0.0,0.0,1.0);
	glTranslatef(1.5,0.0,0.4);

	glutSolidSphere(0.3,20,20);
}



void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glBegin(GL_QUADS);
		
		glColor3f(0.0,1.0,1.0);

		glVertex3f(-2.0,0.0,-5.0);
		glVertex3f(0.0,0.0,-5.0);
		glVertex3f(0.0,1.0,-5.0);
		glVertex3f(-2.0,1.0,-5.0);

	glEnd();



	//glScalef(0.5,0.5,1.0);
	glBegin(GL_TRIANGLES);

		glColor3f(1.0,0.0,1.0);

		glVertex3f(1.0f, 0.0f, -5.0f);
		glVertex3f(0.0f, 1.0f, -5.0f);
		glVertex3f(-1.0f, 0.0f, -5.0f);

	glEnd();

	drawWheel1();

	drawWheel2();


	glutSwapBuffers();

}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	
	glutInitWindowSize(400,400);
	glutCreateWindow("khans_window");
	initRendering();

	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	glutMainLoop();

	return(0);
}

