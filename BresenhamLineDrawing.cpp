// C program for BRESENHAM'S LINE DRAWING ALGORITHM
// Declaring header files
#include<graphics.h>
#include<stdio.h>
int main()
{
int x,y,x1,y1,delx,dely,m,grtr_d,smlr_d,d;

	// gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file 
int gm,gd=DETECT;

    // initgraph initializes the graphics system
    // by loading a graphics driver from disk  
initgraph(&gd,&gm,(char*)"");

	//Next four lines are to take the input of the points
printf("******* BRESENHAM'S LINE DRAWING ALGORITHM *****\n\n");
printf("enter initial coordinate = ");
scanf("%d %d",&x,&y);
printf("enter final coordinate = ");
scanf("%d %d",&x1,&y1);

delx=x1-x;	//Calculating delta x
dely=y1-y;	//Calculating delta y
grtr_d=2*dely-2*delx;// when d > 0
smlr_d=2*dely; // when d< 0
d=(2*dely)-delx; //Calculate the decision parameter

do{
putpixel(x,y,6);	//put pixel at (X,Y) and give color to it

//Next few steps calculate the next points to be plotted
if(d<0) {
d=smlr_d+d;
}
else
{
d=grtr_d+d;
y=y+1;
}
x=x+1;
}while(x<x1);	// this condition checks if whole line is generated
getch();

 	// closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
closegraph();
return 0;
}
