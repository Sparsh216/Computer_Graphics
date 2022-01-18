#include<graphics.h>
#include<conio.h>
 
int main(){
 int gd = 0,gm;
    initgraph(&gd, &gm, (char*)"");
    /* Draw Hut */
    
    //setcolor := It changes the current drawing colour
    setcolor(WHITE);
    rectangle(150,180,250,300);
    rectangle(250,180,420,300);
    rectangle(180,250,220,300);
 
    line(200,100,150,180);
    line(200,100,250,180);
    line(200,100,370,100);
    line(370,100,420,180);
 
    /* Fill colours */
    
    //setfillstyle := It sets the current fill pattern and fill color.
    setfillstyle(SOLID_FILL, BROWN);
    //floodfill := It is used to fill a closed area with current fill pattern and fill color.
    floodfill(152, 182, WHITE);
    floodfill(252, 182, WHITE);
    setfillstyle(SLASH_FILL, BLUE);
    floodfill(182, 252, WHITE);
    setfillstyle(HATCH_FILL, GREEN);
    floodfill(200, 105, WHITE);
    floodfill(210, 105, WHITE);
     
    getch();
    closegraph();
    return 0;
} 
