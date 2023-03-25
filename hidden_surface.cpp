

#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;
void triangle()
{
    setcolor(GREEN);
    line(150, 150, 350, 350);
    line(150, 150, 100, 350);
    line(100, 350, 350, 350);
    setfillstyle(1,GREEN);
    floodfill(155,200,GREEN);
}

void circle()
{
    setcolor(RED);
    circle(300,300,100);
    setfillstyle(1,RED);
    floodfill(302,302,RED);
}

void rectangle()
{
     setcolor(WHITE);
    rectangle(300,300,450,450);
    setfillstyle(1,WHITE);
    floodfill(302,302,WHITE);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    string a,b,c;
//    triangle();
//     circle();
//      rectangle();
//    //cin>>a>>b>>c;
    for(int i=0;i<3;i++){
            cin>>a;
        if(a=="triangle"){
            triangle();
        }
        if(a=="circle"){
            circle();
        }
        if(a=="rectangle"){
            rectangle();
        }
    }


    getch();
    return 0;
}
