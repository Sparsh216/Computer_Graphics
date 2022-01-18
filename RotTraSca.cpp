#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>

// C code to implement basic
// transformations in OPENGL
#include <stdio.h>
#include <math.h>
#include <time.h>

// window size
#define maxWD 640
#define maxHT 480

// rotation speed
#define thetaSpeed 0.1
#define pi 3.14159

using namespace std;

void delay(unsigned int seconds)
{
	clock_t goal = seconds + clock();
	while (goal > clock())
		;
}


void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, maxWD, 0.0, maxHT);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void drawSquare(int x1, int y1, int x2, int y2)
{
	glPointSize(2.0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
        glVertex2i(x1, y1);
        glVertex2i(x1, y2);
        glVertex2i(x2, y2);
        glVertex2i(x2, y1);
	glEnd();
}

void drawPoint(int x, int y)
{
	glPointSize(6.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
    glPointSize(2.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void rotation(int px1, int py1, int px2, int py2, int cx, int cy)
{
	float theta = 0.0;
	glClear(GL_COLOR_BUFFER_BIT);
    drawPoint(cx, cy);
    drawSquare(px1, py1, px2, py2);
    glFlush();
    cout<<px1<<'\t'<<py1<<'\t'<<px2<<'\t'<<py2<<endl;
	delay(1000);
	int i = 100;
	while (i>0) {
		glClear(GL_COLOR_BUFFER_BIT);
		int xf1, yf1, xf2, yf2, xc1, xc2;
		theta = theta + thetaSpeed;
        if (theta >= (2.0 * pi))
			theta = theta - (2.0 * pi);
		xc1 = cx + (int)((float)((px2+px1)/2 - cx) * cos(theta)) - ((float)((py2+py1)/2 - cy) * sin(theta));
		xc2 = cy + (int)((float)((px2+px1)/2 - cx) * sin(theta)) + ((float)((py2+py1)/2 - cy) * cos(theta));

		xf1 = xc1 - 50.0;
		yf1 = xc2 - 50.0;
		xf2 = xc1 + 50.0;
		yf2 = xc2 + 50.0;

		drawPoint(cx, cy);
		drawSquare(xf1, yf1, xf2, yf2);
		drawLine(cx, cy, xc1, xc2);
		glFlush();
		i--;
		delay(100);
		cout<<xf1<<'\t'<<yf1<<'\t'<<xf2<<'\t'<<yf2<<endl;
	}
}

void translation(int px1, int py1, int px2, int py2, int tx, int ty)
{
	int fx1 = px1, fy1 = py1, fx2 = px2, fy2 = py2;
	int i = 15;
	while (i) {
		glClear(GL_COLOR_BUFFER_BIT);
		px1 = px1 + tx;
		py1 = py1 + ty;
		px2 = px2 + tx;
		py2 = py2 + ty;
		if (px1 > maxWD || px1 < 0 || py1 > maxHT || py1 < 0 || px2 > maxWD || px2 < 0 || py2 > maxHT || py2 < 0) {
			px1 = fx1;
			py1 = fy1;
			px2 = fx2;
			py2 = fy2;
		}
		drawSquare(px1, py1, px2, py2);
		glFlush();
		i--;
		delay(100);
	}
}

void scaling(int px1, int py1, int px2, int py2, int sx, int sy)
{
	int fx1, fy1, fx2, fy2;
	int i = 5;
	while (i>0) {
		glClear(GL_COLOR_BUFFER_BIT);
		fx1 = px1;
		fy1 = py1;
		fx2 = px2;
		fy2 = py2;
		drawSquare(fx1, fy1, fx2, fy2);
		glFlush();
		delay(500);
		glClear(GL_COLOR_BUFFER_BIT);
		fx1 = px1 * sx;
		fy1 = py1 * sy;
		fx2 = px2 * sx;
		fy2 = py2 * sy;
		drawSquare(px1, py1, px2, py2);
		drawSquare(fx1, fy1, fx2, fy2);
		drawLine(px1, py1, fx1, fy1);
		drawLine(px1, py2, fx1, fy2);
		drawLine(px2, py1, fx2, fy1);
		drawLine(px2, py2, fx2, fy2);
        glFlush();
		delay(1000);
		i--;
	}
}

void keyPressed(unsigned char ch, int x, int y) {
    if(ch == '1') {
        translation(100, 100, 200, 200, 1, 5);
    } else if(ch == '2') {
        rotation(100, 100, 200, 200, maxWD / 2, maxHT / 2);
    } else if(ch == '3') {
        scaling(50, 50, 100, 100, 2, 3);
    } else {
        return;
    }
}

void myDisplay()
{
	/*int opt = 4;
	int choice = 1;
	while(choice != 4) {
	switch (opt) {
	case 1:
		translation(100, 100, 200, 200, 1, 5);
		break;
	case 2:
		rotation(100, 100, 200, 200, maxWD / 2, maxHT / 2);
		break;
	case 3:
		scaling(10, 10, 20, 20, 2, 3);
		break;
    case 4:
        choice = 4;
        break;
	}
	printf("Switch window\n");
	}*/
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(maxWD, maxHT);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Transformations");
	myInit();
	glutKeyboardFunc(keyPressed);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
