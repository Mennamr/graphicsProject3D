

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include<mmsystem.h>



float angle=0;
bool Rx=0;
bool Ry=0;
bool Rz=0;
float Ty=0;
float Tx=0;
float Tyy=0;
float Tz=0;
float approach=0;
float away=0;
bool awayFlag=0;
bool hauntFlag=0;

void donut(){
        glTranslatef(0,0,0);
        //plain donut
        glColor3f(0.87,0.596,0.317);
        glRotatef(130,1,0,0);
        glutSolidTorus(0.09,0.18,30,30);

        //white chocolate donut
        glColor3f(1,1,0.7);
        glTranslatef(1,0,0);
        glutSolidTorus(0.09,0.18,30,30);

        //chocolate donut
        glColor3f(0.6,0.4,0.2);
        glTranslatef(2,0,0);
        glutSolidTorus(0.09,0.18,30,30);

         //blueberry donut
        glColor3f(0.8,0.5,1);
        glTranslatef(-1,0+Ty,0+Tz);
        glutSolidTorus(0.09,0.18,30,30);

}
void table(){

    glRotatef(280,1,0,0);
    glRotatef(0,0,0,1);
    float cx=3.5;
    float cy=1.5;


   glBegin(GL_QUADS);
   glColor3f(0.84,0.596,0.3176); //light brown
   glColor3f(0.5,0.337,0.157); //dark brown
   glColor3f(0.62,0.412,0.2); //medium brown

      // Top
      glColor3f(0.62,0.412,0.2);
      glVertex3f( cx, cy, -1);
      glVertex3f(-cx, cy, -1);
      glVertex3f(-cx, cy,  1);
      glVertex3f( cx, cy,  1);

      // Bottom
      glColor3f(0.62,0.412,0.2) ;
      glVertex3f( cx, -cy,  1);
      glVertex3f(-cx, -cy,  1);
      glVertex3f(-cx, -cy, -1);
      glVertex3f( cx, -cy, -1);

      // Front
      glColor3f(0.84,0.596,0.3176);
      glVertex3f( cx,  cy, 1);
      glVertex3f(-cx,  cy, 1);
      glVertex3f(-cx, -cy, 1);
      glVertex3f( cx, -cy, 1);

      // Back
      glColor3f(0.84,0.596,0.3176);
      glVertex3f( cx, -cy, -1);
      glVertex3f(-cx, -cy, -1);
      glVertex3f(-cx,  cy, -1);
      glVertex3f( cx,  cy, -1);

      // Left
      glColor3f(0.5,0.337,0.157);
      glVertex3f(-cx,  cy,  1);
      glVertex3f(-cx,  cy, -1);
      glVertex3f(-cx, -cy, -1);
      glVertex3f(-cx, -cy,  1);

      // Right
      glColor3f(0.5,0.337,0.157);
      glVertex3f(cx,  cy, -1);
      glVertex3f(cx,  cy,  1);
      glVertex3f(cx, -cy,  1);
      glVertex3f(cx, -cy, -1);
   glEnd();
}
void pieceOfCake(){

    float c=0.18;

    // Front black
    glBegin(GL_TRIANGLES);
      glColor3f(1,0.7,0);
      glVertex3f( 0, c, c);
      glVertex3f(-c, -c, c);
      glVertex3f(c, -c, c);
    glEnd();


    // Right green
    glBegin(GL_QUADS);
      glColor3f(0.9, 0.4, 0.0);
      glVertex3f(0, c, c);
      glVertex3f(c, -c, c);
      glVertex3f(c, -c, -c);
      glVertex3f(0, c, -c);
    glEnd();


// Back blue
    glBegin(GL_TRIANGLES);
      glColor3f(1,1,1);
      glVertex3f(0, c, -c);
      glVertex3f(c, -c, -c);
      glVertex3f(-c, -c, -c);
    glEnd();


    // Left yellow
    glBegin(GL_QUADS);
      glColor3f(0.9, 0.4, 0.0);
      glVertex3f(-c, -c, c);
      glVertex3f( 0, c, c);
      glVertex3f(0, c, -c);
      glVertex3f(-c, -c, -c);
   glEnd();


    //bottom pink
   glBegin(GL_QUADS);
      glColor3f(1, 0.5, 0.1);     // Blue
      glVertex3f(c, -c, c);
      glVertex3f(-c, -c, c);
      glVertex3f(-c, -c, -c);
      glVertex3f(c, -c, -c);
   glEnd();

}

