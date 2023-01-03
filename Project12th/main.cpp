#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>


float angle=15;
bool Rx=0;
bool Ry=0;
//------------------------------  reshapeFunc  ---------------------------------
void table(){
    //glRotatef(125,1,0,0);
    glRotatef(280,1,0,0);
    glRotatef(25,0,0,1);
    float cx=3.5;
    float cy=1.5;
   glBegin(GL_QUADS);
   glColor3f(0.84,0.596,0.3176); //light brown
   glColor3f(0.5,0.337,0.157); //dark brown
   glColor3f(0.62,0.412,0.2); //medium brown
                 // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out

      glColor3f(0.62,0.412,0.2);
      glVertex3f( cx, cy, -1);
      glVertex3f(-cx, cy, -1);
      glVertex3f(-cx, cy,  1);
      glVertex3f( cx, cy,  1);

      // Bottom face (y = -1.0f)
      glColor3f(0.62,0.412,0.2) ;    // Orange
      glVertex3f( cx, -cy,  1);
      glVertex3f(-cx, -cy,  1);
      glVertex3f(-cx, -cy, -1);
      glVertex3f( cx, -cy, -1);

      // Front face  (z = 1.0f)
      glColor3f(0.84,0.596,0.3176);// Red
      glVertex3f( cx,  cy, 1);
      glVertex3f(-cx,  cy, 1);
      glVertex3f(-cx, -cy, 1);
      glVertex3f( cx, -cy, 1);

      // Back face (z = -1.0f)
      glColor3f(0.84,0.596,0.3176);     // Yellow
      glVertex3f( cx, -cy, -1.0f);
      glVertex3f(-cx, -cy, -1.0f);
      glVertex3f(-cx,  cy, -1.0f);
      glVertex3f( cx,  cy, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.5,0.337,0.157);// Blue
      glVertex3f(-cx,  cy,  1.0f);
      glVertex3f(-cx,  cy, -1.0f);
      glVertex3f(-cx, -cy, -1.0f);
      glVertex3f(-cx, -cy,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(0.5,0.337,0.157);   // Magenta
      glVertex3f(cx,  cy, -1.0f);
      glVertex3f(cx,  cy,  1.0f);
      glVertex3f(cx, -cy,  1.0f);
      glVertex3f(cx, -cy, -1.0f);
   glEnd();  // End of drawing color-cube
}
void donut(){

    glutSolidTorus(2,4,2,2);
}
void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------
int zRotated=0;
void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);


    //table (parallelepipede rectangle)
    glPushMatrix();
    glTranslatef(0.5,-2.5,5.5);
    table();
    glPopMatrix();

    //Donuts
    glPushMatrix();
    glTranslatef(0,8,0);
    donut();
    glPopMatrix();


    glColor3f (0.1, 0.2, 0.8);              // Blue ball displaced to right.
    /*glPushMatrix ();
       glTranslatef    (1.5, 0.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (zRotated, 0,0,1);
       glutSolidSphere (1.0, 5, 30);
    glPopMatrix ();


    glPushMatrix ();
       glTranslatef    (1.8, 0.0, 0.0);
       glRotatef(angle,Rx,Ry,0);
       glutWireTeapot(2);
    glPopMatrix ();*/

    glFlush();


    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    //angle+=0.5;
    glutPostRedisplay();
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
            angle+=5;

    }
    if(key==GLUT_KEY_RIGHT){
        Ry=0;
        Rx=1;
    }
    if(key==GLUT_KEY_LEFT){
        Ry=1;
        Rx=0;
    }

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

    glClearColor(1,1,1,1);
    texture();


    glutMainLoop();
}
