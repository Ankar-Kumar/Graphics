#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int xmin=20,xmax=100,ymin=40,ymax=100;
int leftx[100],lefty[100],rightx[100],righty[20],bottomx[20],bottomy[20],topx[20],topy[30];

void drawwindow()
{
    rectangle(xmin, ymin, xmax, ymax);
}

int leftClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%(n);
        int m;
        if(x[j]-x[i]) m=(y[j]-y[i])/(x[j]-x[i]);
        else m=100000;
        if(x[i]<xmin && x[j]>=xmin) //out to in condition
        {
            leftx[s]=xmin;
            lefty[s]=y[i]+(xmin-x[i])*m;

            s++;
        }
        else if(x[i]<xmin && x[j]<xmin) //out to out condition
        {
            continue;
        }
        else if(x[i]>=xmin && x[j]<xmin) //in to out condition
        {
            // add the first coordinate as it is already in
           leftx[s]=x[i];
            lefty[s]=y[i];
            s++;

            // add the next coordinate with ymin
           leftx[s]=xmin;
            lefty[s]=y[j]+(xmin-x[j])*m;
            s++;
        }
        else if(x[i]>=xmin && x[j]>=xmin) //in to in condition
        {
            // this is accepted
           leftx[s]=x[i];
            lefty[s]=y[i];
            s++;
        }
    }

    // s is number of coordinates in left clipped array
    return s;
}

int topClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        int m;
        if(x[j]-x[i]) m=(y[j]-y[i])/(x[j]-x[i]);
        else m=100000;
        if(y[i]>ymax && y[j]<=ymax) //out to in condition
        {
            topx[s]=x[i]+(ymax-y[i])/m;
            topy[s]=ymax;
            s++;
        }
        else if(y[i]>ymax && y[j]>ymax) //out to out condition
        {
            continue;
        }
        else if(y[i]<=ymax && y[j]>ymax) //in to out condition
        {
            topx[s]=x[i];
            topy[s]=y[i];
            s++;
            topx[s]=x[j]+(ymax-y[j])/m;
            topy[s]=ymax;
            s++;
        }
        else if(y[i]<=ymax && y[j]<=ymax) //in to in condition
        {
            topx[s]=x[i];
            topy[s]=y[i];
            s++;
        }
    }
    return s;
}

int rightClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%(n);
        int m;
        if(x[j]-x[i]) m=(y[j]-y[i])/(x[j]-x[i]);
        else m=100000;
        if(x[i]>xmax && x[j]<=xmax) //out to in condition
        {
            rightx[s]=xmax;
           righty[s]=y[i]+(xmax-x[i])*m;
            s++;
        }
        else if(x[i]>xmax && x[j]>xmax) //out to out condition
        {
            continue;
        }
        else if(x[i]<=xmax && x[j]>xmax) //in to out condition
        {
            rightx[s]=x[i];
           righty[s]=y[i];
            s++;
            rightx[s]=xmax;
           righty[s]=y[j]+(xmax-x[j])*m;
            s++;
        }
        else if(x[i]<=xmax && x[j]<=xmax) //in to in condition
        {
            rightx[s]=x[i];
            righty[s]=y[i];
            s++;
        }
    }
    return s;
}

int bottomClip(int x[],int y[],int n)
{
    int s=0,j;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        int m;
        if(x[j]-x[i]) m=(y[j]-y[i])/(x[j]-x[i]);
        else m=100000;
        if(y[i]<ymin && y[j]>=ymin) //out to in condition
        {
            bottomx[s]=x[i]+(ymin-y[i])/m;
            bottomy[s]=ymin;
            s++;
        }
        else if(y[i]<ymin && y[j]<ymin) //out to out condition
        {
            continue;
        }
        else if(y[i]>=ymin && y[j]<ymin) //in to out condition
        {
            bottomx[s]=x[i];
            bottomy[s]=y[i];
            s++;
            bottomx[s]=x[j]+(ymin-y[j])/m;
            bottomy[s]=ymin;
            s++;
        }
        else if(y[i]>=ymin && y[j]>=ymin) //in to in condition
        {
            bottomx[s]=x[i];
            bottomy[s]=y[i];
            s++;
        }
    }
    return s;
}

int main()
{
    initwindow(500,500);
    int x[]={55,55,15,65,115,75,75};
    int y[]={5,15,15,215,15,15,5};

    int n=7,j;
    drawwindow();
    for(int i=0;i<n;i++){
        j=(i+1)%n;
        line(x[i],y[i],x[j],y[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n1=leftClip(x,y,n);
    for(int i=0;i<n1;i++){
        j=(i+1)%n1;
        line(leftx[i],lefty[i],leftx[j],lefty[j]);
    }
    getch();
    cleardevice();
    drawwindow();
    int n2=topClip(leftx,lefty,n1);

    // print the top clipped new shape
    for(int i=0;i<n2;i++)
    {
        j=(i+1)%n2;
        line(topx[i],topy[i],topx[j],topy[j]);
    }
    getch();
    cleardevice();
    drawwindow();

    int n3=rightClip(topx,topy,n2);

    // print the top clipped new shape
    for(int i=0;i<n3;i++)
    {
        j=(i+1)%n3;
        line(rightx[i],righty[i],rightx[j],righty[j]);
    }
    getch();
    cleardevice();
    drawwindow();

    int n4=bottomClip(rightx,righty,n3);

    // print the top clipped new shape
    for(int i=0;i<n4;i++)
    {
        j=(i+1)%n4;
        line(bottomx[i],bottomy[i],bottomx[j],bottomy[j]);
    }
    getch();


}
