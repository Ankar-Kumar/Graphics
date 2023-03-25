#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int n;
int fact(int num)
{
    if(num<=1) return 1;
    return num*fact(num-1);
}
double combination(int num)
{

}

void bezier(int x[4], int y[4])
{
    double xt, yt, t,b;
    int nfact=fact(n-1);
    putpixel(x[0],y[0],RED);
    for(t = 0.0; t <= 1.0; t += 0.001)   //u===t
    {
        xt=0;yt=0;
        for(int i=0; i<n; i++){
            b=(nfact*pow(t,i)*pow(1-t,n-i-1)/(fact(n-i-1)*fact(i)));
            xt+=b*x[i];
            yt+=b*y[i];
        }
        putpixel(xt,yt,WHITE);
        //delay(1);
    }
    putpixel(x[n-1],y[n-1],RED);
    for(int i=0;i<n;i++){
        //setfillstyle(SOLID_FILL,RED);
        circle(x[i],y[i],n);
        //floodfill(x[i],y[i],RED);
    }


}

int main()
{
    //freopen("BezierCurve.txt","r",stdin);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cout<<"number of control points  ";
    cin>>n;
    int x[n], y[n]; //200 300 300 400 300 300 100 200
    cout<<"Enter the four control points : "<<endl;;
    for(int i=0; i<n; i++)
        cin>>x[i]>>y[i];

    bezier(x, y);
    getch();
    return 0;
}
