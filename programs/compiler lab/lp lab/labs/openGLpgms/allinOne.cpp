#include<stdio.h>
#include<stdlib.h>

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

float size_x=0.5;
float size_y=0.5;
float rot_ang=0.0;
float ball_x=-1.0;
float ball_y=0.0;
static int flag=0;
float bb_x=0.5;
float bb_y=-0.25;
static int flag_bb=0;
float bg_b=0.1;

void reshape(int w,int h)
{
	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45,w/h,1,200);
}

void keyPressed(int key,int x,int y)
{
	if(key==GLUT_KEY_UP)
	{size_x+=0.05;size_y+=0.05;}

	if(key==GLUT_KEY_DOWN)
	{size_x-=0.05;size_y-=0.05;}

	if(key==GLUT_KEY_RIGHT)
		rot_ang+=5;
	if(key==GLUT_KEY_LEFT)
		rot_ang-=5;

	//glutPostRedisplay();
}

void drawBall()
{
	glColor3f(1,0.5,0.1);

	glPushMatrix();

		glTranslatef(ball_x,ball_y,-1);
		glutSolidSphere(0.1,20,20);

	glPopMatrix();

}

void update()
{
	
	if(!flag)
	{
		if(ball_x>-0.25)
		{
			ball_x+=0.005;
			ball_y+=0.005;
		}
		else
			ball_x+=0.005;
		if(ball_x>0)
			flag=1;

	}

	if(flag)
	{
		if(ball_y>0.025)
		{
			ball_x+=0.005;
			ball_y-=0.005;
		}
		else
			ball_x+=0.005;
		//if(ball_x>0)
			//flag=1;

	}

	if(ball_x>1)
	{
		ball_x=-1;
		ball_y=0;
		flag=0;
	}


}



void bouncingBall()
{
	glPushMatrix();

		glColor3f(1,0,0);
		glTranslatef(bb_x,bb_y,0);
		glutSolidSphere(0.1,30,30);

	glPopMatrix();
}

void updateBB(){

	if(!flag_bb)
	{
		bb_y-=0.008;
		if(bb_y<-0.9)
			flag_bb=1;
	}
	if(flag_bb)
	{
		bb_y+=0.005;
		if(bb_y>-0.25)
			flag_bb=0;
	}
}

void updateBg()
{
	bg_b+=0.005;
	if(bg_b>1)
		bg_b=0.1;
}


void display()
{
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

	glClearColor(0,0.1,bg_b,0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

/***************************triangle centred*********************************/
	glPushMatrix();

	//glTranslatef(0.5,0.5,0);

	//glRotatef(rot_ang,0,1,-1);

	glScalef(0.5,0.5,0.5);

	glBegin(GL_POLYGON);
		
		glColor3f(1,0.1,0.1);
	
		glVertex3f(-0.25,0,-1);

		glVertex3f(0.25,0,-1);

		glVertex3f(0,0.25,-1);

	glEnd();

	glPopMatrix();
	
/***********************triangle right upper corner*********************************/

	
	glPushMatrix();
	
	//glScalef(0.5,0.5,0.5);
	glScalef(size_x,size_y,0.5);
	glTranslatef(1,1,0);

	//glRotatef(rot_ang,0,1,-1);

	

	glBegin(GL_POLYGON);

		
		glColor3f(0,1,0);
	
		glVertex3f(-1,0,-1);

		glVertex3f(1,0,-1);

		glVertex3f(0,1,-1);

	glEnd();

	glPopMatrix();

	//rot_ang+=5;

/********************left upper corner**************************************/
	glPushMatrix();

	//glTranslatef(0.5,0.5,-0.5);

	glRotatef(rot_ang,-0.75,1,-1);

	glBegin(GL_TRIANGLES);

		glColor3f(1.5,1,0.05);
	
		glVertex3f(-1.0,0.5,-1);

		glVertex3f(-0.5,0.5,-1);

		glVertex3f(-0.75,1,-1);

	glEnd();
	glPopMatrix();
	rot_ang+=5;
/*********************************sphere**************************************/

	drawBall();

	update();

/***********************bouncing ball****************************************/
	bouncingBall();

	updateBB();

	updateBg();

	glutSwapBuffers();

}


void glutInitRendering()
{
	glEnable(GL_DEPTH_TEST);

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(500,600);

	glutCreateWindow("simple_to_advanced");

	glutInitRendering();

	glutDisplayFunc(display);

	glutIdleFunc(display);

	glutSpecialFunc(keyPressed);

	glutReshapeFunc(reshape);

	glutMainLoop();

}
