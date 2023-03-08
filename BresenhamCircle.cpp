#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
void drawLine(int x0,int y0,int r)
{
    int x=0,y=r;
    int p=1-r;
    while(x<y){
        putpixel(x0+x,y0+y,RED);
        putpixel(x0+x,y0-y,RED);
        putpixel(x0-x,y0+y,RED);
        putpixel(x0-x,y0-y,RED);

        putpixel(x0+y,y0+x,RED);
        putpixel(x0+y,y0-x,RED);
        putpixel(x0-y,y0+x,RED);
        putpixel(x0-y,y0-x,RED);
        x++;
        if(p<0){
            p=p+2*x+1;
        }else{
            y--;
            p=p+2*x+1-2*y;
        }
    }
}
int main()
{
   int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x0,y0,r; //100 150 150
    cin>>x0>>y0>>r;
    drawLine(x0,y0,r);

    getch();
}

