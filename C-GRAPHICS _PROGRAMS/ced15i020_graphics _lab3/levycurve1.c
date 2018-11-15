#include<stdio.h>
#include<graphics.h>
#include<math.h>
void wait_for_char() {
	int in=0;
	while (in ==0)
		in = getchar();
}

void levyccurve(int x1, int y1, float l, float alpha, int it)

{
//int l=424;
	float angle = 45*M_PI/180;
	if(it>0)
	{
		// printf("\n Inside function, it=%d",it);
		l=l*0.7071067811;
		levyccurve(x1,y1,l,alpha+angle,it-1);
		x1=ceil(x1+l*cos(alpha+angle)*1.0);
		y1=ceil(y1+l*sin(alpha+angle)*1.0);
		levyccurve(x1,y1,l,alpha-angle,it-1);
	}
	else
	{
		int x2 = (int)(x1+l*cos(alpha)*1.0);
		int y2 = (int)( y1+l*sin(alpha) *1.0);
		// printf("alpha = %d\n", alpha);
		// printf("\n l* sin = %d \n",(int)(l*sin(alpha) *1.0));
		// printf("\n l* cos = %f \n",(int)(l*cos(alpha) *1.0));
		// printf("\n\ndrawing line x1=%d   y1= %d  x2 = %d y2=%d", x1,y1, x2,y2);
		line(x1,y1,x2,y2);
	}
}









int main(void)
{
	int gd = DETECT, gm;
	float alpha = 30*M_PI/180;
	int iteration;
	printf("for how many iterations u want to display koch curve\n");
	scanf("%d",&iteration);
	initgraph(&gd, &gm, NULL);
	cleardevice();
	int x1 = 200, y1 = 100;
	float l = 200.0;
	// int x2=x1+l*cos(alpha);
	// int y2=y1+l*sin(alpha);
	setcolor(RED);
	levyccurve(x1, y1, l,alpha,iteration);
	
	
	
	//levyccurve(x1, y1, l,alpha,2);
	wait_for_char();
	closegraph();
	return 0;
}
 
