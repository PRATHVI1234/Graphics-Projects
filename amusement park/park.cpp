#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include<stdio.h>
#define PI 3.1416
static GLfloat spin = 0.0;
static float tx	= 0.0,bx=0.0,by=0.0,isbaby=0,dolnay=0,glUp=1,angle=0,step=0,stepx=0,stepy=0,cloudrightupx=0;
static float ty	=  5.0;
static float cloudLeftMove=0,shipMove=70,shipx=2;
static float xx=10,yy=13;

void baby();

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 51; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void sky()
{
    glPushMatrix();
    glColor3f(0.53f,0.807f,2.58f);
    glTranslated(0,10,1),
                 glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-8);
    glVertex2d(-150.0,-8);
    glEnd();
    glPopMatrix();

}
void hillSide()
{
    glPushMatrix();
    glScaled(1,0.6,0);
    glPushMatrix(); //mountain
    glTranslated(-9.5,0.0,1);
    glColor3f(.42, 0.56, 0.107);
    glTranslatef(0,5,0);
    halfcircle(12,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(8.5,0.0,1);
    glColor3f(0.0,1.0,0);
    glTranslatef(0,5,0);
    halfcircle(15,7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5,0.0,1);
    glColor3f(0.68, 1, 0.184);
    glTranslatef(0,5,0);
    halfcircle(6,3);
    glPopMatrix();
    glPopMatrix();
}

void hillTree()
{
    glPushMatrix();//Big tree
    glTranslated(-15,6,0);
    glScaled(0.5,0.2,0);
    glPushMatrix();
    glTranslated(-1,-10,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}

void field()
{

    glPushMatrix();
    glColor3f(0.4, 0.8039,0);
    glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-50);
    glVertex2d(-150.0,-50);
    glEnd();
    glPopMatrix();
}

void river()
{

    glPushMatrix();
    glTranslatef(0,20,0);
    glPushMatrix();
    glBegin(GL_QUADS);
   glColor3f(0.55,0.27,0.0745);
    glVertex2d(-150.0,-16.4);
    glVertex2d(150.0,-16.4);
    glVertex2d(150.0,-16.5);
    glVertex2d(-150.0,-16.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.8f, 1.0f);
    glVertex2d(150.0,-16.5);
    glColor3f(0.7f, 0.8f, 1.0f);
    glVertex2d(-150.0,-16.5);
    glColor3f(0.7f, 0.8f, 1.0f);
    glVertex2d(-150.0,-20);
    glColor3f(0.388f, 0.72f, 1.0f);
    glVertex2d(150.0,-20);
    glEnd();

    glPopMatrix();
    glPopMatrix();

}

void ship()
{
    if(isbaby==8)
    {

        shipx= shipx-0.01;
        if(shipx<-25)
            shipx=20;
    }
    glPushMatrix();
    glTranslated(0+shipx,0.8,0);
    glScaled(0.5,0.2,0);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f); //ship body front
    glVertex2d(0.0f,0.0f);
    glVertex2d(-3.0f,7.0f);
    glVertex2d(10.0f,7.0f);
    glVertex2d(8.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f); //green box front
    glVertex2d(2.0f,7.0f);
    glVertex2d(2.0f,9.0f);
    glVertex2d(8.0f,9.0f);
    glVertex2d(8.0f,7.0f);

    glColor3f(1.0f,0.0f,0.0f); //red stand front
    glVertex2d(4.0f,9.0f);
    glVertex2d(4.0f,15.0f);
    glVertex2d(6.0f,15.0f);
    glVertex2d(6.0f,9.0f);

    glEnd();
    glPopMatrix();
}

void sun()
{
    glPushMatrix();
    glTranslated(-4,8.8,0);
    glScaled(0.5,0.3,0.3);
    glColor3f(1,0.894,0);
    circle(2.5,3.5);
    glPopMatrix();
}

void cloudRightUp()
{
    glPushMatrix();
    glTranslated(16,16.3,1.5);
    glScaled(0.5,0.2,0);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,-38,1),
                 circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();

    glTranslated(3,-35,1),
                 circle(2,3);
    glPopMatrix();

    glPushMatrix();

    glTranslated(4.5,-37.5,1);
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-38.5,1),
                 circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();

}

