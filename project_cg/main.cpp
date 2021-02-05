#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

float X;
float Y;
float enemymove = 0.0f;

GLfloat wholemove = 0.0f;

bool enemy1=true, enemy2=true, enemy3=true;

void update(int value) {

	glutPostRedisplay();
	enemymove -=0.01;

	glutTimerFunc(100, update, 0);
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
            X=(float(x)-350)/350;
            Y=(float(y)-350)/350*(-1);

            printf("clicked at (%f, %f)\n", X, Y);
            if(X>-0.9 && X<-0.7 && Y<(enemymove+0.1+.8) && Y>(enemymove-0.1+.8))
                {
                    enemy1=false;
                    printf("%f",&enemymove);
                }

            if(X>-0.4 && X<-0.2)
                {
                    if(enemymove>0)
                    {
                        if(Y>(enemymove+.1+.8) && Y<(enemymove-.1+.8)){
                        enemy2=false;

                                    }}


            else{if(Y>(enemymove-.1+.8) && Y<(enemymove+.1+.8))
                {
                    enemy2=false;
                }
        }
    }
        if(X>0.2 && X<0.4)
            {
            if(enemymove>0)
                {
                if(Y>(enemymove+.1+.8) && Y<(enemymove-.1+.8))
                    {
                    enemy3=false;
                    }
                }
            else{
                    if(Y>(enemymove-.1+.8) && Y<(enemymove+.1+.8))
                    {
                        enemy3=false;
                    }
                }
            }
		}
	}
	glutPostRedisplay();
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();


    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f,enemymove, 0.0f);

    if(enemy1==true)
    {
    glBegin(GL_TRIANGLES);

      glVertex2f(-0.9f, 0.9f);
      glVertex2f(-0.7f, 0.9f);
      glVertex2f(-0.8f, 0.8f);

    glEnd();
    }
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f,enemymove, 0.0f);

    if(enemy2==true)
    {
    glBegin(GL_TRIANGLES);
      glVertex2f(-0.4f, 0.9f);
      glVertex2f(-0.2f, 0.9f);
      glVertex2f(-0.3f, 0.8f);

    glEnd();
    }
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f,enemymove, 0.0f);

    if(enemy3==true)
    {
    glBegin(GL_TRIANGLES);
      glVertex2f( 0.4f, 0.9f);
      glVertex2f( 0.2f, 0.9f);
      glVertex2f( 0.3f, 0.8f);

    glEnd();
    }
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f,enemymove, 0.0f);
    glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(700, 700);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Mouse Game");
   glutDisplayFunc(display);
   init();



   glutMouseFunc(handleMouse);

   glutTimerFunc(100, update, 0);

   glutMainLoop();
   return 0;
}
