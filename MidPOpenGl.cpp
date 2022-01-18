// opengl program for mid point circle
// Declaring header files
#include <gl/glut.h>
#include <Windows.h>
#include <iostream>
using namespace std;


void circle() {
 glColor3f(1.0, 0.0, 0.0);//to specify point, line, and polygon vertices
 glPointSize(2.0);//specifies the rasterized diameter of both aliased and antialiased points
 float r = 100;
 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POINTS);//The glBegin and glEnd subroutines delimit the vertices that define a primitive or group of like primitives.
 while (x != y)
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
  glVertex2i(x, y);//to specify point, line, and polygon vertices
  glVertex2i(-x, y);
  glVertex2i(x, -y);
  glVertex2i(-x, -y);

  glVertex2i(y, x);
  glVertex2i(-y, x);
  glVertex2i(y, -x);
  glVertex2i(-y, -x);

 }
 glEnd();//The glBegin and glEnd subroutines delimit the vertices that define a primitive or group of like primitives
 glFlush();//empties all commands in these buffers and
        //forces all pending commands will to be executed immediately without waiting buffers are full
}
int main(int argc, char ** argv) {
 glutInit(&argc, argv);// initgraph initializes the graphics system
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//sets the initial display mode.
 glutInitWindowSize(500, 500);//glutInitWindowPosition and glutInitWindowSize set the initial window position and size respectively
 glutInitWindowPosition(100, 100);//define the size and position (upper left corner) of the window on the screen
 glutCreateWindow("Line Draw OpenGL");//creates a top-level window

 glClearColor(1.0, 1.0, 1.0, 1.0);//to clear the color buffers
 glClear(GL_COLOR_BUFFER_BIT);//sets the bitplane area of the window to values previously selected by glClearColor
 gluOrtho2D(-250, 250, -250, 250);//sets up a two-dimensional orthographic viewing region
 glMatrixMode(GL_PROJECTION);//it specifies which matrix is the current matrix
 glViewport(0, 0, 500, 500);//the affine transformation of x and y from normalized device coordinates to window coordinates

 glutDisplayFunc(circle);//sets the callback function, provided by your program
 glutMainLoop();//glutMainLoop is the main function that keeps calling and calling the displaying functions

 return 0;
}
