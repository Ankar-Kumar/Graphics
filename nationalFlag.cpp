#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //Circle
    setfillstyle(1, RED);
    circle(320,240,100);
    floodfill(320,240, WHITE);

    //Rectangle
    setfillstyle(1, GREEN);
    rectangle(40,80,600,400);//left top right bottom
    floodfill(100,100,  WHITE);

    line(40, 80, 40, 800);

     getch();
    return 0;
}
