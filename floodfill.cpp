#include<stdio.h> 
#include<conio.h> 
#include<graphics.h> 
void flood(int,int,int,int); 
int main() 
{ 
int gd,gm; 
detectgraph(&gd,&gm); 
initgraph(&gd,&gm,""); 
line(50,50,50,90); 
setcolor(RED); 
line(50,50,90,50); 
setcolor(GREEN); 
line(90,50,90,90); 
setcolor(BLUE); 
line(50,90,90,90); 
setcolor(WHITE); 
flood(55,55,5,0); 
getch(); 
closegraph(); 
return 0;
} 

void flood(int x,int y,int fillcolor,int oldcolor) 

{ 

int current; 

current=getpixel(x,y); 

if(current==oldcolor) 

{ 

putpixel(x,y,fillcolor); 

delay(10); 

flood(x+1,y,fillcolor,oldcolor); 

flood(x-1,y,fillcolor,oldcolor); 

flood(x,y+1,fillcolor,oldcolor); 

flood(x,y-1,fillcolor,oldcolor); 

} 

} 
