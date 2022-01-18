// C++ Implementation for drawing line
#include<graphics.h>
// driver code
main(){
	// gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // 0 to automatically detect the drive
	int gd =0 , gm;
	
	// initgraph initializes the graphics system
    // by loading a graphics driver from disk
    // and converting text mode to graphic mode
	initgraph(&gd,&gm,(char*)"");
	
	// x1, y1, radius
	circle(100,80,20);
	
	getch();
	
	// closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
	closegraph();
}
