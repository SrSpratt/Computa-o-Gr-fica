#include <windows.h>
#include <stdio.h>
#include <gl/glut.h>
#include <conio.h>


int checkpoint(void);
double colorsx[9] = {1 , 0, 0 ,0 ,0 ,0 ,1 ,1 ,1};

int x=40,y=240;
//int x=165, y = 90;
//int x = 245, y = 35;
void Personagem(){
  //glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(colorsx[0],colorsx[1],colorsx[2]); 
  glBegin(GL_QUADS);
   glVertex2i(x-3,3+y);
   glVertex2i(3+x,3+y);
   glVertex2i(3+x,y-3);
   glVertex2i(x-3,y-3);
  glEnd();
  //colisao():
  glFlush();
  glutPostRedisplay();
  glutSwapBuffers();
}


// Função callback chamada para fazer o desenho
void Desenha(void){
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
                   
  // Limpa a janela de visualização com a cor de fundo especificada
  glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(colorsx[3], colorsx[4], colorsx[5]);
  
  // início do desenho do meio
  glLineWidth (2);
/*  glBegin(GL_LINE_STRIP);
   glVertex2i(115,153);
   glVertex2i(115,93);
   glVertex2i(161,93);
  glEnd();
  
  glBegin(GL_LINE_STRIP);
   glVertex2i(171,93);
   glVertex2i(171,153);
   glVertex2i(125,153);
  glEnd();*/
  
 glColor3f(colorsx[0], colorsx[3], colorsx[4]); 
  glBegin(GL_LINE_LOOP);	   
   glVertex2i(136.5,140);
   glVertex2i(136.5,130);
   glColor3f(colorsx[3], colorsx[5], colorsx[0]);
   glVertex2i(150.5,130);
   glVertex2i(150.5,140);              
  glEnd();
     
  glBegin(GL_LINES);
   glVertex2i(143.5,130);
   glColor3f(colorsx[0], colorsx[3], colorsx[4]);
   glVertex2i(143.5,110);
  glEnd();
     
  glBegin(GL_LINE_STRIP);
   glVertex2i(130.5,120);
   glVertex2i(130.5,125);
   glColor3f(colorsx[3], colorsx[5], colorsx[0]);
   glVertex2i(156.5,125);
   glVertex2i(156.5,130);              
  glEnd();
     
  glBegin(GL_LINE_STRIP);
   glVertex2i(132.5, 105);
   glVertex2i(132.5,110);
   glColor3f(colorsx[0], colorsx[3], colorsx[4]);
   glVertex2i(154.5,110);
   glVertex2i(154.5, 105);              
  glEnd();    
// fim do boneco do meio
	glColor3f(colorsx[3], colorsx[4], colorsx[5]);
	int i = 35, j = 243,n=1,m=1,o=1;
	glBegin(GL_LINE_STRIP);
	glVertex2i(i, j);
	while((i != 161)  && (j != 133)){
		
		if(!(n%2 == 0)){
			if (!(m%2==0)){
				j -= 250-(m*20);
				m++;
			}else {
				j += 250-(m*20);
				m++;
			}			
		} else {
			if (!(o%2==0)){
				i += 226-(o*20);
				o++;
			} else {
				i -= 226-(o*20);
				o++;
			}	
		}
		
		glVertex2i(i, j);
		n++;
	}
	glEnd();
	
	i = 125, j = 153, n=1, m=1, o=1;
	glBegin(GL_LINE_STRIP);
	glVertex2i(i, j);
	while((i != 1)  && (j != 3)){
		
		if((n%2 == 0)){
			if (!(m%2==0)){
				j -= 50+(m*20);
				m++;
			}else {
				j += 50+(m*20);
				m++;
			}			
		} else {
			if (!(o%2==0)){
				i += 26+(o*20);
				o++;
			} else {
				i -= 26+(o*20);
				o++;
			}	
		}
		
		glVertex2i(i, j);
		n++;
	}
	glEnd();  

/*// espiral superior
 glBegin(GL_LINE_STRIP);
  glVertex2i(115,153);
  glVertex2i(115,163);
  glVertex2i(115,163);
  glVertex2i(181,163);
  glVertex2i(181,73);
  glVertex2i(95,73);
  glVertex2i(95,183);
  glVertex2i(201,183);
  glVertex2i(201,53);
  glVertex2i(75,53);
  glVertex2i(75,203);
  glVertex2i(221,203);
  glVertex2i(221,33);
  glVertex2i(55,33);
  glVertex2i(55,223);
  glVertex2i(241,223);
  glVertex2i(241,13);
  glVertex2i(35,13);
  glVertex2i(35,243);
 glEnd();
 
 //espiral inferior
  glBegin(GL_LINE_STRIP);
  glVertex2i(171,93);
  glVertex2i(171,83);
  glVertex2i(105,83);
  glVertex2i(105,173);
  glVertex2i(191,173);
  glVertex2i(191,63);
  glVertex2i(85,63);
  glVertex2i(85,193);
  glVertex2i(211,193);
  glVertex2i(211,43);
  glVertex2i(65,43);
  glVertex2i(65,213);
  glVertex2i(231,213);
  glVertex2i(231,23);
  glVertex2i(45,23);
  glVertex2i(45,233);
  glVertex2i(251,233);
  glVertex2i(251,3);
 glEnd();*/
 
 Personagem();
 glFlush(); 
}
// Inicializa parâmetros de rendering
void Inicializa (void)
{   
  // Define a cor de fundo da janela de visualização como branco
  glClearColor(colorsx[6], colorsx[7], colorsx[8], 0.5f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
  // Evita a divisao por zero
  if(h == 0)
   h = 1;
  
  // Especifica as dimensões da Viewport
  glViewport(0, 0, w, h);

  // Inicializa o sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Estabelece a janela de seleção (left, right, bottom, top)
  if (w <= h) {
   gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
  }
  else {
  gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
  }
}

void colisao(){
 int i = 35, j = 243,n=1,m=1,o=1, auxj, auxi;
 if ((x == i+3) && (j>y)){
  MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
  printf("colisao1\n");
		x = 40;
		y = 240;
 } else if ((j-7 == y) && (x >= i+7) && (x<= i+233)){
  MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
  printf("colisao1\n");
  x = 40;
  y = 240;
 } else if ((x+3 == 23)){
  MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
  printf("colisao1\n");
  x = 40;
  y = 240;
 } else if ((y+3 >= 244)){
  MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
  printf("colisao1\n");
  x = 40;
  y = 240;
 };
	while((i != 161)  && (j != 133)){
		if(!(n%2 == 0)){
			if (!(m%2==0)){
			 auxj = j;
				j -= 250-(m*20);
				if (m ==9){
				 if (((x == i+3) && (auxj-3 > y) && (j+3 < y)) || ((x == i+8) && (auxj-7 > y) && (j+57 < y))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao1\n");
				 x = 40;
				 y = 240;
    }
    } else{
    if (((x == i+3) && (auxj-3 > y) && (j+3 < y)) || ((x == i+7) && (auxj-7 > y) && (j+7 < y))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao1\n");
				 x = 40;
				 y = 240;
    } 
    }
				m++;
			}else {
			 auxj = j;
				j += 250-(m*20);
				if (((x == i-3) && (auxj+3 < y) && (j-3 > y)) || ((x == i-7) && (auxj+7 < y) && (j-7 > y))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao2\n");
				 x = 40;
				 y = 240;
    }
				m++;
			}			
		} else {
			if (!(o%2==0)){
			 auxi = i;
				i += 226-(o*20);
				if (o == 9){
				if ((y == j+3) && (auxi+3 < x) && (i>x)) {
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao3\n");
				 x = 165;
				 y = 90;
    }
    }else{
     if (((y == j+3) && (auxi+3 < x) && (i-3>x)) || ((y == j+7) && (auxi+7 < x) && (i-7>x))) {
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao3\n");
				 x = 40;
				 y = 240;
    }
   }
				o++;
			} else {
			 auxi = i;
				i -= 226-(o*20);
				if ((y == j-3) && (auxi-3 > x) && (i+3 < x) || ((y == j-7) && (auxi-7 > x) && (i+7 < x))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao4\n");
				 x = 40;
				 y = 240;
    }
				o++;
			}	
		}
		n++;
	}
	if ((y == 90) && (x ==165)){
	 MessageBox(NULL,"Checkpoint reached","Saved",MB_OK | MB_ICONINFORMATION);
 }

	// segunda espiral
	i = 125, j = 153, n=1, m=1, o=1;
		while((i != 1)  && (j != 3)){
		
		if((n%2 == 0)){
			if (!(m%2==0)){
			 auxj = j;
				j -= 50+(m*20);
				if (m == 1){
				if (((x == i-3) && (auxj-3 > y) && (j+3 < y)) || ((x == i-8) && (auxj-57 > y) && (j+7 < y))){
				 printf("colisao5\n");
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     x = 165;
				 y = 90;
    }
    }else{
				if (((x == i-3) && (auxj-3 > y) && (j+3 < y)) || ((x == i-7) && (auxj-7 > y) && (j+7 < y))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao5\n");
				 x = 165;
				 y = 90;
    }
    }
				m++;
			}else {
			 auxj = j;
				j += 50+(m*20);
				if (((x == i+3) && (auxj+3 < y) && (j-3 > y)) || ((x == i+7) && (auxj+7 < y) && (j-7 > y))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao6\n");
				 x = 165;
				 y = 90;
    }
				m++;
			}			
		} else {
			if (!(o%2==0)){
			 auxi = i;
				i += 26+(o*20);
				if (o == 1){ 
				if (((y == j-3) && (auxi < x) && (i-3>x))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao7\n");
				 x = 165;
				 y = 90;
    }
    } else {
    if (((y == j-3) && (auxi+3 < x) && (i-3>x)) || ((y == j-7) && (auxi+7 > x) && (i-7 < x))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao7\n");
				 x = 165;
				 y = 90;
    } 
    }
				o++;
			} else {
			 auxi = i;
				i -= 26+(o*20);
				if (((y == j+3) && (auxi-3 > x) && (i+3 < x)) || ((y == j+7) && (auxi-7 > x) && (i+7 < x))){
				 MessageBox(NULL,"Oops","OPA",MB_OK | MB_ICONINFORMATION);
     printf("colisao8\n");
				 x = 165;
				 y = 90;
    }
				o++;
			}	
		}
		n++;
	}
	if ((y<=13)){
	 checkpoint (); 
 }
}
// Função callback chamada para gerenciar eventos de teclas
void Teclado (int key, int a, int b){
 	switch (key){
	 case GLUT_KEY_UP:
	  y++;
	  //printf("\n%d", y);
	  colisao();
	  glutPostRedisplay();
	  break;
	 case GLUT_KEY_DOWN:
	  y--;
	  //printf("\n%d",x);
	  colisao();
	  glutPostRedisplay();
   break;
	  case GLUT_KEY_RIGHT:
	  x++;
	  //printf("\n%d",x);
	  colisao();
	  glutPostRedisplay();
	  break;
	  case GLUT_KEY_LEFT:
	  x--;
	  //printf("\n%d",x);
	  colisao();
	  glutPostRedisplay();
	  break;
 }
}

double r2(){
    return (double)rand() / (double)RAND_MAX ;
}

void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
         			for(int i = 0; i<9;i++){
         				colorsx[i] = r2();
					 }
					 Inicializa();
         		//colorG += 0.1;
         		//colorB += 0.1;
                  // Troca o tamanho do retângulo, que vai do centro da 
                  // janela até a posição onde o usuário clicou com o mouse
                  //xf = ( (2 * win * x) / view_w) - win;
                  //yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
         }
    glutPostRedisplay();
}

