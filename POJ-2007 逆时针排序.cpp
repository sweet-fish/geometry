#include<bits/stdc++.h>
using namespace std;

const double eps=1e-10;
struct point
{
    double x,y;
    point operator - (const point &t)const
    {
        return {x-t.x,y-t.y};
    }
}p[100005];
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
bool cmp(const point &a,const point &b)
{
    return cross(a-p[0],b-p[0])>=eps;
}
int main()
{
    int n=0;
    while(cin>>p[n].x>>p[n].y)
        ++n;
    sort(p+1,p+n,cmp);
    for(int i=0;i<n;++i)
        cout<<'('<<p[i].x<<','<<p[i].y<<')'<<endl;
}
