#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int x1,x2,x3,y1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3;
double angle;
void makeTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}
void translation()
{
    makeTriangle(x1,y1,x2,y2,x3,y3);
    setcolor(YELLOW);
    int xt,yt;
    cout <<"Translation factor x y = ";
    cin>>xt>>yt;

    nx1=x1+xt;
    ny1=y1+yt;

    nx2=x2+xt;
    ny2=y2+yt;

    nx3=x3+xt;
    ny3=y3+yt;

    line(nx1,ny1,nx2,ny2);
    line(nx2,ny2,nx3,ny3);
    line(nx3,ny3,nx1,ny1);

    setcolor(WHITE);
    getch();
    cleardevice();
}
void scaling()
{
    makeTriangle(x1,y1,x2,y2,x3,y3);

    setcolor(YELLOW);
    int sx,sy;
    cout<<"Scaling factor x y = ";
    cin>>sx>>sy;

    nx1=x1*sx;
    ny1=y1*sy;

    nx2=x2*sx;
    ny2=y2*sy;

    nx3=x3*sx;
    ny3=y3*sy;

    line(nx1,ny1,nx2,ny2);
    line(nx2,ny2,nx3,ny3);
    line(nx3,ny3,nx1,ny1);

    setcolor(WHITE);
    getch();
    cleardevice();
}
void rotation()
{
   makeTriangle(x1,y1,x2,y2,x3,y3);
    setcolor(YELLOW);
    int r;
    cout<<"Angle of rotation = ";
    cin>>r;

    angle=3.14*r/180;

    nx1=abs(x1*cos(angle)-y1*sin(angle));
    ny1=abs(x1*sin(angle)+y1*cos(angle));

    nx2=abs(x2*cos(angle)-y2*sin(angle));
    ny2=abs(x2*sin(angle)+y2*cos(angle));

    nx3=abs(x3*cos(angle)-y3*sin(angle));
    ny3=abs(x3*sin(angle)+y3*cos(angle));

    line(nx1,ny1,nx2,ny2);
    line(nx2,ny2,nx3,ny3);
    line(nx3,ny3,nx1,ny1);

    setcolor(WHITE);
    getch();
    cleardevice();
}
int main()
{
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    initwindow(500, 500);
    translation();
    scaling();
    rotation();
    getch();
    return 0;
}

/*

150 150
450 150
300 300

*/