void swing()
{
    glPushMatrix();
    glTranslated(-18,-1.5,0);
    glScaled(0.7,0.4,0);

    glPushMatrix(); //Dolna left bar
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //dolna right bar
    glTranslated(10,0,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(0.4,10.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna up bar
    glTranslated(0,9,1);
    glRotatef(-90,0,0,1);

    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.4);
    glVertex2d(0.4,10.4);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//dolna left line
     glColor3f(1,0.2,0);
    glTranslated(2.9,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,dolnay);
    glVertex2d(0.0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //dolna right side
     glColor3f(1,0,0);
    glTranslated(7.7,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0,dolnay);
    glVertex2d(0,6.0);
    glVertex2d(0.1,6.0);
    glVertex2d(0.1,dolnay);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //dolna sitting table

    glTranslated(1.8,3,1);
     glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2d(1.0,dolnay+1);
    glVertex2d(6.0,dolnay+1);
    glVertex2d(7.0,dolnay);
    glVertex2d(0.0,dolnay);

    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void wheerligig()
{
    glPushMatrix();
    glPushMatrix();  //stand
    glTranslated(13,-5,1);
    glScaled(0.4,0.25,0);
    glColor3f(0.184,0.31,0.31);
    glBegin(GL_QUADS);
    glVertex2d(0,-10);
    glVertex2d(1,-10);
    glVertex2d(1,30);
    glVertex2d(0,30);
    glEnd();

     glPushMatrix();
        glTranslated(0.5,30,0);
        glColor3f(0.545,0,0);
        circle(1,1);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(13.25,2.5,1);
    glScaled(0.35,0.2,0);
    glRotated(angle,0,0,1);
    glPushMatrix();
    glTranslatef(10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();

    if(isbaby==5)
    {
        baby();
    }

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_LINES);

    glVertex2d(0,0);
    glVertex2d(10,13);
    glVertex2d(0,0);
    glVertex2d(10,-13);
    glVertex2d(0,0);       //4 cross lines
    glVertex2d(-10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,13);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,0);
    glColor3f(0.545,0,0);
    circle(1,1);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}

void bench()
{
    glPushMatrix();
    glTranslated(-8,-3,1);
    glColor3f(0,0,1);
    glScaled(0.8,0.6,1);
    glPushMatrix(); //Brench
    glTranslated(1.8,3,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(1.0,1.0);
    glVertex2d(6.0,1.0);
    glVertex2d(7.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslated(-2.8,1.8,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,7.0);
    glVertex2d(0.1,7.0);
    glVertex2d(0.1,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,1.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,1.0);
    glVertex2d(0.4,1.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(7,1.7,1);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,1.0);
    glVertex2d(0.4,1.0);
    glVertex2d(0.4,0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}
void baby()
{
    glPushMatrix();
    if(isbaby==0)
    {
        glTranslated(0+bx,0+by,0);
        glScalef(0.05,0.07,0);
    }

     else if(isbaby==5)
    {
        glTranslated(-0.5,2,0);
        glScaled(0.07,0.2,0);
    }
    else if(isbaby==6)
    {
        glTranslated(0+bx,0+by,0);
        glScalef(0.04,0.06,0);
    }

    else if(isbaby==8)
    {

        glTranslated(0+shipx,3,0);
        glTranslated(0,0,0);
        glScalef(0.04,0.04,0);
    }
    glPushMatrix();   //jama top
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(-6,-6);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-6,-11);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(6,-11);
    glVertex2d(9,-13);
    glVertex2d(11,-9);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //left hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11,-9);
    glVertex2d(-9,-13);
    glVertex2d(-13,-20);
    glVertex2d(-16,-18);
    glEnd();

    glPopMatrix();

    glPushMatrix();     //left hand palm
    glTranslated(-15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //right hand
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(11,-9);
    glVertex2d(9,-13);
    glVertex2d(13,-20);
    glVertex2d(16,-18);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //right hand palm
    glTranslated(15,-20,0);
    glColor3f(0.87,0.72,0.53);
    circle(3,2.5);
    glPopMatrix();


    glPushMatrix();     //skirt
    glColor3f(0.6,0.1,0.1);
    glBegin(GL_QUADS);
    glVertex2d(-6,-22);
    glVertex2d(6,-22);
    glVertex2d(13,-32);
    glVertex2d(-13,-32);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6,-32);
    glVertex2d(-2,-32);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right leg
    glColor3f(0.87,0.72,0.53);
    glBegin(GL_QUADS);
    glVertex2d(6,-32);
    glVertex2d(2,-32);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //right shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(10,-42);
    glVertex2d(2,-42);
    glVertex2d(2,-38);
    glVertex2d(6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix();         //left shoe
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(-10,-42);
    glVertex2d(-2,-42);
    glVertex2d(-2,-38);
    glVertex2d(-6,-38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //hair
    glColor3f(0,0,0);
    circle(9,10);
    glPopMatrix();

    glPushMatrix();         //head, neck, nose ,eye, lips
    glColor3f(0.87,0.72,0.53);
    circle(7,6);            //head
    glBegin(GL_QUADS);      //neck
    glVertex2d(-6,-6);
    glVertex2d(6,-6);
    glVertex2d(4,-10);
    glVertex2d(-4,-10);
    glEnd();
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //right eye

    glVertex2d(4,3);
    glVertex2d(1,3);

    glEnd();
    glBegin(GL_LINES);      //lips

    glVertex2d(2,-3);
    glVertex2d(-2,-3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_LINES);      //left eye

    glVertex2d(-4,3);
    glVertex2d(-1,3);

    glEnd();
    circle(0.5,2);      //nose
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
}

void slide()
{
    glPushMatrix();
    glTranslatef(2,-3,0);
    glPushMatrix();
    glTranslatef(-3,-3,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,-2,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,-1,0);
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(2.8,-0.1);
    glVertex2d(-0.1,-0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54,0.396,0.031);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(0.3,0);
    glVertex2d(-3.7,-4);
    glVertex2d(-4,-4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54,0.396,0.031);
    glBegin(GL_QUADS);
    glVertex2d(3,0);
    glVertex2d(2.7,0);
    glVertex2d(-1.3,-4);
    glVertex2d(-1,-4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(3,0);
    glVertex2d(6,-5);
    glVertex2d(3,-5);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void glidder()
{
    glPushMatrix();
    glTranslated(-18.5,-6,0);
    glColor3f(0,0,0.54);
    glScalef(0.8,0.5,0);
    //glPushMatrix(); // glidder body
      if(glUp==0)
      {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(13,3.0);
        glVertex2f(13,3.3);
        glVertex2f(0,0.3);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(3.0,0.9);
        glVertex2d(3.0,1.5);
        glVertex2d(3.3,1.5);
        glVertex2d(3.3,0.9);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(10.0,2.4);
        glVertex2d(10.0,3.0);
        glVertex2d(9.7,3.0);
        glVertex2d(9.7,2.4);
        glEnd();
        glPopMatrix();
        glPushMatrix();  //glidder bottom
        glTranslated(6.2,1.0,1);
        glBegin(GL_QUADS);
        glVertex2d(0.0,0.5);
        glVertex2d(0.0,-2.0);
        glVertex2d(0.5,-2.0);
        glVertex2d(0.5,0.6);
        glEnd();
        glPopMatrix();
     }

     if(glUp==1)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2f(0,3.0);
        glVertex2f(0,3.3);
        glVertex2f(13,0.3);
        glVertex2f(13,0);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(3.0,2.4);
        glVertex2d(3.0,3.0);
        glVertex2d(3.3,3.0);
        glVertex2d(3.3,2.4);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(10.0,0.9);
        glVertex2d(10.0,1.5);
        glVertex2d(9.7,1.5);
        glVertex2d(9.7,0.9);
        glEnd();
        glPopMatrix();
        glPushMatrix();  //glidder bottom
        glTranslated(6.2,1.0,1);
        glBegin(GL_QUADS);
        glVertex2d(0.0,0.6);
        glVertex2d(0.0,-2.0);
        glVertex2d(0.5,-2.0);
        glVertex2d(0.5,0.5);
        glEnd();
        glPopMatrix();

    }

    glPushMatrix();
    glPopMatrix();
    glPopMatrix();
}
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    hillSide();
    field();
    river();
    sun();
    cloudRightUp();
    hillTree();
    glidder();
    if(isbaby!=8)
    {
        ship();
        wheerligig();
        swing();

    }
    bench();
    if(isbaby==0||isbaby==6||isbaby==8)
    {
        baby();
    }
    slide();


    if(isbaby==8)
    {
        ship();
        wheerligig();
        swing();

    }

    glutPostRedisplay();

    glFlush();
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
}

void spe_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_LEFT:

        bx=bx-0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:

        bx=bx+0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:

        by=by-0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:

        by=by+0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }

}

void windMove()
{

    if(angle<-726.5)
    {
        isbaby=0;
        angle=0;
        bx=7;
        by=0;
        glutIdleFunc(NULL);
    }
    else
    {
        angle=angle-0.2;
    }
    glutPostRedisplay();

}

void normal_key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'h':
        glUp=1;
        glutPostRedisplay();
        break;

    case 'l':
        glUp=0;
        glutPostRedisplay();
        break;

    case 'w':
        isbaby=5;
        glutIdleFunc(windMove);
        break;

    case 'b':
        isbaby=8;
        glutPostRedisplay();
        break;

    case 'c':
        if(shipx<5 && shipx>-5)
        {
            isbaby=0;
            bx=0;
            by=0;
        }

    default:
        break;
    }

}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1600, 1000);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Amusement Park");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(normal_key);
    glutMainLoop();
    return 0;
}
