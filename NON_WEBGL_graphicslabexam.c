
//##CED15I020_NON_WEBGL_LAB_QUESTION//C PROGRAM
//QUESTION:DRAW ELLIPSE INSIDE A CIRCLE TOUCHING EACH OTHER AT TWO DIFFERENT POINTS 
//COMPILING :cc NON_WEBGL_graphicslabexam.c -lgraph
//./a.out

#include<stdio.h>
#include<graphics.h>
#include<math.h>
void wait_for_char() {
	int in=0;
	while (in ==0)
		in = getchar();
} 
void main(void)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
cleardevice();
 circle(100,110,100);
 //ellipse(20,30,0,180,50,60);
 ellipse(100,110,0,360,70,100);
 wait_for_char();
closegraph();
return;
}
