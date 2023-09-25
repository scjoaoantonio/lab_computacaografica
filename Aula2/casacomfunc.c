#include <GL/glut.h>
#include <math.h>

/* X compile line: cc -o simple simple.c -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm */

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

float radio = 20, calx, caly;

   void ceu() {// Desenha o céu (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(windowWidth, 0.0f);
    glVertex2f(windowWidth, windowHeight);
    glVertex2f(0.0f, windowHeight);
    glEnd();
}


void grama(){    // Desenha o gramado (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(windowWidth, 0.0f);
    glVertex2f(windowWidth, windowHeight * 0.4f); // Ajuste a altura do gramado conforme desejado
    glVertex2f(0.0f, windowHeight * 0.4f); // Ajuste a altura do gramado conforme desejado
    glEnd();
}

// Função para desenhar o sol
void sol() {
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 30) {
        float angle = i * 3.14 / 180.0f;
        calx = radio * cos(i) + 400; 
        caly = radio * sin(i) + 230;
        glVertex2f(calx, caly);
    }
    glEnd();
}
//Desenha um quadrado de lado 1 centrado na origem
void desenhaQuadrado() {
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}

//Desenha um triângulo equilátero de lado 1 centrado na origem
void desenhaTriangulo() {
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

//Desenha um círculo de raio 1 centrado na origem
void desenhaCirculo() {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 30; i++) {
            glVertex2f(cos(i), sin(i));
        }
    glEnd();
}

//Faz o cisalhamento de um objeto em relação ao eixo X
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewX(GLfloat angle) {
    GLfloat m[16] = {
        1, 0, 0, 0,
        tan(angle), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0 ,1
    };
    glMultMatrixf(m);
}

//Faz o cisalhamento de um objeto em relação ao eixo Y
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewY(GLfloat angle) {
    GLfloat m[16] = {
        1, tan(angle), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(m);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Aqui entra todo o seu código da casa 2D.
    //Vocês só pode usar as funções de desenho:
        // desenhaQuadrado, desenhaTriangulo, desenhaCirculo
    // as transformações geométricas:
        // glTranslatef, glRotatef, glScalef, skewX, skewY
    // e as funções de cor:
        // glColor3f
    // Não desenhe nenhuma primitiva utilizando glBegin/glEnd diretamente aqui.

    ceu();
    grama();
    sol();


    glColor3f(0.142,0.35,0.107); //verde escuro
    glTranslatef(100,100,0);
    
    glPushMatrix();
    glScalef(100,100,1);
    desenhaQuadrado();
    glPopMatrix();


    glPushMatrix();
    skewX(2.79f);
    glColor3f(0.3,0.2,0.0); //marrom
    glTranslatef(135,100,0);
    glScalef(160,100,1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.16,0.5,0.2); //verde claro

    glTranslatef(125,0,0);
    glScalef(150,100,1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,100,0);
    glColor3f(0.255,0.165,0.0); //marrom
    glScalef(100,100,1);
    desenhaTriangulo();
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glTranslatef(0,-25,0);
    glPushMatrix();
    glScalef(30,50,1);
    desenhaQuadrado();
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glTranslatef(100,20,0);
    glPushMatrix();
    glScalef(30,30,1);
    desenhaQuadrado();
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glTranslatef(50,0,0);
    glPushMatrix();
    glScalef(30,30,1);
    desenhaQuadrado();
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glTranslatef(50,0,0);
    glPushMatrix();
    glScalef(30,30,1);

    glPopMatrix();
    
    


    // Executa os comandos OpenGL
    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)  {
        windowHeight = 250.0f*h/w;
                windowWidth = 250.0f;
    }
    else  {
        windowWidth = 250.0f*w/h;
        windowHeight = 250.0f;
    }

    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400,350);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Quartel");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
    return 0;
}