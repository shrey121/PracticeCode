#ifdef __APPLE__ 
#include<GLUT/glut.h> 
#include<openGL/openGL.h> 

#else 
#include<GL/glut.h> 
#endif 

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int n;
float x_1=1.0,y_1=1.0;
float xt1,yt1,xt2,yt2,xt3,yt3;
float a1=0.0,a2=0.0,step=0.0005;

void initialise()
{
    xt1=-1.0;yt1=0.0;
    xt2=1.0;yt2=0.0;
    xt3=0.0;yt3=1.73;
}

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

void drawTriangle(int d,float xt1, float yt1, float xt2, float yt2, float xt3, float yt3,int flag)
{
    if(flag)
    {
        glColor3f(d%2,(d+1)%2,d%2);
    }
    else
    {
    glColor3f(1.0, 0.0, 0.0);
    }
    
    glLineWidth(1.00);
    
    
    glBegin(GL_LINES);
    
    glVertex3f(xt1,yt1,-5.0);
    
    glVertex3f(xt2,yt2,-5.0);
    
    glEnd();
    
    
    glBegin(GL_LINES);
    
    glVertex3f(xt1,yt1,-5.0);
    
    glVertex3f(xt3,yt3,-5.0);
    
    glEnd();
    
    
    glBegin(GL_LINES);
    
    glVertex3f(xt3,yt3,-5.0);
    
    glVertex3f(xt2,yt2,-5.0);
    
    glEnd();
    
}


void triangles(int d, float xt1, float yt1, float xt2, float yt2, float xt3, float yt3, int flag)
{
    if(d==(n+1))
        return;
    
    float x1,x2,x3,y1,y2,y3;
    x3=(xt1+xt2)/2;
    y3=(yt1+yt2)/2;
    x1=(xt2+xt3)/2;
    y1=(yt2+yt3)/2;
    x2=(xt1+xt3)/2;
    y2=(yt1+yt3)/2;
    
    if(flag==1)
        drawTriangle(d, xt1, yt1, xt2, yt2, xt3, yt3, flag);
        
    triangles(d+1, xt1, yt1, x2, y2, x3, y3, 0);
    
    triangles(d+1, x1, y1, xt2, yt2, x3, y3, 0);
    
    triangles(d+1, x1, y1, x2, y2, xt3, yt3, 0);
    
    triangles(d+1, x1, y1, x2, y2, x3, y3, 1);
    
}

void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
    
    glMatrixMode(GL_MODELVIEW); 
    
    glLoadIdentity(); 
    
    //glShadeModel(GL_SMOOTH);
    
    //drawMainTriangle();
    triangles(1, xt1, yt1, xt2, yt2, xt3, yt3 , 1);
    
    glutSwapBuffers(); 
} 


int main(int argc,char **argv) 
{ 
    
    cout<<"Enter the Depth upto which triangles will be created : ";
    cin>>n;
    
    glutInit(&argc,argv); 
    
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); 
    
    glutInitWindowSize(800,800); 
    
    glutCreateWindow("Collision Window"); 
    
    //initRendering();    //initialize 3d rendering  
    initialise();
    glutDisplayFunc(display); 
    
    glutIdleFunc(display); 
    
    glutReshapeFunc(reshape); 
    
    glutSpecialFunc(keyPressed); 
    
    glutMainLoop(); 
    
    return(0); 
}