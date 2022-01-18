#include<graphics.h>
void Flood(int x,int y,int oldcolor,int newcolor)                     //flood fill algorithm
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
int gd = DETECT, gm;
int dx,dy;
int sx,sy;
initgraph(&gd, &gm,NULL);                                             //initializes the graphics system by loading graphics driver from disk

for(dx=0;dx<=300;dx=dx+50)
{
//Plane
setcolor(WHITE);                                                    //to set current drawing color
line(0,300,640,300);                                                //function to draw a line

//Ball
setcolor(YELLOW);                                                   //to set current color
circle(200+dx,285,20);                                               //function to draw circle(ball)
Flood(100+dx,295,BLACK,YELLOW);



delay(1000);                                                        //function pauses the computation for sometime
cleardevice();                                                      //clears the screen
}


//Plane
setcolor(WHITE);
line(0,300,640,300);


//Ball
setcolor(YELLOW);  
circle(200+dx,285,20);
Flood(100+dx,295,BLACK,YELLOW);


getch();                                                             //hold output screen for sometime
closegraph();                                                      //closes graphics mode(deallocates memory)
}
