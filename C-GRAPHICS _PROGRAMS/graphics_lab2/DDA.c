#include <graphics.h>
#include <stdio.h>
#include <math.h>

void wait_for_char() {
	int in=0;
	while (in ==0)
		in = getchar();
} 
void main( )
{
    float x,y,x1,y1,x2,y2,m;
    int i,gd=DETECT,gm;
 
    initgraph(&gd,&gm,NULL);
 
    printf("Enter the value of x1 and y1 : ");
    scanf("%f %f",&x1,&y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%f %f",&x2,&y2);
 
    m=(y2-y1)/(x2-x1);
 
   
    x=x1;
    y=y1;
 
  
    while(y<=y2)
    {
        putpixel(round(x),round(y),250);
        x=x+1;
        y=y+m;
     
        //delay(10);
    }
 	wait_for_char();
    closegraph();
}
