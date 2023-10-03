#include <GL/glut.h>
#include <stdlib.h>

float posX = 0.0, posY = 0.0;
float transX = 0.0, transY = 0.0, transZ = -10.0;  // Ajuste a posição Z para uma visão mais distante
int win_id;

void desenhaCubo()
{
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	// frente
	glVertex3f(-5.5f, -5.5f, 5.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 5.0f, -5.5f, 5.0f);
	glVertex3f( 5.0f, 5.0f, 5.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.5f, 5.0f, 5.0f);
	// costa
	glVertex3f(-5.5f, -5.5f, -5.5f);
	glVertex3f(-5.5f, 5.0f, -5.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 5.0f, 5.0f, -5.5f);
	glVertex3f( 5.0f, -5.5f, -5.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	// esquerda
	glVertex3f(-5.5f, -5.5f, 5.0f);
	glVertex3f(-5.5f, 5.0f, 5.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-5.5f, 5.0f, -5.5f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-5.5f, -5.5f, -5.5f);
	// direita
	glVertex3f( 5.0f, -5.5f, -5.5f);
	glVertex3f( 5.0f, 5.0f, -5.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 5.0f, 5.0f, 5.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f( 5.0f, -5.5f, 5.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	// teto
	glVertex3f(-5.5f, 5.0f, 5.0f);
	glVertex3f( 5.0f, 5.0f, 5.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( 5.0f, 5.0f, -5.5f);
	glVertex3f(-5.5f, 5.0f, -5.5f);
	glColor3f(1.0f, 0.0f, 0.0f);
	// chao
	glVertex3f(-5.5f, -5.5f, 5.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-5.5f, -5.5f, -5.5f);
	glVertex3f( 5.0f, -5.5f, -5.5f);
	glVertex3f( 5.0f, -5.5f, 5.0f);
	glEnd();
}

void desenhaPiramide() {
    glPushMatrix();  // Salve a matriz de transformação atual

    // Defina a altura e a largura da pirâmide
    float altura = 10.0;
    float largura = 11.5;  // Largura do teto do cubo

    glBegin(GL_TRIANGLES);
    // Base da pirâmide (teto do cubo)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-largura / 2, 5.0f, -largura / 2);
    glVertex3f(largura / 2, 5.0f, -largura / 2);
    glVertex3f(0.0f, 5.0f, largura / 2);


    // Faces laterais da pirâmide
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, altura + 5.0f, 0.0f);
    glVertex3f(-largura / 2, 5.0f, -largura / 2);
    glVertex3f(largura / 2, 5.0f, -largura / 2);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, altura + 5.0f, 0.0f);
    glVertex3f(largura / 2, 5.0f, -largura / 2);
    glVertex3f(0.0f, 5.0f, largura / 2);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, altura + 5.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, largura / 2);
    glVertex3f(-largura / 2, 5.0f, -largura / 2);

    glEnd();

    glPopMatrix();  // Restaure a matriz de transformação anterior
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (posX == 360)
        posX = 0;

    if (posY == 360)
        posY = 0;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Ajuste a posição da câmera para uma visão mais distante
    glTranslatef(0.0, 0.0, -50.0);  // Ajuste a posição Z

    // Movimentos de rotação e translação
    glTranslatef(transX, transY, transZ);
    glRotatef(posX, 1.0, 0.0, 0.0);
    glRotatef(posY, 0.0, 1.0, 0.0);

    desenhaCubo();
    desenhaPiramide();

    glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y){
    switch (key){
        case 'A':
        case 'a':
          posY += 1;
        break;
        case 'D':
        case 'd':
          posY -= 1;
        break;
        case 'W':
        case 'w':
          posX += 1;
        break;
        case 'S':
        case 's':
          posX -= 1;
        break;
        case 27:
          exit(0);
        break;
        default:
         break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    win_id = glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}