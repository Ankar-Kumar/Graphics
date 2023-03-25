

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int l = 1, r = 2, b = 4, t = 8;
double xmin, xmax, ymin, ymax;

int computeCode(double x, double y)
{
    int code = 0;
    if (x < xmin)
        code |= l;
    else if (x > xmax)      // to the r of clip window
        code |= r;
    if (y < ymin)           // below the clip window
        code |= b;
    else if (y > ymax)      // above the clip window
        code |= t;
    return code;
}
void lineCLipping(double x0,double y0,double x1,double y1)
{
    int code0=computeCode(x0,y0);
    int code1=computeCode(x1,y1);
    int flag=0;
    while(1)
    {
        if(!(code0|code1))
        {
            flag=1;
            break;
        }
        else if(code0 & code1) break;
        else
        {
            double m=(y1-y0)/(x1-x0);
            double x,y;
            int code=code0?code0:code1;
            if(code & t)
            {
                x=x0+(ymax-y0)/m;
                y=ymax;
            }
            else if(code & b)
            {
                x=x0+(ymin-y0)/m;
                y=ymin;
            }
            if(code & l)
            {
                y=y0+m*(xmin-x0);
                x=xmin;
            }
            else if(code & r)
            {
                y=y0+m*(xmax-x0);
                x=xmax;
            }
            if(code==code0)
            {
                x0=x;
                y0=y;
                code0=computeCode(x0,y0);
            }
            else
            {
                x1=x;
                y1=y;
                code1=computeCode(x1,y1);
            }
        }

    }
    if (flag)
    {
        setcolor(GREEN);
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(BLUE);
        line(x0, y0, x1, y1);
    }
}
int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");
    xmin = 100;
    xmax = 500;
    ymin = 10;
    ymax = 300;
    int t=50;
    double x0, y0, x1, y1;
    while(t--){
     x0=50,y0=rand(),x1=600,y1=90;
    lineCLipping(x0,y0,x1,y1);
    }
    getch();
}
