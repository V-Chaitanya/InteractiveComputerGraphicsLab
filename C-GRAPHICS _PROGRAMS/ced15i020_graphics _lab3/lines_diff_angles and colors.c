//generating lines with different colors and different angles

#include<stdio.h>
#include<graphics.h>
void wait_for_char() {
	int in=0;
	while (in ==0)
		in = getchar();
}


int main()
{
int i;

int s[10]={10,111,112,200,250,300,312,213,200,100};
int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);
for(i=0;i<140;i=i+1)
{
setcolor(s[i]%10);
line(rand()%30,rand()%300,rand()%400,rand()%200);

}
wait_for_char();
	closegraph();
	return(0);
	}
