#include<windows.h>
#include<math.h>
#include<stdio.h>

#ifdef __APPLE__
#include<GLUT/glut.h>
#include<openGL/openGL.h>
#else
#include<GL/glut.h>
#endif

int limit=5;
void init(void);
//Initialize OpenGL
void init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,300.0,0.0,300.0);
}
void circle (int x,int y,float radius)
{
    float tx,ty;
    float i;
    //float r=0;
    float a=0,b=0;
    glBegin(GL_POINTS);
    for (i = 0; i < limit; i=i+.05)
    {
        //r=r+.2;
        a=a+.2;
        b=b+.3;
        tx=x+b*cosf(i);
        ty=y+a*sinf(i);
        glVertex2f(tx,ty);
    }
    glEnd();
}
void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    glColor3f(1,1,1);
    circle(150,150,1);
    glFlush();
}
void keypress(int key,int x,int y) {
    if(key==GLUT_KEY_UP) {
        limit=limit+1;
        circle(250,250,1);
        //   printf("\ndfd");
    }
    if(key==GLUT_KEY_DOWN) {
        limit=limit-1;
        circle(250,250,1);
    }
    //limit=limit+1;
    //circle(250,250,1);

    glutPostRedisplay();
}
int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Moving circles");
    init();
    glutDisplayFunc(draw);
    glutSpecialFunc(keypress);
    glutMainLoop();

}

