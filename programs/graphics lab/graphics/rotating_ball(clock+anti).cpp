#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#ifdef __APPLE__
#include<GLUT/glut.h>
#include<openGL/openGL.h>
#else
#include<GL/glut.h>
#endif



float x1=1.0,x2=1.0,angle=0,da=0.0005;


void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}


void reshape(int w,int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45,w/h,1,200);

}

void keyPressed(int key,int x,int y)
{
    if(key==GLUT_KEY_LEFT)
    {}
}

/*
 void drawBall1()
 {
 glColor3f(1.0,0.0,0.0);

 glPushMatrix();

 glTranslatef(x1,0.0,-5.0);

 glutSolidSphere(0.4,20,20);

 glPopMatrix();

 }

 */

void drawBall1()
{
    glColor3f(0.5,1.0,1.0);

    glPushMatrix();

    glTranslatef(x1,x2,-5.0);

    glutSolidSphere(0.4,20,20);



    glPopMatrix();

    glColor3f(1.0,0,0);

    glPushMatrix();

    glTranslatef(0,0,-5.0);


    glutSolidSphere(0.6,40,40);

    glPopMatrix();

}

void update()
{
    /* if(flag)
     {
     x1+=7;
     x2-=5;
     //if(x1>-0.35)
     flag=0;
     }
     if(!flag)
     {
     x1-=9;
     x2+=3;
     //if(x1<-2.0)
     flag=1;
     }
     */

    angle += da;

    if( (angle > 6.28) ||( angle<0))
    { //angle=0;
        da = -da;
        printf("hello");
    }
    x1= sin(angle);
    x2= cos(angle);

    // x1 += 0.001;
    //x2 -= 0.001;

    // sleep(1);


}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();


    drawBall1();

    //drawBall2();

    update();

    glutSwapBuffers();
}


int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(400,400);

    glutCreateWindow("Ball Rotation");

    initRendering();

    glutDisplayFunc(display);

    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutSpecialFunc(keyPressed);

    glutMainLoop();

    return(0);
}
