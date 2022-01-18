#include<graphics.h>


void Flood(int x,int y,int oldcolor,int newcolor)          //flood fill algorithm
{
	if(getpixel(x,y) == oldcolor)
	{
	putpixel(x,y,newcolor);
	Flood(x+1,y,oldcolor,newcolor);
	Flood(x,y+1,oldcolor,newcolor);
	Flood(x-1,y,oldcolor,newcolor);
	Flood(x,y-1,oldcolor,newcolor);
	}
}

int main()
{

int gd = DETECT, gm;                                    //initializes the graphic driver variable gd and graphic mode
int dx;
int sx,sy;
initgraph(&gd, &gm,NULL);

for(dx=0;dx<=300;dx=dx+50)
{
//Plane
setcolor(WHITE);
line(0,300,640,300);

//Ball
setcolor(YELLOW);
circle(200+dx,270,30);                        //to draw ball
Flood(210+dx,280,BLACK,YELLOW);                //to fill color in the ball

delay(1000);                            
cleardevice();
}

setcolor(WHITE);                              //helps to set color
line(0,300,640,300);

setcolor(YELLOW);  
circle(200+dx,270,30);
Flood(210+dx,280,BLACK,YELLOW);

getch();                                      //to hold the screen
closegraph();                                 //close graphic driver

}
