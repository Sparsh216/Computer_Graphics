// C program for DDA line generation
// Declaring header files
#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
 main( )        //This function calculates DDA
{
float x,y,x1,y1,x2,y2,dx,dy,step;   

	// gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file  
int i,gd=DETECT,gm;

    // initgraph initializes the graphics system
    // by loading a graphics driver from disk  
initgraph(&gd,&gm,(char*)"");

//Next four lines are to take the input of the points
printf("Enter the value of x1 and y1 : ");
scanf("%f%f",&x1,&y1);
printf("Enter the value of x2 and y2: ");
scanf("%f%f",&x2,&y2);
 
dx=abs(x2-x1);   //Calculating delta x
dy=abs(y2-y1);	 //Calculating delta y

// calculate steps required for generating pixels 
if(dx>=dy)
step=dx;
else
step=dy;
// calculate increment in x & y for each steps 
dx=dx/step;
dy=dy/step;
// Put pixel for each step 
x=x1;
y=y1; 
i=1;
while(i<=step)
{
putpixel(x,y,2);     // put pixel at (X,Y)	and give color to it
x=x+dx;              // increment in x at each step
y=y+dy;              // increment in y at each step
i=i+1;               
delay(100);          // for visualization of line-generation step by step
}
getch(); 
 	// closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
closegraph();
}

