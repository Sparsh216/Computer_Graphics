// opengl program for DDA line generation
// Declaring header files
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
float x1,x2,y1,y2;
// dda function for line generation
void display(void)
{
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1; //calculating dx
dy=y2-y1; //calculating dy

//calculating steps required for pixels generating
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

//calculating increment in x & y for each step
Xin = dx/step;
Yin = dy/step;

x= x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

//put pixels for each step
for (k=1 ;k<=step;k++)
{
x= x + Xin; //increment in x at each step
y= y + Yin; //increment in y at each step

//The glBegin and glEnd subroutines delimit the vertices that define a primitive or group of like primitives.
glBegin(GL_POINTS);
glVertex2i(x,y); //to specify point, line, and polygon vertices
glEnd();
}

glFlush(); //empties all commands in these buffers and
        //forces all pending commands will to be executed immediately without waiting buffers are full
}

void init(void)
{
glClearColor(0.7,0.7,0.7,0.7); //to clear the color buffers
glMatrixMode(GL_PROJECTION); //it specifies which matrix is the current matrix
glLoadIdentity(); // replaces the current matrix with identity matrix
gluOrtho2D(-100,100,-100,100);//sets up a two-dimensional orthographic viewing region
}

int main(int argc, char** argv) { //to take input
x1=30,y1=40,x2=200,y2=150;

glutInit(&argc, argv);// initgraph initializes the graphics system
    // by loading a graphics driver from disk
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //sets the initial display mode.

//glutInitWindowPosition and glutInitWindowSize set the initial window position and size respectively
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);

glutCreateWindow ("DDA Line Algo"); //creates a top-level window
init();
glutDisplayFunc(display); //sets the callback function, provided by your program
glutMainLoop(); //glutMainLoop is the main function that keeps calling and calling the displaying functions

return 0;
}
