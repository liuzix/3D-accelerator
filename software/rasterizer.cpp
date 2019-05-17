#include "MacLinux.h"
#define LIGHT_GREEN   153./255,255/255,153/255

// draws a colored line from p1 to p2
void drawLine(int x1, int y1, int z1
            , int x2, int y2, int z2
            , float r, float g, float b) {
  glColor3f(r,g,b);
  glBegin(GL_LINES);
     glVertex3i(x1,y1,z1);
     glVertex3i(x2,y2,z2);
  glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawLine(100,100,0, 400,400,0, 255,231,50);
}


void init() {
    glClearColor(LIGHT_GREEN, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA);
    glutInitWindowSize(600,600); 
    glutInitWindowPosition(100,100);
	glutCreateWindow("Rasterizer");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
