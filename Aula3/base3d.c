#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int win_id;
float posX=0.0,posY=0.0,posZ=0.0;
float transX=0.0,transY=0.0,transZ=0.0;

void casa()
{
	glTranslatef(0.0f, 0.0f, 0.0f);

        //desenha a casa.
        glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);  // Cor amarela
            glScalef(1.0, 2.0, 2.0);
            glutSolidCube(2);
            glutSolidCone(1.0,1.0,1.5,1.4);
        glPopMatrix();

        //porta
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(-1.01,-2.0,0.9);
          glVertex3f(-1.01, -2.0,-0.0); 
          glVertex3f(-1.01 , 0.4,-0.0);
          glVertex3f(-1.01, 0.4,0.9);
        glEnd();

        //janela
        glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f); // branco
          glVertex3f(-1.01,-0.2,-0.6);
          glVertex3f(-1.01, -0.2,-1.5); 
          glVertex3f(-1.01 , 0.5,-1.5);
          glVertex3f(-1.01, 0.5,-0.6);
        glEnd();

        // triangulo do teto
        glBegin(GL_POLYGON); 
      	  glColor3f(0.3, 0.2, 0.1);  // Cor marrom escuro
          glVertex3f( 0.0f, 3.0f,2.01); 
          glVertex3f( 1.0f, 2.0f,2.01);
          glVertex3f( -1.0f, 2.0f,2.01);
        glEnd(); 
        
        // triangulo do teto
        glBegin(GL_POLYGON);
          glColor3f(0.3, 0.2, 0.1);  // Cor marrom escuro
          glVertex3f( 0.0f, 3.0f,-2.01);
          glVertex3f( 1.0f, 2.0f,-2.01);
          glVertex3f( -1.0f, 2.0f,-2.01);
        glEnd();

        //Telhado
        glBegin(GL_QUADS);
        glColor3f(0.3, 0.2, 0.1);  // Cor marrom escuro
          glVertex3f(-0.0f,3.0f, 2.01f);
          glVertex3f( 1.0f, 2.0f, 2.01f);       
          glVertex3f( 1.0f, 2.0f, -2.01f);       
          glVertex3f(-0.0f,3.0f, -2.01f);       
        glEnd();

        //Telhado
        glBegin(GL_QUADS);
          glColor3f(0.3, 0.2, 0.1);  // Cor marrom escuro
          glVertex3f( 0.0f,2.0f, 2.01f);
          glVertex3f( -1.0f, 2.0f, 2.01f);       
          glVertex3f( -1.0f, 2.0f, -2.01f);       
          glVertex3f( 0.0f,3.0f, -2.01f);       
        glEnd();
}

//Aqui se capturam as teclas comuns (letras, números e ESC, por exemplo)
void myKeyboard(unsigned char key,int x,int y){
    switch (key){
        case 'a':
          posY += 1;
        break;
        case 'd':
          posY -= 1;
        break;
        case 'w':
          posX += 1;
        break;
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

//Aqui se capturam as teclas especiais (Alt, Control, Shift, F1, F2, etc.)
void myKeyboardSpecial(int key, int x, int y ) {
  switch ( key ) {
    case GLUT_KEY_UP:                   // Quando a seta para cima é teclada...
      glutFullScreen ( );               // Vá para o modo tela cheia...
      break;
    case GLUT_KEY_DOWN:                 // Quando a seta para baixo for teclada...
      glutReshapeWindow ( 640, 480 );   // Vá para modo em janela de 640 por 480
      break;
    default:
      printf("Você apertou a tecla especial código: %d\n", key);  // ...para ajudar você a debugar...       
      break;
  }
}

// Função callback chamada para gerenciar eventos do mouse
void myMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {
      float r, g, b;
      r = (double)rand() / (double)RAND_MAX;
      g = (double)rand() / (double)RAND_MAX;
      b = (double)rand() / (double)RAND_MAX;
      glColor3f(r,g,b);
      printf("%.2f, %.2f, %.2f\n", r, g, b);
    }
  glutPostRedisplay();
}

void init(void) 
{
  // Define a cor de fundo da janela de visualização como preto
  glClearColor (0.0, 0.0, 0.0, 0.0);

  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);

  //Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

  // Passa os parâmetros definidos acima para a OpenGL
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  // Habilita a luz ambiente, a luz zero e o depth buffer
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  //Primeira cor, para depois mudarmos com os eventos
  glColor3f(0.5, 1.0, 0.5);
}

void display(void)
{
    // Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.7f, 0.7f, 1.0f, 1.0f);
    // Entra no modo de definição de matriz de visualização
    glMatrixMode(GL_MODELVIEW);
    // Carrega a matriz identidade
    glLoadIdentity();
    // Define a posição da câmera e para onde ela aponta
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Ajuste a posição da câmera aqui

    glRotatef(posX, 1.0, 0.0, 0.0);
    glRotatef(posY, 0.0, 1.0, 0.0);
    glTranslatef(transX, transY, transZ);

    casa();

    // Executa os comandos OpenGL, e depois troca os buffers de vídeo
    glFlush();
}

void reshape(int w, int h)
{
    // Define o viewport como o tamanho da janela
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    // Entra no modo de definição de matriz de projeção
    glMatrixMode(GL_PROJECTION);
    // Carrega a matriz identidade
    glLoadIdentity();
    // Ajusta a projeção ortogonal
    glOrtho(-10.0, 10.0, -10.0, 10.0, -100.0, 100.0); // Ajuste a escala da projeção ortogonal aqui

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
  // Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas
  glutInit(&argc, argv);
  // Inicializa o display, indicando que usará:
  // - um buffer de imagem (single buffer);
  // - buffer de profundidade;
  // - padrão de cores RGB)
  glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  // Especifica as dimensões da janela de exibição
  glutInitWindowSize (500, 500); 
  // Especifica a posição inicial da janela de exibição
  glutInitWindowPosition (100, 100);
  // Cria a janela de exibição
  win_id = glutCreateWindow (argv[0]);
  // Chama a função init
  init ();
  // Estabelece a função "display" como a função callback de exibição.
  glutDisplayFunc(display); 
  // Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
  glutReshapeFunc(reshape);
  // Estabelece a função "keyboard" como a função callback de evento de teclado.
  glutKeyboardFunc(myKeyboard);
  // Estabelece a função "keyboardSpecial" como a função callback de evento de teclado especial.
  glutSpecialFunc(myKeyboardSpecial);
  // Estabelece a função "mouse" como a função callback de evento de mouse.
  glutMouseFunc(myMouse);
  // Entra no loop de eventos, não retorna
  glutMainLoop();
  return 0;
}