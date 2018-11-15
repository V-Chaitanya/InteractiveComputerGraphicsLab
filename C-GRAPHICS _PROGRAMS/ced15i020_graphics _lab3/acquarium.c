
//aquarium program in c graphics 
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void wait_for_char() {
	int in=0;
	while (in ==0)
		in = getchar();
} 

void oxygen_bubbles(int i,int y)
{
if(y<100)
   { 
   //second bubble
   y=y+200;
   if(y>200)
   {
   circle(100,y+110-i,5);//110-i because bubble should go up and y axis decreases on going up
   }
   }
else {
//first bubble
     circle(100,y+110-i,5);
     }
     }
void main(void)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
cleardevice();
int i,y=200;
//setbkcolor(MAGENTA);
for(i=0;i<300;i++)
{
//fish1
line(150+i,250,190+i,290);
line(150+i,250,90+i,310);
line(90+i,270,150+i,330);
line(190+i,290,150+i,330);
line(90+i,310,90+i,270);
circle(170+i,290,3);
//fish2
arc(400-i,150,50,320,30);
line(420-i,128,450-i,160);
line(420-i,173,450-i,130);
line(450-i,160,450-i,130);
arc(380-i,150,270,90,20);
//oxygentank
line(50,300,80,300);
line(80,300,80,370);
line(50,370,80,370);
line(80,305,90,305);
line(80,310,90,310);
line(90,305,90,310);
//oxygen_bubbles(i,y);
oxygen_bubbles(i,y);
y--;
//roof
//setfillstyle(SOLID_FILL,BLUE);
line(50,10,550,10);
line(50,10,10,100);
line(550,10,590,100);
line(10,100,590,100);
floodfill(51,10,RED);
//bordrer of the tank
line(50,100,50,400);
line(550,100,550,400);
line(50,400,550,400);
//stones

ellipse(100,390,0,360,20,10);
floodfill(100,390,6);
ellipse(125,370,0,360,25,10);
floodfill(125,370,CYAN);
ellipse(150,390,0,360,25,10);
floodfill(150,390,CYAN);
ellipse(170,375,0,360,15,5);
floodfill(170,375,CYAN);
circle(180,390,10);
floodfill(180,390,CYAN);
ellipse(200,380,0,360,10,15);
floodfill(200,380,CYAN);
//setfillstyle(HATCH_FILL,RED);
circle(220,390,10);
floodfill(220,390,CYAN);
ellipse(250,380,0,360,20,15);
floodfill(250,380,WHITE);

ellipse(290,390,0,360,20,10);
ellipse(315,370,0,360,25,10);
floodfill(315,370,CYAN);
ellipse(340,390,0,360,25,10);
ellipse(360,375,0,360,15,5);
circle(370,390,10);
floodfill(370,390,CYAN);
ellipse(390,380,0,360,10,15);
circle(410,390,10);
ellipse(440,380,0,360,20,15);


ellipse(480,390,0,360,20,10);
ellipse(505,370,0,360,25,10);
ellipse(530,390,0,360,21,10);

delay(50);
cleardevice();

}
wait_for_char();
closegraph();
return;
}
