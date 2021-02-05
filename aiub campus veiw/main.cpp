#include<cstdio>
#include<math.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <iostream>

using namespace std;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = 0.0;
int sX1=200,sY1=650,sd=30, ssX1=200,ssY1=650,ssd=33, Sx, Sy, Sz;
int si,sl, ssi,ssl;
float sx, sy, ssx, ssy;
int mX1=200,mY1=650,md=30, mmX1=210,mmY1=660,mmd=25;
int mi,ml, mmi,mml;
float mx, my, mmx, mmy;
int day = 1;
bool carv=false;
bool cloudv = false;
bool rainv=false;

GLfloat position = 0.0f;
GLfloat speed = 0.1f;
GLfloat position1 = 0.0f;
GLfloat speed1 = 0.05f;
float cat=.15, dog=.15, xc=.5, xc1=-.5, yc=.8,  ben=.2, ten=.2, cr=-0.7, cl=-.9;

void update(int value)
{

    if(position > 1.8)
        position = -1.8f;
        position += speed;

    if(position1 > 1.4)
        position1 = -1.6f;
        position1 += speed1;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}


void Road(void)
{
    //Road
    glColor3ub(78, 78, 78);
    glBegin(GL_QUADS);
    glVertex3i(0, 0, 0);
    glVertex3i(1400, 0, 0);
    glVertex3i(1400, 230, 0);
    glVertex3i(0, 230, 0);
    glEnd();

}

