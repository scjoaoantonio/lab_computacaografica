#include <GL/glut.h>
#include <math.h>

float v1 = 0.0, v2 = 0.0, v3 = 0.0;
float radio = 20, calx, caly;
float PI = 3.14;
void 
meuTeclado(unsigned char key, int x, int y){
// esc = 27
switch (key)
{
case 27:
  exit(0);
  break;

case '+':
  v1 += 1;
  v2 += 1;
  v3 += 1;
  glutPostRedisplay();
  break;

case '-':
  v1 -= 1;
  v2 -= 1;
  v3 -= 1;
  glutPostRedisplay();
  break;

default:
  break;
}
}

void
reshape(int w, int h)
{

  glViewport(0, 0, w, h);       
  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();             
  glOrtho(0, w, 0, h, -1, 1); 
  glScalef(1, -1, 1);       
  glTranslatef(0, -h, 0);
}

void
display(void)
{
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  /* red */ 
    glVertex2i(100, 50);
    glVertex2i(200, 200);
    glVertex2i(0, 200);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(v1,v2,v3);
    for (double i = 0; i < 2 * PI; i += 0.01) {
        calx = radio * cos(i) + 100; 
        caly = radio * sin(i) + 150;
        glVertex2f(calx, caly);
    }
    glEnd();


glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);  /* azul claro baixo */
    glVertex2i(120, 50);
    glVertex2i(120, 30);
    glVertex2i(140, 30);
    glVertex2i(140, 50);
glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);  /* azul claro cima */
    glVertex2i(110, 10);
    glVertex2i(110, 30);
    glVertex2i(150, 30);
    glVertex2i(150, 10);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (double i = 0; i < 2 * PI; i += 0.01) {
        calx = radio * cos(i) + 180; 
        caly = radio * sin(i) + 20;
        glVertex2f(calx, caly);
    }
glEnd();
glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (double i = 0; i < 2 * PI; i += 0.01) {
        calx = radio * cos(i) + 220; 
        caly = radio * sin(i) + 20;
        glVertex2f(calx, caly);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (double i = 0; i < 2 * PI; i += 0.01) {
        calx = radio * cos(i) + 200; 
        caly = radio * sin(i) + 20;
        glVertex2f(calx, caly);
    }
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);  /* yellow */
    glVertex2i(120, 50);
    glVertex2i(120, 30);
    glVertex2i(140, 30);
    glVertex2i(140, 50);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);  /* blue */
    glVertex2i(100, 50);
    glVertex2i(200, 200);
    glVertex2i(500, 200);
    glVertex2i(400, 50);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);  /* yellow */
    glVertex2i(0, 200);
    glVertex2i(200, 200);
    glVertex2i(200, 400);
    glVertex2i(0, 400);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);  /* azul claro porta */
    glVertex2i(80, 300);
    glVertex2i(120, 300);
    glVertex2i(120, 400);
    glVertex2i(80, 400);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); /*green*/
    glVertex2i(200, 200);
    glVertex2i(500, 200);
    glVertex2i(500, 400);
    glVertex2i(200, 400);
glEnd();

 glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);  // Cor azul
    glVertex2i(220, 250);
    glVertex2i(320, 250);
    glVertex2i(320, 350);
    glVertex2i(220, 350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);  // Cor vermelha
    glVertex2i(360, 250);
    glVertex2i(460, 250);
    glVertex2i(460, 350);
    glVertex2i(360, 350);
    glEnd();


glFlush();  /* Single buffered, so needs a flush. */
}

int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640,480);
  glutCreateWindow("single triangle");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(meuTeclado);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
