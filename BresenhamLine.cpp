#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
void drawLine(int x0,int y0,int x1,int y1)
{
    int dx=x1-x0;
    int dy=y1-y0;
    int dy2=dy*2;
    int p=dy2-dx;
    while(x0<x1 and y0<y1){
        if(p<0){
            p=2*dy+p;
            putpixel(x0,y0,RED);
        }else{
            p=dy2+p-2*dx;
            putpixel(x0,y0,RED);
            y0++;
        }x0++;
    }
}
int main()
{
   int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x0,x1,y0,y1;
    cin>>x0>>y0>>x1>>y1;
    drawLine(x0,y0,x1,y1);

    getch();
}
