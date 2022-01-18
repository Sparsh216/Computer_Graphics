// C++ Implementation for drawing line
#include <graphics.h>
// driver code
int main()
{
    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;
  
    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, "");
  
    // line for x1, y1, x2, y2
    setcolor(6);
    line(150, 150, 150, 300);
    line(150,150,250,150);
    line(150,200,250,200);
	
	line(350,150,270,290);
	line(350,150,420,290);
	line(320,200,376,200);
	
	line(470,150,470,300);
	line(470,150,570,300);
	line(570,300,570,150);
    line(150,400,550,400);
    getch();
  
    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();
}
