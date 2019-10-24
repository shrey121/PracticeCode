//
//  main.c
//  ball
//
//  Created by student on 26/07/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else 
#include<GL/glut.h>
#endif

//using namespace std;
int n;
/*float ballX = -0.3f;
 float ballY = 0.0f;
 float ballZ = -1.0f;*/
float ballX=-0.3f;
float ballY=-0.3f;
float ballZ=-1.0f;

 float ballX2 = 0.3f;
 float ballY2 = 0.0f;
 float ballZ2 = -1.0f;
 
float c1,c2,c3;
void drawBall(void) {
    
    glColor3f(1.5, 0.5, 0.3); //set ball colour
    glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
    glutSolidSphere (0.1, 40, 40); //create ball.
    
    
    
    
    
}

void init()
{
    printf("Enter the number of figures");
    scanf("%d",&n);
}



 
 void drawBall2(int k) {
 
 glColor3f(1.0, 1.0, 0.0); //set ball colour
 //glTranslatef(ballX2,ballY2,ballZ2); //moving it toward the screen a bit on creation
     //glTranslatef(0.0,0.0,-1.0);
     //glutSolidSphere (0.1, 4, 10); //create sun.
     //glutWireSphere(0.1,4,10);
     //glTranslatef(0.0,0.0,-1.0);
     //glutWireSphere(0.3,4,10);
     /*glBegin(GL_POLYGON);
     glVertex3f(0.05,0.05,0.0);
     glVertex3f(0.5,0.05,0.0);
     glVertex3f(0.5,0.5,0.0);
     glVertex3f(0.05,0.5,0.0);
     glEnd();
     */
     glBegin(GL_LINE_LOOP);
     glVertex3f(-0.25/k,-0.25/k,0.0);
     glVertex3f(0.25/k,-0.25/k,0.0);
     glVertex3f(0.25/k,0.25/k,0.0);
     glVertex3f(-0.25/k,0.25/k,0.0);
     glEnd();
     glBegin(GL_LINE_LOOP);
     glVertex3f(0.0,-0.25/k,0.0);
     glVertex3f(0.25/k,0.0,0.0);
     glVertex3f(0.0,0.25/k,0.0);
     glVertex3f(-0.25/k,0.0,0.0);
     glEnd();
     
     //glFlush();
     /*
     glBegin(GL_LINE);
     glVertex3f(0.25,0.25,0.0);
     glVertex3f(0.75,0.25,0.0);
     glEnd();
      */
 
 }
void drawRectangle() {
    glColor3f(0.0,1.0,0.0);
    glTranslatef(ballX2,ballY2,ballZ2); //moving it toward the screen a bit on creation
    
    //glTranslatef(0.3,0.0,-1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25,0.25,0.0);
    glVertex3f(0.75,0.25,0.0);
    glVertex3f(0.75,0.75,0.0);
    glVertex3f(0.25,0.75,0.0);
    glEnd();
    
}
 
 

/*void keyPress(int key, int x, int y)
{
  	if(key==GLUT_KEY_RIGHT)
		ballX -= 0.05f;
	if(key==GLUT_KEY_LEFT)
		ballX  += 0.05f;
    
	glutPostRedisplay();
}*/


void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

/*void autorot(){
 
 while(1)
 {
 ballX -= 0.01f;
 glutPostRedisplay();
 //sleep(1000);
 }
 }*/

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}


void drawScene()
{
    int x=1;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	//drawRectangle();
    glTranslatef(0.0,0.0,-1.0);
    
    
	//drawBall();
    drawBall2(1.0);
	//drawBall2(1.5);
    for(int i=1;i<n/2;i++){
        drawBall2(2.0*x);
    x=x*2;}
    //drawBall2(4.0);
    //drawBall2(8.0);
    //drawBall2(16.0);
    
    
    
	glutSwapBuffers();
}


//float _angle = 30.0f;
void update(int value) {
	/*if(flag)
	{
	    ballX += 0.0005f;
        ballY+=0.001f;
        //if(ballX>0.3)
        if(ballX>-0.25)
            glClearColor(0.2f,0.2f,0.2f,1.0f);
        if(ballX>-0.20)
            glClearColor(0.4f,0.4f,0.4f,1.0f);
        if(ballX>-0.15)
            glClearColor(0.7f,0.7f,0.7f,1.0f);
        if(ballX>-0.1)
            glClearColor(1.0f,1.0f,1.0f,1.0f);
        if(ballY>0.3)
        {
            flag=0;
            
        }
	}
	if (!flag)
	{
        if(ballX>0.05f)
            glClearColor(0.7f,0.7f,0.7f,1.0f);        
        if(ballX>0.10f)
            glClearColor(0.7f,0.7f,0.7f,1.0f);
        if(ballX>0.20)
            glClearColor(0.0f,0.0f,0.0f,0.0f);
        ballX+=0.0005f;
		ballY -= 0.001f;
		if(ballY<-0.3)
        {
            flag=1;
            
        }
	}
	*/
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}


int main(int argc,char** argv)
{
    init();
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	
	glutInitWindowSize(800,800);
	
	glutCreateWindow("lab");
	
	initRendering();
	
	glutDisplayFunc(drawScene);
	
	//glutKeyBoardFunc(keyPress);
	//glutKeyboardFunc(keyPress);
	//glutSpecialFunc(keyPress);
	glutReshapeFunc(handleResize);
	//autorot();
    
	glutTimerFunc(25, update, 0);
    
	glutMainLoop();
	
	return(0);
}