// Programa Principal 
int main(void)
{
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(400,350);
 glutInitWindowPosition(10,10);
 glutCreateWindow("THE MAZE!!!");
 glutDisplayFunc(Desenha);
 glutReshapeFunc(AlteraTamanhoJanela);
 glutSpecialFunc(Teclado);
 glutMouseFunc(GerenciaMouse);
 Inicializa();
 glutMainLoop();
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando caracteres bitmap
void DesenhaTexto(void *font, char *string) 
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,*string++); 
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na 
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}


// Função callback de redesenho da janela de visualização
void Desenhat(void)
{
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor para os textos: preto
	glColor3f(1,0,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();	
	glTranslatef(-70,0,0);
	glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(2); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"YOU WON");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado 
	glColor3f(0,0,1);
	//glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-45,-20); 
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"You've reached the end");
	// Exibe o desenha na janela
	glutSwapBuffers();
}
// Função callback chamada para gerenciar eventos de teclas
void Tecladot (unsigned char key, int x, int y) 
{
	if (key == 27) {
		exit(0);
}
}
// Inicializa projeção
void Inicializat(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
	
	// Define a cor de fundo de tela como branca
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Programa Principal
int checkpoint(void)
{
	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(300,250);

	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Endgame");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc (Desenhat);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Tecladot);

	// Inicialização
	Inicializat();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}

