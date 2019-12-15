#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

struct object
{
    double m;
    double x;
    double y;
    double Vx;
    double Vy;
    double ax;
    double ay;
};

int main()
{
    object planet[30];
    int n;
    double R[30][30];
    cout<<"kol-vo objektov:";
    cin>>n;
    cout<<"massa, x, y, speed x, speed y"<<endl;
    for (int i=0; i<n; i++)
    {
       cin>>planet[i].m>>planet[i].x>>planet[i].y>>planet[i].Vx>>planet[i].Vy;
    }
    for (int t=0; t<3000; t++)
    {
       for (int i=0; i<n; i++)
       {
            R[i][i]=0;
            for (int j=i+1; j<n; j++)
            {
                R[i][j]=sqrt(pow(planet[i].x-planet[j].x, 2)+pow(planet[i].y-planet[j].y, 2));
                R[j][i]=R[i][j];
            }
       }
       for (int i=0; i<n; i++)
       {
            planet[i].ax=0;
            planet[i].ay=0;
            for (int j=0; j<n; j++)
            {
                if (i!=j)
                {
                    planet[i].ax+=planet[j].m/pow(R[i][j],3)*(planet[j].x-planet[i].x)*4;
                    planet[i].ay+=planet[j].m/pow(R[i][j],3)*(planet[j].y-planet[i].y)*4;
                }
            }
       }
       for (int i=0; i<n; i++)
       {
            planet[i].x+=planet[i].Vx/1000;
            planet[i].y+=planet[i].Vy/1000;
            planet[i].Vx+=planet[i].ax/1000;
            planet[i].Vy+=planet[i].ay/1000;
       }
       cout << planet[0].x<<" "<<planet[0].y<<" "<< planet[0].Vx<<" "<<planet[0].Vy<< endl;
    }
    return 0;
}