void DaySky(void)
{
    //Sky Background
    glColor3ub(173, 216, 230);
    glBegin(GL_QUADS);
    glVertex3i(0, 0, 0);
    glVertex3i(1400, 0, 0);
    glVertex3i(1400, 700, 0);
    glVertex3i(0, 700, 0);
    glEnd();

    //Sun
    glBegin(GL_QUADS);
    glColor3ub (255, 255, 0);

    glVertex2i(140, 648);
    glVertex2i(140, 652);
    glVertex2i(260, 652);
    glVertex2i(260, 648);

    glVertex2i(198, 710);
    glVertex2i(202, 710);
    glVertex2i(202, 595);
    glVertex2i(198, 595);

    glVertex2i(155, 695);
    glVertex2i(158, 698);
    glVertex2i(245, 605);
    glVertex2i(248, 608);

    glVertex2i(245, 698);
    glVertex2i(248, 695);
    glVertex2i(158, 600);
    glVertex2i(155, 602);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (173, 216, 230);

    for(ssi=0;ssd>=ssi;ssi++)
    {
        ssy=sqrt((ssd*ssd)-(ssi*ssi));
        ssl=round(ssy);
        glVertex2i(ssX1+ssi,ssY1-ssl);
    }
    for(ssi=0;ssd>=ssi;ssi++)
    {
        ssx=sqrt((ssd*ssd)-(ssi*ssi));
        ssl=round(ssx);
        glVertex2i(ssX1+ssl,ssY1+ssi);
    }
    for(ssi=0;ssd>=ssi;ssi++)
    {
        ssy=sqrt((ssd*ssd)-(ssi*ssi));
        ssl=round(ssy);
        glVertex2i(ssX1-ssi,ssY1+ssl);
    }
    for(ssi=0;ssd>=ssi;ssi++)
    {
        ssx=sqrt((ssd*ssd)-(ssi*ssi));
        ssl=round(ssx);
        glVertex2i(ssX1-ssl,ssY1-ssi);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    for(si=0;sd>=si;si++)
    {
        sy=sqrt((sd*sd)-(si*si));
        sl=round(sy);
        glVertex2i(sX1+si,sY1-sl);
    }
    for(si=0;sd>=si;si++)
    {
        sx=sqrt((sd*sd)-(si*si));
        sl=round(sx);
        glVertex2i(sX1+sl,sY1+si);
    }
    for(si=0;sd>=si;si++)
    {
        sy=sqrt((sd*sd)-(si*si));
        sl=round(sy);
        glVertex2i(sX1-si,sY1+sl);
    }
    for(si=0;sd>=si;si++)
    {
        sx=sqrt((sd*sd)-(si*si));
        sl=round(sx);
        glVertex2i(sX1-sl,sY1-si);
    }
    glEnd();



}
void car1(void)
{
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(ten*0.4f, cr+ben*-0.7f);
    glVertex2f(ten*0.4f, cr+ben*-0.4f);
    glVertex2f(ten*0.5f, cr+ben*-0.1f);
    glVertex2f(ten*0.65f, cr+ben*-0.3f);
    glVertex2f(ten*0.65f, cr+ben*-0.65f);
    glVertex2f(ten*0.75f, cr+ben*-0.65f);
    glVertex2f(ten*0.75f, cr+ben*0.0f);
    glVertex2f(ten*0.3f, cr+ben*0.2f);
    glVertex2f(ten*-0.0f, cr+ben*0.6f);
    glVertex2f(ten*-0.62f, cr+ben*0.6f);
    glVertex2f(ten*-0.75f, cr+ben*0.1f);
    glVertex2f(ten*-0.75f, cr+ben*-0.7f);
    glVertex2f(ten*-0.6f, cr+ben*-0.7f);
    glVertex2f(ten*-0.6f, cr+ben*-0.4f);
    glVertex2f(ten*-0.5f, cr+ben*-0.2f);
    glVertex2f(ten*-0.32f, cr+ben*-0.4f);
    glVertex2f(ten*-0.3f, cr+ben*-0.7f);
    glVertex2f(ten*0.4f, cr+ben*-0.7f);
    glEnd();
    //3 windows(using Quads)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(ten*0.25f, cr+ben*0.1f);
    glVertex2f(ten*-0.0f, cr+ben*0.5f);
    glVertex2f(ten*-0.1f, cr+ben*0.5f);
    glVertex2f(ten*-0.1f, cr+ben*0.1f);
    glVertex2f(ten*-0.15f, cr+ben*0.1f);
    glVertex2f(ten*-0.15f, cr+ben*0.5f);
    glVertex2f(ten*-0.4f, cr+ben*0.5f);
    glVertex2f(ten*-0.4f, cr+ben*0.1f);
    glVertex2f(ten*-0.45f, cr+ben*0.1f);
    glVertex2f(ten*-0.45f, cr+ben*0.5f);
    glVertex2f(ten*-0.6f, cr+ben*0.5f);
    glVertex2f(ten*-0.7f, cr+ben*0.1f);
    glEnd();
    //wheel2(polygon)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 01.0f);
    glVertex2f(ten*-0.45f, cr+ben*-0.9f);
    glVertex2f(ten*-0.55f, cr+ben*-0.75f);
    glVertex2f(ten*-0.55f, cr+ben*-0.4f);
    glVertex2f(ten*-0.42f, cr+ben*-0.3f);
    glVertex2f(ten*-0.35f, cr+ben*-0.6f);
    glVertex2f(ten*-0.38f, cr+ben*-0.8f);
    glEnd();
    //wheel1(polygon)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 01.0f, 01.0f);
    glVertex2f(ten*0.45f, cr+ben*-0.8f);
    glVertex2f(ten*0.55f, cr+ben*-0.83f);
    glVertex2f(ten*0.6f, cr+ben*-0.6f);
    glVertex2f(ten*0.6f, cr+ben*-0.4f);
    glVertex2f(ten*0.5f, cr+ben*-0.2f);
    glVertex2f(ten*0.42f, cr+ben*-0.5f);
    glEnd();
    //Light
    if(day == 2)
    {
          glBegin(GL_QUADS);
        glColor3f(1.0f, 01.0f, 0.0f);
        glVertex2f(ten*0.7f, cl+ben*0.0f);
        glVertex2f(ten*0.7f, cl-ben*0.1f);
        glColor3f(0.3059f, 0.3059f, 0.3059f);
        glVertex2f(ten*1.3f, cl-ben*0.50f);
        glVertex2f(ten*1.3f, cl+ben*0.50f);
        glEnd();
    }

    glPopMatrix();
    glPopMatrix();
}

void car2(void)
{
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-position,0.0f, 0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(-ten*0.4f, cl+ben*-0.7f);
    glVertex2f(-ten*0.4f, cl+ben*-0.4f);
    glVertex2f(-ten*0.5f, cl+ben*-0.1f);
    glVertex2f(-ten*0.65f, cl+ben*-0.3f);
    glVertex2f(-ten*0.65f, cl+ben*-0.65f);
    glVertex2f(-ten*0.75f, cl+ben*-0.65f);
    glVertex2f(-ten*0.75f, cl+ben*0.0f);
    glVertex2f(-ten*0.3f, cl+ben*0.2f);
    glVertex2f(-ten*-0.0f, cl+ben*0.6f);
    glVertex2f(-ten*-0.62f, cl+ben*0.6f);
    glVertex2f(-ten*-0.75f, cl+ben*0.1f);
    glVertex2f(-ten*-0.75f, cl+ben*-0.7f);
    glVertex2f(-ten*-0.6f, cl+ben*-0.7f);
    glVertex2f(-ten*-0.6f, cl+ben*-0.4f);
    glVertex2f(-ten*-0.5f, cl+ben*-0.2f);
    glVertex2f(-ten*-0.32f, cl+ben*-0.4f);
    glVertex2f(-ten*-0.3f, cl+ben*-0.7f);
    glVertex2f(-ten*0.4f, cl+ben*-0.7f);
    glEnd();
    //3 windows(using Quads)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-ten*0.25f, cl+ben*0.1f);
    glVertex2f(-ten*-0.0f, cl+ben*0.5f);
    glVertex2f(-ten*-0.1f, cl+ben*0.5f);
    glVertex2f(-ten*-0.1f, cl+ben*0.1f);
    glVertex2f(-ten*-0.15f, cl+ben*0.1f);
    glVertex2f(-ten*-0.15f, cl+ben*0.5f);
    glVertex2f(-ten*-0.4f, cl+ben*0.5f);
    glVertex2f(-ten*-0.4f, cl+ben*0.1f);
    glVertex2f(-ten*-0.45f, cl+ben*0.1f);
    glVertex2f(-ten*-0.45f, cl+ben*0.5f);
    glVertex2f(-ten*-0.6f, cl+ben*0.5f);
    glVertex2f(-ten*-0.7f, cl+ben*0.1f);
    glEnd();
    //wheel2(polygon)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 01.0f);
    glVertex2f(-ten*-0.45f, cl+ben*-0.9f);
    glVertex2f(-ten*-0.55f, cl+ben*-0.75f);
    glVertex2f(-ten*-0.55f, cl+ben*-0.4f);
    glVertex2f(-ten*-0.42f, cl+ben*-0.3f);
    glVertex2f(-ten*-0.35f, cl+ben*-0.6f);
    glVertex2f(-ten*-0.38f, cl+ben*-0.8f);
    glEnd();
    //wheel1(polygon)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 01.0f, 01.0f);
    glVertex2f(-ten*0.45f, cl+ben*-0.8f);
    glVertex2f(-ten*0.55f, cl+ben*-0.83f);
    glVertex2f(-ten*0.6f, cl+ben*-0.6f);
    glVertex2f(-ten*0.6f, cl+ben*-0.4f);
    glVertex2f(-ten*0.5f, cl+ben*-0.2f);
    glVertex2f(-ten*0.42f, cl+ben*-0.5f);
    glEnd();

    //Light(quad)
    if(day == 2)
    {
          glBegin(GL_QUADS);
        glColor3f(1.0f, 01.0f, 0.0f);
        glVertex2f(-ten*0.7f, cl+ben*0.0f);
        glVertex2f(-ten*0.7f, cl-ben*0.1f);
        glColor3f(0.3059f, 0.3059f, 0.3059f);
        glVertex2f(-ten*1.3f, cl-ben*0.50f);
        glVertex2f(-ten*1.3f, cl+ben*0.50f);
        glEnd();
    }

    glPopMatrix();
    glPopMatrix();

}

void cloud(void)
{
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    glBegin(GL_POLYGON);

    glColor3f(01.f, 01.f, 1.f);
    glVertex2f(xc+cat*.8f, yc+dog*-.4f);
    glVertex2f(xc+cat*.8f, yc+dog*-.2f);
    glVertex2f(xc+cat*.7f, yc+dog*.0f);
    glVertex2f(xc+cat*.5f, yc+dog*.1f);
    glVertex2f(xc+cat*.4f, yc+dog*.5f);
    glVertex2f(xc+cat*.1f, yc+dog*.7f);
    glVertex2f(xc+cat*-.2f, yc+dog*.3f);
    glVertex2f(xc+cat*-.4f, yc+dog*.4f);
    glVertex2f(xc+cat*-.55f, yc+dog*.1f);
    glVertex2f(xc+cat*-.7f, yc+dog*-.05f);
    glVertex2f(xc+cat*-.8f, yc+dog*-.2f);
    glVertex2f(xc+cat*-.7f, yc+dog*-.5f);
    glColor3f(0.5f, 0.5f, .5f);
    glVertex2f(xc+cat*-.6f, yc+dog*-.6f);
    glVertex2f(xc+cat*.6f, yc+dog*-.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(01.f, 01.f, 1.f);
    glVertex2d(xc1+cat*.8f, yc+.1+dog*-.4f);
    glVertex2d(xc1+cat*.8f, yc+.1+dog*-.2f);
    glVertex2d(xc1+cat*.7f, yc+dog*.0+.1f);
    glVertex2d(xc1+cat*.5f, yc+dog*.1+.1f);
    glVertex2d(xc1+cat*.4f, yc+dog*.5+.1f);
    glVertex2d(xc1+cat*.1f, yc+dog*.7+.1f);
    glVertex2d(xc1+cat*-.2f, yc+dog*.3+.1f);
    glVertex2d(xc1+cat*-.4f, yc+dog*.4+.1f);
    glVertex2d(xc1+cat*-.55f, yc+dog*.1+.1f);
    glVertex2d(xc1+cat*-.7f, yc+dog*-.05+.1f);
    glVertex2d(xc1+cat*-.8f, yc+dog*-.2+.1f);
    glVertex2d(xc1+cat*-.7f, yc+dog*-.5+.1f);
    glColor3f(0.5f, 0.5f, .5f);
    glVertex2d(xc1+cat*-.6f, yc+dog*-.6+.1f);
    glVertex2d(xc1+cat*.6f, yc+dog*-.6+.1f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void rain()
{
    int x=0;
    int y=778;
    static float a=-760.0f;
    if(a<=-768)
    {
         a=-760.0f;

    }
    else
    {
        a-=0.5f;
    }
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0.0f,a,0.0f);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3i(x,y,0);
            glVertex3i(x+3,y+10,0);
            x+=rand()%1050;
        }
        y+=rand()%15;
        x=0;

    }
    glEnd();
    glPopMatrix();
    glutPostRedisplay();
}

void DayGarden(void)
{
    //Garden
    glColor3ub(50, 205, 50);
    glBegin(GL_QUADS);
    glVertex3i(0, 90,0);
    glVertex3i(900, 90,0);
    glVertex3i(790, 190,0);
    glVertex3i(0, 190,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(0, 91,0);
    glVertex3i(898, 91,0);
    glVertex3i(786, 190,0);
    glVertex3i(0, 190,0);
    glEnd();

    //Garden Bottom Border
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex3i(0, 80, 0);
    glVertex3i(910, 80, 0);
    glVertex3i(900, 90, 0);
    glVertex3i(0, 90, 0);
    //Garden Side Border
    glVertex3i(910, 80, 0);
    glVertex3i(930, 80, 0);
    glVertex3i(795, 200, 0);
    glVertex3i(775, 200, 0);
    //Garden Top Border
    glVertex3i(0, 190,0);
    glVertex3i(800, 190,0);
    glVertex3i(795, 200,0);
    glVertex3i(0, 200,0);
    glEnd();
}

void DayObjects(void)
{
    //Benches
    glBegin(GL_QUADS);
    //Bench 1
    glColor3ub(160, 90, 40);
    glVertex3i(35, 255, 0);
    glVertex3i(135, 255, 0);
    glVertex3i(135, 275, 0);
    glVertex3i(35, 275, 0);

    glColor3ub(205, 133, 63);
    glVertex3i(35, 250, 0);
    glVertex3i(135, 250, 0);
    glVertex3i(135, 257, 0);
    glVertex3i(35, 257, 0);

    glColor3ub(105, 105, 105);
    glVertex3i(40, 240, 0);
    glVertex3i(50, 240, 0);
    glVertex3i(50, 250, 0);
    glVertex3i(40, 250, 0);

    glVertex3i(120, 240, 0);
    glVertex3i(130, 240, 0);
    glVertex3i(130, 250, 0);
    glVertex3i(120, 250, 0);

    //Bench 2
    glColor3ub(160, 90, 40);
    glVertex3i(555, 255, 0);
    glVertex3i(655, 255, 0);
    glVertex3i(655, 275, 0);
    glVertex3i(555, 275, 0);

    glColor3ub(205, 133, 63);
    glVertex3i(555, 250, 0);
    glVertex3i(655, 250, 0);
    glVertex3i(655, 257, 0);
    glVertex3i(555, 257, 0);

    glColor3ub(105, 105, 105);
    glVertex3i(560, 240, 0);
    glVertex3i(570, 240, 0);
    glVertex3i(570, 250, 0);
    glVertex3i(560, 250, 0);

    glVertex3i(640, 240, 0);
    glVertex3i(650, 240, 0);
    glVertex3i(650, 250, 0);
    glVertex3i(640, 250, 0);

    //Bench 3
    glColor3ub(160, 90, 40);
    glVertex3i(880, 255, 0);
    glVertex3i(980, 255, 0);
    glVertex3i(980, 275, 0);
    glVertex3i(880, 275, 0);

    glColor3ub(205, 133, 63);
    glVertex3i(880, 250, 0);
    glVertex3i(980, 250, 0);
    glVertex3i(980, 257, 0);
    glVertex3i(880, 257, 0);

    glColor3ub(105, 105, 105);
    glVertex3i(890, 240, 0);
    glVertex3i(900, 240, 0);
    glVertex3i(900, 250, 0);
    glVertex3i(890, 250, 0);

    glVertex3i(960, 240, 0);
    glVertex3i(970, 240, 0);
    glVertex3i(970, 250, 0);
    glVertex3i(960, 250, 0);
    glEnd();

    //Tree stem
    glColor3ub(160, 90, 40);
    glBegin(GL_TRIANGLES);
    glVertex3i(20, 95, 0);
    glVertex3i(30, 95, 0);
    glVertex3i(25, 130, 0);

    glVertex3i(120, 175, 0);
    glVertex3i(130, 175, 0);
    glVertex3i(125, 210, 0);

    glVertex3i(220, 95, 0);
    glVertex3i(230, 95, 0);
    glVertex3i(225, 130, 0);

    glVertex3i(320, 175, 0);
    glVertex3i(330, 175, 0);
    glVertex3i(325, 210, 0);

    glVertex3i(420, 95, 0);
    glVertex3i(430, 95, 0);
    glVertex3i(425, 130, 0);

    glVertex3i(520, 175, 0);
    glVertex3i(530, 175, 0);
    glVertex3i(525, 210, 0);

    glVertex3i(620, 95, 0);
    glVertex3i(630, 95, 0);
    glVertex3i(625, 130, 0);

    glVertex3i(720, 175, 0);
    glVertex3i(730, 175, 0);
    glVertex3i(725, 210, 0);

    glVertex3i(820, 95, 0);
    glVertex3i(830, 95, 0);
    glVertex3i(825, 130, 0);
    glEnd();

    //Tree Base
    glColor3ub(85, 107, 47);
    glBegin(GL_TRIANGLES);
    glVertex3i(0, 110, 0);
    glVertex3i(50, 110, 0);
    glVertex3i(25, 150, 0);

    glVertex3i(100, 190, 0);
    glVertex3i(150, 190, 0);
    glVertex3i(125, 230, 0);

    glVertex3i(200, 110, 0);
    glVertex3i(250, 110, 0);
    glVertex3i(225, 150, 0);

    glVertex3i(300, 190, 0);
    glVertex3i(350, 190, 0);
    glVertex3i(325, 230, 0);

    glVertex3i(400, 110, 0);
    glVertex3i(450, 110, 0);
    glVertex3i(425, 150, 0);

    glVertex3i(500, 190, 0);
    glVertex3i(550, 190, 0);
    glVertex3i(525, 230, 0);

    glVertex3i(600, 110, 0);
    glVertex3i(650, 110, 0);
    glVertex3i(625, 150, 0);

    glVertex3i(700, 190, 0);
    glVertex3i(750, 190, 0);
    glVertex3i(725, 230, 0);

    glVertex3i(800, 110, 0);
    glVertex3i(850, 110, 0);
    glVertex3i(825, 150, 0);
    glEnd();

    //Tree Middle
    glColor3ub(128, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex3i(0, 125, 0);
    glVertex3i(50, 125, 0);
    glVertex3i(25, 165, 0);

    glVertex3i(100, 205, 0);
    glVertex3i(150, 205, 0);
    glVertex3i(125, 245, 0);

    glVertex3i(200, 125, 0);
    glVertex3i(250, 125, 0);
    glVertex3i(225, 165, 0);

    glVertex3i(300, 205, 0);
    glVertex3i(350, 205, 0);
    glVertex3i(325, 245, 0);

    glVertex3i(400, 125, 0);
    glVertex3i(450, 125, 0);
    glVertex3i(425, 165, 0);

    glVertex3i(500, 205, 0);
    glVertex3i(550, 205, 0);
    glVertex3i(525, 245, 0);

    glVertex3i(600, 125, 0);
    glVertex3i(650, 125, 0);
    glVertex3i(625, 165, 0);

    glVertex3i(700, 205, 0);
    glVertex3i(750, 205, 0);
    glVertex3i(725, 245, 0);

    glVertex3i(800, 125, 0);
    glVertex3i(850, 125, 0);
    glVertex3i(825, 165, 0);
    glEnd();

    //Tree Top
    glColor3ub(107, 142, 35);
    glBegin(GL_TRIANGLES);
    glVertex3i(0, 140, 0);
    glVertex3i(50, 140, 0);
    glVertex3i(25, 180, 0);

    glVertex3i(100, 220, 0);
    glVertex3i(150, 220, 0);
    glVertex3i(125, 260, 0);

    glVertex3i(200, 140, 0);
    glVertex3i(250, 140, 0);
    glVertex3i(225, 180, 0);

    glVertex3i(300, 220, 0);
    glVertex3i(350, 220, 0);
    glVertex3i(325, 260, 0);

    glVertex3i(400, 140, 0);
    glVertex3i(450, 140, 0);
    glVertex3i(425, 180, 0);

    glVertex3i(500, 220, 0);
    glVertex3i(550, 220, 0);
    glVertex3i(525, 260, 0);

    glVertex3i(600, 140, 0);
    glVertex3i(650, 140, 0);
    glVertex3i(625, 180, 0);

    glVertex3i(700, 220, 0);
    glVertex3i(750, 220, 0);
    glVertex3i(725, 260, 0);

    glVertex3i(800, 140, 0);
    glVertex3i(850, 140, 0);
    glVertex3i(825, 180, 0);
    glEnd();

    //Lamp Posts
    glBegin(GL_QUADS);
    //1st Lamp
    glColor3ub(255, 255, 255);
    glVertex3i(640, 330, 0);
    glVertex3i(750, 330, 0);
    glVertex3i(750, 340, 0);
    glVertex3i(640, 340, 0);

    glColor3ub(119, 136, 153);
    glVertex3i(690, 140, 0);
    glVertex3i(700, 140, 0);
    glVertex3i(700, 350, 0);
    glVertex3i(690, 350, 0);

    glVertex3i(640, 340, 0);
    glVertex3i(750, 340, 0);
    glVertex3i(750, 350, 0);
    glVertex3i(640, 350, 0);

    //2nd Lamp
    glColor3ub(255, 255, 255);
    glVertex3i(340, 330, 0);
    glVertex3i(450, 330, 0);
    glVertex3i(450, 340, 0);
    glVertex3i(340, 340, 0);

    glColor3ub(119, 136, 153);
    glVertex3i(390, 140, 0);
    glVertex3i(400, 140, 0);
    glVertex3i(400, 350, 0);
    glVertex3i(390, 350, 0);

    glVertex3i(340, 340, 0);
    glVertex3i(450, 340, 0);
    glVertex3i(450, 350, 0);
    glVertex3i(340, 350, 0);

    //3rd Lamp
    glColor3ub(255, 255, 255);
    glVertex3i(40, 330, 0);
    glVertex3i(150, 330, 0);
    glVertex3i(150, 340, 0);
    glVertex3i(40, 340, 0);

    glColor3ub(119, 136, 153);
    glVertex3i(90, 140, 0);
    glVertex3i(100, 140, 0);
    glVertex3i(100, 350, 0);
    glVertex3i(90, 350, 0);

    glVertex3i(40, 340, 0);
    glVertex3i(150, 340, 0);
    glVertex3i(150, 350, 0);
    glVertex3i(40, 350, 0);
    glEnd();
}

void DayBuilding(void)
{
    //Left Border
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3i(0, 230, 0);
    glVertex3i(220, 230, 0);
    glVertex3i(200, 240, 0);
    glVertex3i(0, 240, 0);
    //Right Border
    glVertex3i(480, 230, 0);
    glVertex3i(1400, 230, 0);
    glVertex3i(1400, 240, 0);
    glVertex3i(500, 240, 0);
    glEnd();

    //Left Building
    glBegin(GL_QUADS);
    glColor3ub(125, 0, 0);
    glVertex3i(0, 240, 0);
    glVertex3i(200, 240, 0);
    glVertex3i(200, 380, 0);
    glVertex3i(0, 380, 0);
    //Right Building
    glVertex3i(500, 240, 0);
    glVertex3i(1400, 240, 0);
    glVertex3i(1400, 380, 0);
    glVertex3i(500, 380, 0);
    glEnd();

    //shed pillars
    glBegin(GL_QUADS);
    glColor3ub(20, 20, 20);
    glVertex3i(0, 240, 0);
    glVertex3i(10, 240, 0);
    glVertex3i(10, 380, 0);
    glVertex3i(0, 380, 0);

    glVertex3i(680, 240, 0);
    glVertex3i(690, 240, 0);
    glVertex3i(690, 380, 0);
    glVertex3i(680, 380, 0);

    glVertex3i(840, 240, 0);
    glVertex3i(850, 240, 0);
    glVertex3i(850, 380, 0);
    glVertex3i(840, 380, 0);

    glVertex3i(1000, 240, 0);
    glVertex3i(1010, 240, 0);
    glVertex3i(1010, 380, 0);
    glVertex3i(1000, 380, 0);

    glVertex3i(1160, 240, 0);
    glVertex3i(1170, 240, 0);
    glVertex3i(1170, 380, 0);
    glVertex3i(1160, 380, 0);

    glVertex3i(1320, 240, 0);
    glVertex3i(1330, 240, 0);
    glVertex3i(1330, 380, 0);
    glVertex3i(1320, 380, 0);
    glEnd();

    //2nd Floor Glass
    glColor3ub(155, 238, 238);
    glBegin(GL_QUADS);
    glVertex3i(0, 475, 0);
    glVertex3i(1400, 475, 0);
    glVertex3i(1400, 420, 0);
    glVertex3i(0, 420, 0);
    glEnd();

    //Left Pillar
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3i(170, 240, 0);
    glVertex3i(200, 240, 0);
    glVertex3i(200, 580, 0);
    glVertex3i(170, 580, 0);
    //Right Pillar
    glVertex3i(500, 240, 0);
    glVertex3i(530, 240, 0);
    glVertex3i(530, 580, 0);
    glVertex3i(500, 580, 0);
    //Center Board
    glVertex3i(200, 530, 0);
    glVertex3i(500, 530, 0);
    glVertex3i(500, 580, 0);
    glVertex3i(200, 580, 0);
    glEnd();

    //Top Beam
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3i(0, 510, 0);
    glVertex3i(1400, 510, 0);
    glVertex3i(1400, 530, 0);
    glVertex3i(0, 530, 0);

    //2nd Floor Beam
    glVertex3i(0, 400, 0);
    glVertex3i(1400, 400, 0);
    glVertex3i(1400, 420, 0);
    glVertex3i(0, 420, 0);

    //Handle Bar
    glVertex3i(0, 475, 0);
    glVertex3i(1400, 475, 0);
    glVertex3i(1400, 480, 0);
    glVertex3i(0, 480, 0);
    glEnd();

    //2nd Floor Bottom Border
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3i(0, 420, 0);
    glVertex3i(1400, 420, 0);
    glVertex3i(1400, 430, 0);
    glVertex3i(0, 430, 0);
    //2nd Floor Top Left Border
    glVertex3i(0, 530, 0);
    glVertex3i(170, 530, 0);
    glVertex3i(170, 540, 0);
    glVertex3i(0, 540, 0);
    //2nd Floor Top Right Border
    glVertex3i(530, 530, 0);
    glVertex3i(1400, 530, 0);
    glVertex3i(1400, 540, 0);
    glVertex3i(530, 540, 0);
    glEnd();

    //Left Shade
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex3i(0, 380, 0);
    glVertex3i(220, 380, 0);
    glVertex3i(200, 400, 0);
    glVertex3i(0, 400, 0);
    //Right Shade
    glVertex3i(480, 380, 0);
    glVertex3i(1400, 380, 0);
    glVertex3i(1400, 400, 0);
    glVertex3i(500, 400, 0);
    glEnd();

    //2nd Floor Pillars
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3i(0, 430, 0);
    glVertex3i(15, 430, 0);
    glVertex3i(15, 530, 0);
    glVertex3i(0, 530, 0);

    glVertex3i(685, 430, 0);
    glVertex3i(700, 430, 0);
    glVertex3i(700, 530, 0);
    glVertex3i(685, 530, 0);

    glVertex3i(855, 430, 0);
    glVertex3i(870, 430, 0);
    glVertex3i(870, 530, 0);
    glVertex3i(855, 530, 0);

    glVertex3i(1025, 430, 0);
    glVertex3i(1040, 430, 0);
    glVertex3i(1040, 530, 0);
    glVertex3i(1025, 530, 0);

    glVertex3i(1195, 430, 0);
    glVertex3i(1210, 430, 0);
    glVertex3i(1210, 530, 0);
    glVertex3i(1195, 530, 0);

    glVertex3i(1365, 430, 0);
    glVertex3i(1380, 430, 0);
    glVertex3i(1380, 530, 0);
    glVertex3i(1365, 530, 0);
    glEnd();

    //Roof
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 100, 0);
    glVertex3i(150, 580, 0);
    glVertex3i(550, 580, 0);
    glVertex3i(350, 610, 0);
    glEnd();
}

void DayWindows(void)
{
    //Window Borders
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3i(40, 280, 0);
    glVertex3i(120, 280, 0);
    glVertex3i(120, 360, 0);
    glVertex3i(40, 360, 0);

    glVertex3i(570, 280, 0);
    glVertex3i(650, 280, 0);
    glVertex3i(650, 360, 0);
    glVertex3i(570, 360, 0);

    glVertex3i(730, 280, 0);
    glVertex3i(810, 280, 0);
    glVertex3i(810, 360, 0);
    glVertex3i(730, 360, 0);

    glVertex3i(890, 280, 0);
    glVertex3i(970, 280, 0);
    glVertex3i(970, 360, 0);
    glVertex3i(890, 360, 0);

    glVertex3i(1050, 280, 0);
    glVertex3i(1130, 280, 0);
    glVertex3i(1130, 360, 0);
    glVertex3i(1050, 360, 0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(40, 280, 0);
    glVertex3i(120, 280, 0);
    glVertex3i(120, 360, 0);
    glVertex3i(40, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(570, 280, 0);
    glVertex3i(650, 280, 0);
    glVertex3i(650, 360, 0);
    glVertex3i(570, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(730, 280, 0);
    glVertex3i(810, 280, 0);
    glVertex3i(810, 360, 0);
    glVertex3i(730, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(890, 280, 0);
    glVertex3i(970, 280, 0);
    glVertex3i(970, 360, 0);
    glVertex3i(890, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(1050, 280, 0);
    glVertex3i(1130, 280, 0);
    glVertex3i(1130, 360, 0);
    glVertex3i(1050, 360, 0);
    glEnd();
    //window glass
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3i(45, 285, 0);
    glVertex3i(76, 285, 0);
    glVertex3i(76, 318, 0);
    glVertex3i(45, 318, 0);

    glVertex3i(45, 322, 0);
    glVertex3i(76, 322, 0);
    glVertex3i(76, 355, 0);
    glVertex3i(45, 355, 0);

    glVertex3i(79, 322, 0);
    glVertex3i(115, 322, 0);
    glVertex3i(115, 355, 0);
    glVertex3i(79, 355, 0);

    glVertex3i(79, 285, 0);
    glVertex3i(115, 285, 0);
    glVertex3i(115, 318, 0);
    glVertex3i(79, 318, 0);

    glVertex3i(575, 285, 0);
    glVertex3i(606, 285, 0);
    glVertex3i(606, 318, 0);
    glVertex3i(575, 318, 0);

    glVertex3i(575, 322, 0);
    glVertex3i(606, 322, 0);
    glVertex3i(606, 355, 0);
    glVertex3i(575, 355, 0);

    glVertex3i(609, 322, 0);
    glVertex3i(645, 322, 0);
    glVertex3i(645, 355, 0);
    glVertex3i(609, 355, 0);

    glVertex3i(609, 285, 0);
    glVertex3i(645, 285, 0);
    glVertex3i(645, 318, 0);
    glVertex3i(609, 318, 0);

    glVertex3i(79, 285, 0);
    glVertex3i(115, 285, 0);
    glVertex3i(115, 318, 0);
    glVertex3i(79, 318, 0);

    glVertex3i(735, 285, 0);
    glVertex3i(766, 285, 0);
    glVertex3i(766, 318, 0);
    glVertex3i(735, 318, 0);

    glVertex3i(735, 322, 0);
    glVertex3i(766, 322, 0);
    glVertex3i(766, 355, 0);
    glVertex3i(735, 355, 0);

    glVertex3i(769, 322, 0);
    glVertex3i(805, 322, 0);
    glVertex3i(805, 355, 0);
    glVertex3i(769, 355, 0);

    glVertex3i(769, 285, 0);
    glVertex3i(805, 285, 0);
    glVertex3i(805, 318, 0);
    glVertex3i(769, 318, 0);

    glVertex3i(895, 285, 0);
    glVertex3i(926, 285, 0);
    glVertex3i(926, 318, 0);
    glVertex3i(895, 318, 0);

    glVertex3i(895, 322, 0);
    glVertex3i(926, 322, 0);
    glVertex3i(926, 355, 0);
    glVertex3i(895, 355, 0);

    glVertex3i(929, 322, 0);
    glVertex3i(965, 322, 0);
    glVertex3i(965, 355, 0);
    glVertex3i(929, 355, 0);

    glVertex3i(929, 285, 0);
    glVertex3i(965, 285, 0);
    glVertex3i(965, 318, 0);
    glVertex3i(929, 318, 0);
    glEnd();
}

void DayGlobe(void)
{
    //Globe Platform
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex3i(1050, 100,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1400, 200,0);
    glVertex3i(1100, 200,0);

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3i(1050, 90,0);
    glVertex3i(1400, 90,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1050, 100,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1050, 100,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1400, 200,0);
    glVertex3i(1100, 200,0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(1050, 90,0);
    glVertex3i(1400, 90,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1050, 100,0);
    glEnd();

    //Globe Base
    glColor3ub(112, 128, 144);
    glBegin(GL_QUADS);
    glVertex3i(1100, 130,0);
    glVertex3i(1400, 130,0);
    glVertex3i(1400, 350,0);
    glVertex3i(1100, 350,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1100, 130,0);
    glVertex3i(1500, 130,0);
    glVertex3i(1500, 350,0);
    glVertex3i(1100, 350,0);
    glEnd();

    //Globe
    glBegin(GL_POLYGON);
    glColor3ub (112, 128, 144);
    int X1=1200,Y1=680,d=420;
    int i,l;
    float x, y;

    for(i=0;d>=i;i++)
    {
        y=sqrt((d*d)-(i*i));
        l=round(y);
        glVertex2i(X1+i,Y1-l);
    }
    for(i=0;d>=i;i++)
    {
        x=sqrt((d*d)-(i*i));
        l=round(x);
        glVertex2i(X1+l,Y1+i);
    }
    for(i=0;d>=i;i++)
    {
        y=sqrt((d*d)-(i*i));
        l=round(y);
        glVertex2i(X1-i,Y1+l);
    }
    for(i=0;d>=i;i++)
    {
        x=sqrt((d*d)-(i*i));
        l=round(x);
        glVertex2i(X1-l,Y1-i);
    }
    glEnd();

    //globe windows
    glColor3ub(1, 128, 144);
    glBegin(GL_QUADS);
    glVertex3i(1100, 160,0);
    glVertex3i(1400, 160,0);
    glVertex3i(1400, 270,0);
    glVertex3i(1100, 270,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(870, 420,0);
    glVertex3i(1400, 420,0);
    glVertex3i(1400, 550,0);
    glVertex3i(801, 550,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(786, 620,0);
    glVertex3i(1400, 620,0);
    glVertex3i(1400, 750,0);
    glVertex3i(785, 750,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1100, 160,0);
    glVertex3i(1400, 160,0);
    glVertex3i(1400, 270,0);
    glVertex3i(1100, 270,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3i(870, 420,0);
    glVertex3i(1400, 420,0);
    glVertex3i(1400, 550,0);
    glVertex3i(801, 550,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3i(786, 620,0);
    glVertex3i(1400, 620,0);
    glVertex3i(1400, 750,0);
    glVertex3i(785, 750,0);
    glEnd();

    //globe door
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3i(1250, 130,0);
    glVertex3i(1385, 130,0);
    glVertex3i(1385, 280,0);
    glVertex3i(1250, 280,0);
    glEnd();

    glColor3ub(169, 169, 169);
    glBegin(GL_QUADS);
    glVertex3i(1255, 130,0);
    glVertex3i(1380, 130,0);
    glVertex3i(1380, 275,0);
    glVertex3i(1255, 275,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1250, 130,0);
    glVertex3i(1385, 130,0);
    glVertex3i(1385, 280,0);
    glVertex3i(1250, 280,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3i(1255, 130,0);
    glVertex3i(1380, 130,0);
    glVertex3i(1380, 275,0);
    glVertex3i(1255, 275,0);
    glEnd();

}

void DayView(void)
{
    DaySky();

    Road();

    DayGarden();

    DayBuilding();

    DayWindows();

    DayObjects();

    if(carv)
        {
            //car1();
            car2();
        }
    if(cloudv)
        {
            cloud();
        }

    glPopMatrix();

    DayGlobe();

    if(rainv)
        {
            rain();
        }
}


void NightSky(void)
{
    //Sky Background
    glColor3ub(0, 0, 100);
    glBegin(GL_QUADS);
    glVertex3i(0, 0, 0);
    glVertex3i(1400, 0, 0);
    glVertex3i(1400, 700, 0);
    glVertex3i(0, 700, 0);
    glEnd();

    //Moon
    glBegin(GL_POLYGON);
    glColor3ub (255, 255, 255);

    for(mi=0;md>=mi;mi++)
    {
        my=sqrt((md*md)-(mi*mi));
        ml=round(my);
        glVertex2i(mX1+mi,mY1-ml);
    }
    for(mi=0;md>=mi;mi++)
    {
        mx=sqrt((md*md)-(mi*mi));
        ml=round(mx);
        glVertex2i(mX1+ml,mY1+mi);
    }
    for(mi=0;md>=mi;mi++)
    {
        my=sqrt((md*md)-(mi*mi));
        ml=round(my);
        glVertex2i(mX1-mi,mY1+ml);
    }
    for(mi=0;md>=mi;mi++)
    {
        mx=sqrt((md*md)-(mi*mi));
        ml=round(mx);
        glVertex2i(mX1-ml,mY1-mi);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (0, 00, 100);

    for(mmi=0;mmd>=mmi;mmi++)
    {
        mmy=sqrt((mmd*mmd)-(mmi*mmi));
        mml=round(mmy);
        glVertex2i(mmX1+mmi,mmY1-mml);
    }
    for(mmi=0;mmd>=mmi;mmi++)
    {
        mmx=sqrt((mmd*mmd)-(mmi*mmi));
        mml=round(mmx);
        glVertex2i(mmX1+mml,mmY1+mmi);
    }
    for(mmi=0;mmd>=mmi;mmi++)
    {
        mmy=sqrt((mmd*mmd)-(mmi*mmi));
        mml=round(mmy);
        glVertex2i(mmX1-mmi,mmY1+mml);
    }
    for(mmi=0;mmd>=mmi;mmi++)
    {
        mmx=sqrt((mmd*mmd)-(mmi*mmi));
        mml=round(mmx);
        glVertex2i(mmX1-mml,mmY1-mmi);
    }
    glEnd();

    //star

glTranslatef(0.0f,0.0f, 0.0f);

    for(int Si=0; Si<6000; Si++)
    {
        Sx=rand() % 1400 + 1;
        Sy=rand() % 300 + 450;
        Sz=rand() % 3 +1;

        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        {
            if(Sz%2==1)
                {
                    glVertex2i(Sx,Sy);
                    glVertex2i(Sx+1,Sy);
                    glVertex2i(Sx+1,Sy+1);
                    glVertex2i(Sx,Sy+1);
                }
            else
                {
                    glVertex2i(Sx,Sy);
                    glVertex2i(Sx+Sz,Sy);
                    glVertex2i(Sx+Sz,Sy+Sz);
                    glVertex2i(Sx,Sy+Sz);
                }
            glEnd();
        }
    }
}

void NightGarden(void)
{
    //Garden
    glColor3ub(0, 60, 0);
    glBegin(GL_QUADS);
    glVertex3i(0, 90,0);
    glVertex3i(900, 90,0);
    glVertex3i(790, 190,0);
    glVertex3i(0, 190,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(0, 91,0);
    glVertex3i(898, 91,0);
    glVertex3i(786, 190,0);
    glVertex3i(0, 190,0);
    glEnd();

    //Garden Bottom Border
    glColor3ub(140, 60, 0);
    glBegin(GL_QUADS);
    glVertex3i(0, 80, 0);
    glVertex3i(910, 80, 0);
    glVertex3i(900, 90, 0);
    glVertex3i(0, 90, 0);
    //Garden Side Border
    glVertex3i(910, 80, 0);
    glVertex3i(930, 80, 0);
    glVertex3i(795, 200, 0);
    glVertex3i(775, 200, 0);
    //Garden Top Border
    glVertex3i(0, 190,0);
    glVertex3i(800, 190,0);
    glVertex3i(795, 200,0);
    glVertex3i(0, 200,0);
    glEnd();
}

void NightObjects(void)
{
    //Benches
    glBegin(GL_QUADS);
    //Bench 1
    glColor3ub(160, 90, 40);
    glVertex3i(35, 255, 0);
    glVertex3i(135, 255, 0);
    glVertex3i(135, 275, 0);
    glVertex3i(35, 275, 0);

    glColor3ub(205, 133, 63);
    glVertex3i(35, 250, 0);
    glVertex3i(135, 250, 0);
    glVertex3i(135, 257, 0);
    glVertex3i(35, 257, 0);

    glColor3ub(105, 105, 105);
    glVertex3i(40, 240, 0);
    glVertex3i(50, 240, 0);
    glVertex3i(50, 250, 0);
    glVertex3i(40, 250, 0);

    glVertex3i(120, 240, 0);
    glVertex3i(130, 240, 0);
    glVertex3i(130, 250, 0);
    glVertex3i(120, 250, 0);

    //Bench 2
    glColor3ub(160, 90, 40);
    glVertex3i(555, 255, 0);
    glVertex3i(655, 255, 0);
    glVertex3i(655, 275, 0);
    glVertex3i(555, 275, 0);

    glColor3ub(205, 133, 63);
    glVertex3i(555, 250, 0);
    glVertex3i(655, 250, 0);
    glVertex3i(655, 257, 0);
    glVertex3i(555, 257, 0);

    glColor3ub(105, 105, 105);
    glVertex3i(560, 240, 0);
    glVertex3i(570, 240, 0);
    glVertex3i(570, 250, 0);
    glVertex3i(560, 250, 0);

    glVertex3i(640, 240, 0);
    glVertex3i(650, 240, 0);
    glVertex3i(650, 250, 0);
    glVertex3i(640, 250, 0);

    //Bench 3
    glColor3ub(160, 90, 40);
    glVertex3i(880, 255, 0);
    glVertex3i(980, 255, 0);
    glVertex3i(980, 275, 0);
    glVertex3i(880, 275, 0);

    glColor3ub(205, 133, 63);
    glVertex3i(880, 250, 0);
    glVertex3i(980, 250, 0);
    glVertex3i(980, 257, 0);
    glVertex3i(880, 257, 0);

    glColor3ub(105, 105, 105);
    glVertex3i(890, 240, 0);
    glVertex3i(900, 240, 0);
    glVertex3i(900, 250, 0);
    glVertex3i(890, 250, 0);

    glVertex3i(960, 240, 0);
    glVertex3i(970, 240, 0);
    glVertex3i(970, 250, 0);
    glVertex3i(960, 250, 0);

    glEnd();

    //Lamp Posts
    glBegin(GL_QUADS);
    //1st Lamp
    glColor3ub(255, 255, 100);
    glVertex3i(640, 330, 0);
    glVertex3i(750, 330, 0);
    glVertex3i(750, 340, 0);
    glVertex3i(640, 340, 0);

    glColor3ub(119, 136, 153);
    glVertex3i(690, 140, 0);
    glVertex3i(700, 140, 0);
    glVertex3i(700, 350, 0);
    glVertex3i(690, 350, 0);

    glVertex3i(640, 340, 0);
    glVertex3i(750, 340, 0);
    glVertex3i(750, 350, 0);
    glVertex3i(640, 350, 0);

    //2nd Lamp
    glColor3ub(255, 255, 100);
    glVertex3i(340, 330, 0);
    glVertex3i(450, 330, 0);
    glVertex3i(450, 340, 0);
    glVertex3i(340, 340, 0);

    glColor3ub(119, 136, 153);
    glVertex3i(390, 140, 0);
    glVertex3i(400, 140, 0);
    glVertex3i(400, 350, 0);
    glVertex3i(390, 350, 0);

    glVertex3i(340, 340, 0);
    glVertex3i(450, 340, 0);
    glVertex3i(450, 350, 0);
    glVertex3i(340, 350, 0);

    //3rd Lamp
    glColor3ub(255, 255, 100);
    glVertex3i(40, 330, 0);
    glVertex3i(150, 330, 0);
    glVertex3i(150, 340, 0);
    glVertex3i(40, 340, 0);

    glColor3ub(119, 136, 153);
    glVertex3i(90, 140, 0);
    glVertex3i(100, 140, 0);
    glVertex3i(100, 350, 0);
    glVertex3i(90, 350, 0);

    glVertex3i(40, 340, 0);
    glVertex3i(150, 340, 0);
    glVertex3i(150, 350, 0);
    glVertex3i(40, 350, 0);
    glEnd();

    //Tree stem
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);
    glVertex3i(20, 95, 0);
    glVertex3i(30, 95, 0);
    glVertex3i(25, 130, 0);

    glVertex3i(120, 175, 0);
    glVertex3i(130, 175, 0);
    glVertex3i(125, 210, 0);

    glVertex3i(220, 95, 0);
    glVertex3i(230, 95, 0);
    glVertex3i(225, 130, 0);

    glVertex3i(320, 175, 0);
    glVertex3i(330, 175, 0);
    glVertex3i(325, 210, 0);

    glVertex3i(420, 95, 0);
    glVertex3i(430, 95, 0);
    glVertex3i(425, 130, 0);

    glVertex3i(520, 175, 0);
    glVertex3i(530, 175, 0);
    glVertex3i(525, 210, 0);

    glVertex3i(620, 95, 0);
    glVertex3i(630, 95, 0);
    glVertex3i(625, 130, 0);

    glVertex3i(720, 175, 0);
    glVertex3i(730, 175, 0);
    glVertex3i(725, 210, 0);

    glVertex3i(820, 95, 0);
    glVertex3i(830, 95, 0);
    glVertex3i(825, 130, 0);
    glEnd();

    //Tree Base
    glColor3ub(0, 100, 0);
    glBegin(GL_TRIANGLES);
    glVertex3i(0, 110, 0);
    glVertex3i(50, 110, 0);
    glVertex3i(25, 150, 0);

    glVertex3i(100, 190, 0);
    glVertex3i(150, 190, 0);
    glVertex3i(125, 230, 0);

    glVertex3i(200, 110, 0);
    glVertex3i(250, 110, 0);
    glVertex3i(225, 150, 0);

    glVertex3i(300, 190, 0);
    glVertex3i(350, 190, 0);
    glVertex3i(325, 230, 0);

    glVertex3i(400, 110, 0);
    glVertex3i(450, 110, 0);
    glVertex3i(425, 150, 0);

    glVertex3i(500, 190, 0);
    glVertex3i(550, 190, 0);
    glVertex3i(525, 230, 0);

    glVertex3i(600, 110, 0);
    glVertex3i(650, 110, 0);
    glVertex3i(625, 150, 0);

    glVertex3i(700, 190, 0);
    glVertex3i(750, 190, 0);
    glVertex3i(725, 230, 0);

    glVertex3i(800, 110, 0);
    glVertex3i(850, 110, 0);
    glVertex3i(825, 150, 0);
    glEnd();

    //Tree Middle
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLES);
    glVertex3i(0, 125, 0);
    glVertex3i(50, 125, 0);
    glVertex3i(25, 165, 0);

    glVertex3i(100, 205, 0);
    glVertex3i(150, 205, 0);
    glVertex3i(125, 245, 0);

    glVertex3i(200, 125, 0);
    glVertex3i(250, 125, 0);
    glVertex3i(225, 165, 0);

    glVertex3i(300, 205, 0);
    glVertex3i(350, 205, 0);
    glVertex3i(325, 245, 0);

    glVertex3i(400, 125, 0);
    glVertex3i(450, 125, 0);
    glVertex3i(425, 165, 0);

    glVertex3i(500, 205, 0);
    glVertex3i(550, 205, 0);
    glVertex3i(525, 245, 0);

    glVertex3i(600, 125, 0);
    glVertex3i(650, 125, 0);
    glVertex3i(625, 165, 0);

    glVertex3i(700, 205, 0);
    glVertex3i(750, 205, 0);
    glVertex3i(725, 245, 0);

    glVertex3i(800, 125, 0);
    glVertex3i(850, 125, 0);
    glVertex3i(825, 165, 0);
    glEnd();

    //Tree Top
    glColor3ub(85, 107, 47);
    glBegin(GL_TRIANGLES);
    glVertex3i(0, 140, 0);
    glVertex3i(50, 140, 0);
    glVertex3i(25, 180, 0);

    glVertex3i(100, 220, 0);
    glVertex3i(150, 220, 0);
    glVertex3i(125, 260, 0);

    glVertex3i(200, 140, 0);
    glVertex3i(250, 140, 0);
    glVertex3i(225, 180, 0);

    glVertex3i(300, 220, 0);
    glVertex3i(350, 220, 0);
    glVertex3i(325, 260, 0);

    glVertex3i(400, 140, 0);
    glVertex3i(450, 140, 0);
    glVertex3i(425, 180, 0);

    glVertex3i(500, 220, 0);
    glVertex3i(550, 220, 0);
    glVertex3i(525, 260, 0);

    glVertex3i(600, 140, 0);
    glVertex3i(650, 140, 0);
    glVertex3i(625, 180, 0);

    glVertex3i(700, 220, 0);
    glVertex3i(750, 220, 0);
    glVertex3i(725, 260, 0);

    glVertex3i(800, 140, 0);
    glVertex3i(850, 140, 0);
    glVertex3i(825, 180, 0);
    glEnd();
       glLoadIdentity();

}

void NightBuilding(void)
{
    //Left Border
    glBegin(GL_QUADS);
    glColor3ub(140, 60, 0);
    glVertex3i(0, 230, 0);
    glVertex3i(220, 230, 0);
    glVertex3i(200, 240, 0);
    glVertex3i(0, 240, 0);
    //Right Border
    glVertex3i(480, 230, 0);
    glVertex3i(1400, 230, 0);
    glVertex3i(1400, 240, 0);
    glVertex3i(500, 240, 0);
    glEnd();

    //Left Building
    glBegin(GL_QUADS);
    glColor3ub(100, 0, 0);
    glVertex3i(0, 240, 0);
    glVertex3i(200, 240, 0);
    glVertex3i(200, 380, 0);
    glVertex3i(0, 380, 0);
    //Right Building
    glVertex3i(500, 240, 0);
    glVertex3i(1400, 240, 0);
    glVertex3i(1400, 380, 0);
    glVertex3i(500, 380, 0);
    glEnd();

    //shed pillars
    glBegin(GL_QUADS);
    glColor3ub(20, 20, 20);
    glVertex3i(0, 240, 0);
    glVertex3i(10, 240, 0);
    glVertex3i(10, 380, 0);
    glVertex3i(0, 380, 0);

    glVertex3i(680, 240, 0);
    glVertex3i(690, 240, 0);
    glVertex3i(690, 380, 0);
    glVertex3i(680, 380, 0);

    glVertex3i(840, 240, 0);
    glVertex3i(850, 240, 0);
    glVertex3i(850, 380, 0);
    glVertex3i(840, 380, 0);

    glVertex3i(1000, 240, 0);
    glVertex3i(1010, 240, 0);
    glVertex3i(1010, 380, 0);
    glVertex3i(1000, 380, 0);

    glVertex3i(1160, 240, 0);
    glVertex3i(1170, 240, 0);
    glVertex3i(1170, 380, 0);
    glVertex3i(1160, 380, 0);

    glVertex3i(1320, 240, 0);
    glVertex3i(1330, 240, 0);
    glVertex3i(1330, 380, 0);
    glVertex3i(1320, 380, 0);
    glEnd();

    //2nd Floor Glass
    glColor3ub(135, 200, 250);
    glBegin(GL_QUADS);
    glVertex3i(0, 475, 0);
    glVertex3i(1400, 475, 0);
    glVertex3i(1400, 420, 0);
    glVertex3i(0, 420, 0);
    glEnd();

    //Left Pillar
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3i(170, 240, 0);
    glVertex3i(200, 240, 0);
    glVertex3i(200, 580, 0);
    glVertex3i(170, 580, 0);
    //Right Pillar
    glVertex3i(500, 240, 0);
    glVertex3i(530, 240, 0);
    glVertex3i(530, 580, 0);
    glVertex3i(500, 580, 0);
    //Center Board
    glVertex3i(200, 530, 0);
    glVertex3i(500, 530, 0);
    glVertex3i(500, 580, 0);
    glVertex3i(200, 580, 0);
    glEnd();

    //Top Beam
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3i(0, 510, 0);
    glVertex3i(1400, 510, 0);
    glVertex3i(1400, 530, 0);
    glVertex3i(0, 530, 0);

    //2nd Floor Beam
    glVertex3i(0, 400, 0);
    glVertex3i(1400, 400, 0);
    glVertex3i(1400, 420, 0);
    glVertex3i(0, 420, 0);

    //Handle Bar
    glVertex3i(0, 475, 0);
    glVertex3i(1400, 475, 0);
    glVertex3i(1400, 480, 0);
    glVertex3i(0, 480, 0);
    glEnd();

    //2nd Floor Bottom Border
    glColor3ub(211, 211, 211);
    glBegin(GL_QUADS);
    glVertex3i(0, 420, 0);
    glVertex3i(1400, 420, 0);
    glVertex3i(1400, 430, 0);
    glVertex3i(0, 430, 0);
    //2nd Floor Top Left Border
    glVertex3i(0, 530, 0);
    glVertex3i(170, 530, 0);
    glVertex3i(170, 540, 0);
    glVertex3i(0, 540, 0);
    //2nd Floor Top Right Border
    glVertex3i(530, 530, 0);
    glVertex3i(1400, 530, 0);
    glVertex3i(1400, 540, 0);
    glVertex3i(530, 540, 0);
    glEnd();

    //Left Shade
    glBegin(GL_QUADS);
    glColor3ub(0, 70, 70);
    glVertex3i(0, 380, 0);
    glVertex3i(220, 380, 0);
    glVertex3i(200, 400, 0);
    glVertex3i(0, 400, 0);
    //Right Shade
    glVertex3i(480, 380, 0);
    glVertex3i(1400, 380, 0);
    glVertex3i(1400, 400, 0);
    glVertex3i(500, 400, 0);
    glEnd();

    //2nd Floor Pillars
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3i(0, 430, 0);
    glVertex3i(15, 430, 0);
    glVertex3i(15, 530, 0);
    glVertex3i(0, 530, 0);

    glVertex3i(685, 430, 0);
    glVertex3i(700, 430, 0);
    glVertex3i(700, 530, 0);
    glVertex3i(685, 530, 0);

    glVertex3i(855, 430, 0);
    glVertex3i(870, 430, 0);
    glVertex3i(870, 530, 0);
    glVertex3i(855, 530, 0);

    glVertex3i(1025, 430, 0);
    glVertex3i(1040, 430, 0);
    glVertex3i(1040, 530, 0);
    glVertex3i(1025, 530, 0);

    glVertex3i(1195, 430, 0);
    glVertex3i(1210, 430, 0);
    glVertex3i(1210, 530, 0);
    glVertex3i(1195, 530, 0);

    glVertex3i(1365, 430, 0);
    glVertex3i(1380, 430, 0);
    glVertex3i(1380, 530, 0);
    glVertex3i(1365, 530, 0);
    glEnd();

    //Roof
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 70, 0);
    glVertex3i(150, 580, 0);
    glVertex3i(550, 580, 0);
    glVertex3i(350, 610, 0);
    glEnd();
}

void NightWindows(void)
{
    //Window Borders
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3i(40, 280, 0);
    glVertex3i(120, 280, 0);
    glVertex3i(120, 360, 0);
    glVertex3i(40, 360, 0);

    glVertex3i(570, 280, 0);
    glVertex3i(650, 280, 0);
    glVertex3i(650, 360, 0);
    glVertex3i(570, 360, 0);

    glVertex3i(730, 280, 0);
    glVertex3i(810, 280, 0);
    glVertex3i(810, 360, 0);
    glVertex3i(730, 360, 0);

    glVertex3i(890, 280, 0);
    glVertex3i(970, 280, 0);
    glVertex3i(970, 360, 0);
    glVertex3i(890, 360, 0);

    glVertex3i(1050, 280, 0);
    glVertex3i(1130, 280, 0);
    glVertex3i(1130, 360, 0);
    glVertex3i(1050, 360, 0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(40, 280, 0);
    glVertex3i(120, 280, 0);
    glVertex3i(120, 360, 0);
    glVertex3i(40, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(570, 280, 0);
    glVertex3i(650, 280, 0);
    glVertex3i(650, 360, 0);
    glVertex3i(570, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(730, 280, 0);
    glVertex3i(810, 280, 0);
    glVertex3i(810, 360, 0);
    glVertex3i(730, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(890, 280, 0);
    glVertex3i(970, 280, 0);
    glVertex3i(970, 360, 0);
    glVertex3i(890, 360, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(1050, 280, 0);
    glVertex3i(1130, 280, 0);
    glVertex3i(1130, 360, 0);
    glVertex3i(1050, 360, 0);
    glEnd();
    //window glass
    glColor3ub(255, 255, 100);
    glBegin(GL_QUADS);
    glVertex3i(45, 285, 0);
    glVertex3i(76, 285, 0);
    glVertex3i(76, 318, 0);
    glVertex3i(45, 318, 0);

    glVertex3i(45, 322, 0);
    glVertex3i(76, 322, 0);
    glVertex3i(76, 355, 0);
    glVertex3i(45, 355, 0);

    glVertex3i(79, 322, 0);
    glVertex3i(115, 322, 0);
    glVertex3i(115, 355, 0);
    glVertex3i(79, 355, 0);

    glVertex3i(79, 285, 0);
    glVertex3i(115, 285, 0);
    glVertex3i(115, 318, 0);
    glVertex3i(79, 318, 0);

    glVertex3i(575, 285, 0);
    glVertex3i(606, 285, 0);
    glVertex3i(606, 318, 0);
    glVertex3i(575, 318, 0);

    glVertex3i(575, 322, 0);
    glVertex3i(606, 322, 0);
    glVertex3i(606, 355, 0);
    glVertex3i(575, 355, 0);

    glVertex3i(609, 322, 0);
    glVertex3i(645, 322, 0);
    glVertex3i(645, 355, 0);
    glVertex3i(609, 355, 0);

    glVertex3i(609, 285, 0);
    glVertex3i(645, 285, 0);
    glVertex3i(645, 318, 0);
    glVertex3i(609, 318, 0);

    glVertex3i(79, 285, 0);
    glVertex3i(115, 285, 0);
    glVertex3i(115, 318, 0);
    glVertex3i(79, 318, 0);

    glVertex3i(735, 285, 0);
    glVertex3i(766, 285, 0);
    glVertex3i(766, 318, 0);
    glVertex3i(735, 318, 0);

    glVertex3i(735, 322, 0);
    glVertex3i(766, 322, 0);
    glVertex3i(766, 355, 0);
    glVertex3i(735, 355, 0);

    glVertex3i(769, 322, 0);
    glVertex3i(805, 322, 0);
    glVertex3i(805, 355, 0);
    glVertex3i(769, 355, 0);

    glVertex3i(769, 285, 0);
    glVertex3i(805, 285, 0);
    glVertex3i(805, 318, 0);
    glVertex3i(769, 318, 0);

    glVertex3i(895, 285, 0);
    glVertex3i(926, 285, 0);
    glVertex3i(926, 318, 0);
    glVertex3i(895, 318, 0);

    glVertex3i(895, 322, 0);
    glVertex3i(926, 322, 0);
    glVertex3i(926, 355, 0);
    glVertex3i(895, 355, 0);

    glVertex3i(929, 322, 0);
    glVertex3i(965, 322, 0);
    glVertex3i(965, 355, 0);
    glVertex3i(929, 355, 0);

    glVertex3i(929, 285, 0);
    glVertex3i(965, 285, 0);
    glVertex3i(965, 318, 0);
    glVertex3i(929, 318, 0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(45, 285, 0);
    glVertex3i(76, 285, 0);
    glVertex3i(76, 318, 0);
    glVertex3i(45, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(45, 322, 0);
    glVertex3i(76, 322, 0);
    glVertex3i(76, 355, 0);
    glVertex3i(45, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(79, 322, 0);
    glVertex3i(115, 322, 0);
    glVertex3i(115, 355, 0);
    glVertex3i(79, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(79, 285, 0);
    glVertex3i(115, 285, 0);
    glVertex3i(115, 318, 0);
    glVertex3i(79, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(575, 285, 0);
    glVertex3i(606, 285, 0);
    glVertex3i(606, 318, 0);
    glVertex3i(575, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(575, 322, 0);
    glVertex3i(606, 322, 0);
    glVertex3i(606, 355, 0);
    glVertex3i(575, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(609, 322, 0);
    glVertex3i(645, 322, 0);
    glVertex3i(645, 355, 0);
    glVertex3i(609, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(609, 285, 0);
    glVertex3i(645, 285, 0);
    glVertex3i(645, 318, 0);
    glVertex3i(609, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(79, 285, 0);
    glVertex3i(115, 285, 0);
    glVertex3i(115, 318, 0);
    glVertex3i(79, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(735, 285, 0);
    glVertex3i(766, 285, 0);
    glVertex3i(766, 318, 0);
    glVertex3i(735, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(735, 322, 0);
    glVertex3i(766, 322, 0);
    glVertex3i(766, 355, 0);
    glVertex3i(735, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(769, 322, 0);
    glVertex3i(805, 322, 0);
    glVertex3i(805, 355, 0);
    glVertex3i(769, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(769, 285, 0);
    glVertex3i(805, 285, 0);
    glVertex3i(805, 318, 0);
    glVertex3i(769, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(895, 285, 0);
    glVertex3i(926, 285, 0);
    glVertex3i(926, 318, 0);
    glVertex3i(895, 318, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(895, 322, 0);
    glVertex3i(926, 322, 0);
    glVertex3i(926, 355, 0);
    glVertex3i(895, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(929, 322, 0);
    glVertex3i(965, 322, 0);
    glVertex3i(965, 355, 0);
    glVertex3i(929, 355, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(929, 285, 0);
    glVertex3i(965, 285, 0);
    glVertex3i(965, 318, 0);
    glVertex3i(929, 318, 0);
    glEnd();
}

void NightGlobe(void)
{
    //Globe Platform
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex3i(1050, 100,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1400, 200,0);
    glVertex3i(1100, 200,0);

    glColor3ub(211, 211, 211);
    glBegin(GL_QUADS);
    glVertex3i(1050, 90,0);
    glVertex3i(1400, 90,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1050, 100,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1050, 100,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1400, 200,0);
    glVertex3i(1100, 200,0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(1050, 90,0);
    glVertex3i(1400, 90,0);
    glVertex3i(1400, 100,0);
    glVertex3i(1050, 100,0);
    glEnd();

    //Globe Base
    glColor3ub(100, 120, 140);
    glBegin(GL_QUADS);
    glVertex3i(1100, 130,0);
    glVertex3i(1400, 130,0);
    glVertex3i(1400, 350,0);
    glVertex3i(1100, 350,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1100, 130,0);
    glVertex3i(1500, 130,0);
    glVertex3i(1500, 350,0);
    glVertex3i(1100, 350,0);
    glEnd();

    //Globe
    glBegin(GL_POLYGON);
    glColor3ub (100, 120, 140);
    int X1=1200,Y1=680,d=420;
    int i,l;
    float x, y;

    for(i=0;d>=i;i++)
    {
        y=sqrt((d*d)-(i*i));
        l=round(y);
        glVertex2i(X1+i,Y1-l);
    }
    for(i=0;d>=i;i++)
    {
        x=sqrt((d*d)-(i*i));
        l=round(x);
        glVertex2i(X1+l,Y1+i);
    }
    for(i=0;d>=i;i++)
    {
        y=sqrt((d*d)-(i*i));
        l=round(y);
        glVertex2i(X1-i,Y1+l);
    }
    for(i=0;d>=i;i++)
    {
        x=sqrt((d*d)-(i*i));
        l=round(x);
        glVertex2i(X1-l,Y1-i);
    }
    glEnd();

    //globe windows
    glColor3ub(255, 255, 100);
    glBegin(GL_QUADS);
    glVertex3i(1100, 160,0);
    glVertex3i(1400, 160,0);
    glVertex3i(1400, 270,0);
    glVertex3i(1100, 270,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(870, 420,0);
    glVertex3i(1400, 420,0);
    glVertex3i(1400, 550,0);
    glVertex3i(801, 550,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(786, 620,0);
    glVertex3i(1400, 620,0);
    glVertex3i(1400, 750,0);
    glVertex3i(785, 750,0);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1100, 160,0);
    glVertex3i(1400, 160,0);
    glVertex3i(1400, 270,0);
    glVertex3i(1100, 270,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3i(870, 420,0);
    glVertex3i(1400, 420,0);
    glVertex3i(1400, 550,0);
    glVertex3i(801, 550,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3i(786, 620,0);
    glVertex3i(1400, 620,0);
    glVertex3i(1400, 750,0);
    glVertex3i(785, 750,0);
    glEnd();

    //globe door
    glColor3ub(211, 211, 211);
    glBegin(GL_QUADS);
    glVertex3i(1250, 130,0);
    glVertex3i(1385, 130,0);
    glVertex3i(1385, 280,0);
    glVertex3i(1250, 280,0);
    glEnd();

    glColor3ub(150, 150, 150);
    glBegin(GL_QUADS);
    glVertex3i(1255, 130,0);
    glVertex3i(1380, 130,0);
    glVertex3i(1380, 275,0);
    glVertex3i(1255, 275,0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3i(1250, 130,0);
    glVertex3i(1385, 130,0);
    glVertex3i(1385, 280,0);
    glVertex3i(1250, 280,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3i(1255, 130,0);
    glVertex3i(1380, 130,0);
    glVertex3i(1380, 275,0);
    glVertex3i(1255, 275,0);
    glEnd();
}

void NightView(void)
{
    NightSky();

    Road();

    NightGarden();

    NightBuilding();

    NightWindows();

    NightObjects();

    if(carv)
        {
            //car1();
            car2();
        }
    if(cloudv)
        {
            cloud();
        }

    glPopMatrix();

    NightGlobe();

    if(rainv)
        {
            rain();
        }

}

void myDisplay(void)
{
    glPushMatrix();
    glTranslatef(translate_x,translate_y,translate_z);

    if(day==2)
    {
       NightView();
    }
    else if(day==1)
    {
        DayView();
    }
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='d')
        {
            day=1;
            myDisplay();
        }
    else if(key=='n')
        {
            day=2;
            myDisplay();
        }
    else if(key=='c')
        {
            carv=true;
            myDisplay();
        }
    else if(key=='v')
        {
            carv=false;
            myDisplay();
        }
    else if(key=='z')
        {
            cloudv=true;
            myDisplay();
        }
    else if(key=='x')
        {
            cloudv=false;
            myDisplay();
        }
    else if(key=='r')
        {
            rainv=true;
            myDisplay();
        }
    else if(key=='t')
        {
            rainv=false;
            myDisplay();
        }
}

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1400.0, 0.0, 700.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1400, 700);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("AIUB Campus View");
    myInit ();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
    return 0;
}

