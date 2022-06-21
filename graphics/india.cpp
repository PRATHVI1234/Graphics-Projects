
#include<bits/stdc++.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
using namespace std;
float counter=0;
void Init()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-200,500,-50,400);
}
void circle(int x, int y,int r)
{
//glColor3f(0.0,0.0,1.0);
float th;
glBegin(GL_POLYGON);
for(int i=0;i<=360;i++)
{

    th=i*(3.14/180);
    glVertex2f(x+r*cos(th),y+r*sin(th));
}
glEnd();
}

void boat()
{
//glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);

counter=counter+1;
if(counter>=500)
    counter=-200;

glBegin(GL_QUADS);//garden
glColor3f(0.0,0.5,0.1);
glVertex2i(-200,300);
glVertex2i(500,300);
glVertex2i(500,35);
glVertex2i(-200,35);
glEnd();

//glTranslated(counter,200,0.0);
glColor3f(0.0,0.9,1.0);
glBegin(GL_QUADS);// river

glVertex2i(-200,35);
glVertex2i(-200,-50);
glColor3f(0.0,0.2,1.0);
glVertex2i(500,-50);
glVertex2i(500,35);
glEnd();

//glTranslated(counter,200,0.0);
glPushMatrix();
glTranslatef(counter,0.0,0);
glColor3f(1.0,0.5,0.0);
glBegin(GL_QUADS);   //boat
glVertex2i(10,50);
glVertex2i(30,10);
glVertex2i(130,10);
glVertex2i(150,50);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2i(30,50);
glVertex2i(30,70);
glVertex2i(130,70);
glVertex2i(130,50);
glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex2i(60,90);
glVertex2i(60,70);
glVertex2i(100,70);
glVertex2i(100,90);
glEnd();
glColor3f(0.1,0.0,0.0);//pole
glPointSize(6);
glBegin(GL_LINE_STRIP);
glVertex2i(80,90);
glVertex2i(80,150);
glEnd();
glColor3f(1.0,0.5,0.0);
glBegin(GL_QUADS);//flag orange
glVertex2i(110,150);
glVertex2i(110,144);
glVertex2i(80,144);
glVertex2i(80,150);
glEnd();
glColor3f(1.0,1.0,1.0);//white
glBegin(GL_QUADS);
glVertex2i(110,138);
glVertex2i(110,144);
glVertex2i(80,144);
glVertex2i(80,138);
glEnd();
glColor3f(0.0,1.0,0.0);//green
glBegin(GL_QUADS);
glVertex2i(110,132);
glVertex2i(110,138);
glVertex2i(80,138);
glVertex2i(80,132);
glEnd();
glColor3f(0.1,0.1,0.4); //chakra
circle(95,141,3);

glPopMatrix();


}

void display()
{
//    glClear(GL_COLOR_BUFFER_BIT);

boat();

glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);// sky

glVertex2i(-200,400);
glVertex2i(500,400);
glVertex2i(500,300);
glVertex2i(-200,300);
glEnd();



glColor3f(0.6,0.4,0.4);
glBegin(GL_QUADS);    //house
glVertex2i(350,230);
glVertex2i(350,150);
glVertex2i(420,150);
glVertex2i(420,230);
glEnd();
glColor3f(0.0,0.7,0.4);
glBegin(GL_TRIANGLES);    //house
glVertex2i(320,230);
glVertex2i(385,260);
glVertex2i(450,230);
glEnd();
glColor3f(1.0,1.0,0.0); //sun
circle(400,360,20);
glFlush();
}
void timer(int value)
{
    glutTimerFunc(10,timer,0);
    display();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1600,1000);
    glutCreateWindow("SHIP");
    Init();
    glutDisplayFunc(display);
    timer(0);
    glutMainLoop();
}
