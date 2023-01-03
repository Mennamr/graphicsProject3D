#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>


float angle=0;
bool Rx=0;
bool Ry=0;
bool Rz=0;
float Ty=0;
float Tx=0;
float Tz=0;
float approach=0;

void donut(){
        //plain donut
        glColor3f(0.87,0.596,0.317);
        glRotatef(130+angle,1,0,0);
        glutSolidTorus(0.09,0.18,30,30);

        //white chocolate donut
        glColor3f(1,1,0.7);
        glTranslatef(1,0,0);
        glutSolidTorus(0.09,0.18,30,30);

        //blueberry donut
        glColor3f(0.8,0.5,1);
        glTranslatef(1,0,0);
        glutSolidTorus(0.09,0.18,30,30);

        //chocolate donut
        glColor3f(0.6,0.4,0.2);
        glTranslatef(1,0,0);
        glutSolidTorus(0.09,0.18,30,30);
}
void table(){
    //glRotatef(125,1,0,0);
    glRotatef(280,1,0,0);
    glRotatef(0,0,0,1);
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
void pieceOfCake(){
    //glRotatef(angle,Rx,Ry,Rz);
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
      glColor3f(0.9, 0.4, 0.0);     // Red
      glVertex3f(0, c, c);
      glVertex3f(c, -c, c);
      glVertex3f(c, -c, -c);
      glVertex3f(0, c, -c);
    glEnd();


// Back blue
    glBegin(GL_TRIANGLES);
      glColor3f(1,1,1);    // Red
      glVertex3f(0, c, -c);
      glVertex3f(c, -c, -c);
      glVertex3f(-c, -c, -c);
    glEnd();


    // Left yellow
    glBegin(GL_QUADS);
      glColor3f(0.9, 0.4, 0.0);     // Blue
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
    glRotatef(angle,1,0,0);
    //glutSolidCube(2);
    glutSolidSphere(1,30,30);
    glTranslatef(0,-1,-0.65);
    glutSolidCube(2);
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

//------------------------------  display   -------------------------------
int zRotated=0;
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
        glTranslatef(-4.8,2.3,2);
        donut();
    glPopMatrix();


    //Tarte (triangle with rectangular sides)
    glPushMatrix();

        glTranslatef(2.2,-1,6.5);
        glRotatef(290,1,0,0);
        glRotatef(40,0,0,1);
        pieceOfCake();
        glTranslatef(-0.6+Tx,0,0);
        pieceOfCake();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(Tx,Ty,approach);
        ghost();
    glPopMatrix();
    while(approach<6){
    approach+=0.1;
    }
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
        Tz+=0.2;
    }
    if(key==GLUT_KEY_LEFT){
        Tx+=0.2;
    }
    if(key==GLUT_KEY_DOWN){
        Ty+=0.2;
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