void ghost(){
    glTranslated(0,0,-5);
    glColor3f(1,1,1);
    //glRotatef(angle,1,0,0);

    //head
    glutSolidSphere(1,30,30);
    glTranslatef(0,-1,-0.65);

    //
    glPushMatrix();
    glTranslatef(0,0,-0.1);
    glutSolidCube(2);
    glPopMatrix();

    glColor3f(0,0,0);

    //right eye
    glTranslatef(0.3,1.4,1.6);
    glutSolidSphere(0.18,30,30);

    //left eye
    glTranslatef(-0.47,0,0.01);
    glutSolidSphere(0.18,30,30);

    //mouth
    glColor3f(0.8,0,0);
    glTranslatef(0.2,-0.6,-0.1);
    glutSolidSphere(0.2,30,30);

}
void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void idleFunc (void)
{

    if(approach<7){
        approach+=0.08;
    }
    if(Ty<-1.6){
        Tz=15;
        awayFlag=1;
    }

    if(awayFlag){
        away-=0.02;
        if(away<-9){
            awayFlag=false;
            hauntFlag=true;
            //away=-5;
        }
        if(hauntFlag){
            if(Tyy<2.5){
            Tyy+=0.02;
            }
            else{
                Tx-=0.02;
            }
        }
    }

    glutPostRedisplay();
}
//------------------------------  display   -------------------------------

void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);


    //table (parallelepipede rectangle)
    glPushMatrix();
        glTranslatef(0,-2.5,4);
        table();
    glPopMatrix();


    //Donuts (torus)
    glPushMatrix();
        glTranslatef(2.8,-3.5,4);
        glTranslatef(-4.8+Tx,2.3+Tyy,2);
        donut();
    glPopMatrix();


    //piece of cake (triangle with rectangular sides)
    glPushMatrix();
        glTranslatef(2.2,-1.1,6.5);
        glRotatef(290,1,0,0);
        glRotatef(40,0,0,1);
        pieceOfCake();
        glTranslatef(-0.6,0,0);
        pieceOfCake();
    glPopMatrix();


    //teapot
    glPushMatrix();
        glTranslatef(1.1,-0.45,9.5);
        glColor3f(1,1,0);
        glutSolidTeapot(0.2);
    glPopMatrix();


    //ghost
    glPushMatrix();
        glTranslatef(away,0,approach);
        ghost();
    glPopMatrix();

    glFlush();


    glutSwapBuffers();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}
void keyEvent(int key, int x, int y){
    if(key==GLUT_KEY_UP){
            Ty-=0.2;

    }
   /* if(key==GLUT_KEY_RIGHT){
        Tyy+=0.2;
    }
    if(key==GLUT_KEY_LEFT){
        Tx-=0.2;
    }
    if(key==GLUT_KEY_DOWN){
        Ty+=0.2;
    }*/

}

//----------------------------------  main  ------------------------------------

int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (500, 50);
    glutCreateWindow       ("20102899");
    //glOrtho(-50,50,-50,50,-50,50);

    glClearColor (1.0, 1.0, 1.0, 0.0);

    glutDisplayFunc (display);
    glutSpecialFunc(keyEvent);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);

   // PlaySound("falling.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glClearColor(1,1,1,1);
    texture();


    glutMainLoop();
}
