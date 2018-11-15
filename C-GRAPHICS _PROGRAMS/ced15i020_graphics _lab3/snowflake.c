//snowflake algorithm

 #include<graphics.h>
 #include<math.h>
 #include<stdio.h>
void wait_for_char() {
	int in=0;
	while (in ==0)
		in = getchar();
} 

//considering line 1
void koch(int x1, int y1, int x2, int y2, int it)
{
 float angle = 60*M_PI/180;//one degree= pie/180 radians 
 //division of a given line in to 3 parts with points(x3,y3)=(200,200)and (x4,y4)=(300,300)as (x1,y1)=(100,100)and(x2,y2)=(400,400)
 int x3 = (2*x1+x2)/3;
 int y3 = (2*y1+y2)/3;
 int x4 = (x1+2*x2)/3;
 int y4 = (y1+2*y2)/3;
 int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);//->this when y axis is also increasing 
 int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

if(it==0)
 {
 line(x1,y1,x2,y2);

 }

 else if(it > 0)
 {
  koch(x1, y1, x3, y3, it-1);
  koch(x3, y3, x, y, it-1);
  koch(x, y, x4, y4, it-1);
  koch(x4, y4, x2, y2, it-1);
  
 }
 else
 {

  line(x1, y1, x3, y3);
  line(x3, y3, x, y);
  line(x, y, x4, y4);
  line(x4, y4, x2, y2);
  
  
  
 }

}
//considering line 2 in the equilateral triangle
void koch1(int a1, int b1, int a2, int b2, int it)
{
 float angle = 60*M_PI/180;//one degree= pie/180 radians 
 int a3 = (2*a1+a2)/3;
 int b3 = (2*b1+b2)/3;

int a4 = (a1+2*a2)/3;
 int b4 = (b1+2*b2)/3;
 
 int a = a3 + (a4-a3)*cos(angle)+(b4-b3)*sin(angle);//->this when y axis is also increasing 
 int b = b3 - (a4-a3)*sin(angle)+(b4-b3)*cos(angle);
 if(it==0)
 {
  line(a1,b1,a2,b2);
 }
  else if(it > 0)
  {
  koch1(a1, b1, a3, b3, it-1);
  koch1(a3, b3, a, b, it-1);
  koch1(a, b, a4, b4, it-1);
  koch1(a4, b4, a2, b2, it-1);
  }
  else
  {
   line(a1, b1, a3, b3);
  line(a3, b3, a, b);
  line(a, b, a4, b4);
  line(a4, b4, a2, b2);
  }
}
//considering line 3 in the equilateral triangle
void koch2(int c1, int d1, int c2, int d2, int it)
{
 float angle = 60*M_PI/180;//one degree= pie/180 radians 
 int c3 = (2*c1+c2)/3;
 int d3 = (2*d1+d2)/3;

int c4 = (c1+2*c2)/3;
 int d4 = (d1+2*d2)/3;
 
 int c = c3 + (c4-c3)*cos(angle)+(d4-d3)*sin(angle);//->this when y axis is also increasing 
 int d = d3 - (c4-c3)*sin(angle)+(d4-d3)*cos(angle);
 if(it==0)
 {
  line(c1,d1,c2,d2);
 }
  else if(it > 0)
  {
  koch1(c1, d1, c3, d3, it-1);
  koch1(c3, d3, c, d, it-1);
  koch1(c, d, c4, d4, it-1);
  koch1(c4, d4, c2, d2, it-1);
  }
  else
  {
   line(c1, d1, c3, d3);
  line(c3, d3, c, d);
  line(c, d, c4, d4);
  line(c4, d4, c2, d2);
  }
}

int main(void)
{
 int gd = DETECT, gm;
 int n=2000;
 int iteration;
 printf("for how many iterations u want to display c curve\n");
 scanf("%d",&iteration);
 initgraph(&gd, &gm, NULL);
 cleardevice();
  setbkcolor(CYAN);
  //equlateral triangle with (100,100),(400,100)and (250,360) 
 int x1 = 100, y1 = 100, x2 = 400, y2 = 100;
 int c1 = 250,d1 =360,c2=100,d2=100;
 int a2 = 250,b2 =360,a1=400,b1=100;
   setcolor(RED);
   koch(x1, y1, x2, y2,iteration);
   setcolor(GREEN);
   koch1(a1, b1, a2, b2,iteration);
   setcolor(BLUE);
   koch2(c1,d1,c2,d2,iteration);
   wait_for_char();
   closegraph();
   return 0;

}
