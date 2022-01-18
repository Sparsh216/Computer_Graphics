/* translation */
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>  
int main()
{
int gd=DETECT,gm;
int x,y,x1,y1,x2,y2,tx,ty,ch,x3,y3,d,xn1,xn2,yn1,yn2,ra,si,co;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("Press 1 for translation 2 for rotation: ");
scanf("%d",&ch);
switch(ch){
	case 1:{
		printf("\n Please enter first coordinate of the triangle= ");
		scanf("%d %d", &x,&y);
		printf("\n Enter second coordinate of the trinagle = ");
		scanf("%d %d",&x1,&y1);
		printf("\n Enter third coordinate of the triangle = ");
		scanf("%d %d",&x2,&y2);
		printf("\n\t\t********** TRIANGLE before & after translation ***********");
		line(x,y,x1,y1);
		line(x1,y1,x2,y2);
		line(x2,y2,x,y);
		printf("\n Now enter the translation vector = ");
		scanf("%d %d",&tx,&ty);
		setcolor(RED);
		line(x+tx,y+ty,x1+tx,y1+ty);
		line(x1+tx,y1+ty,x2+tx,y2+ty);
		line(x2+tx,y2+ty,x+tx,y+ty);
		getch();
		closegraph();
		break;
	}
	case 2:{
		printf("Enter the value of X1 and Y1: ");
	  scanf("%d %d", &x1, &y1);
	
	  printf("Enter the value of X2 and Y2: ");
	
	  scanf("%d %d", &x2, &y2);
	
	  line(x1, y1, x2, y2);
	
	  printf("Enter the degree of rotation: ");
	
	  scanf("%d", &d);
	
	
	  xn1 = x1;
	
	  yn1 = y1;
	
	
	  ra = 0.0175 * d;
	
	  si = sin(ra);
	
	  co = cos(ra);
	
	  //second point
	
	  xn2 = floor(x2 * co + y2 * si);  
	
	  yn2 = floor(-x2 * si + y2 * co);  

	line(xn1, yn1, xn2, yn2);

	getch();

	closegraph();
	
		break;
	}
}

return 0;
}
