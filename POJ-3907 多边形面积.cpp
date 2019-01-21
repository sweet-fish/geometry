#include<bits/stdc++.h>
using namespace std;

const double eps=1e-10;
struct point
{
    double x,y;
}p[100005];
bool cmp(const point &a,const point &b)
{
    return (a.x-p[0].x)*(b.y-p[0].y)-(a.y-p[0].y)*(b.x-p[0].x)>=eps;
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;++i)
            cin>>p[i].x>>p[i].y;
        double ans=0;
        for(int i=0;i<n;++i)
            ans+=cross(p[i],p[(i+1)%n]);
        ans=0.5*fabs(ans);
        cout<<int(ans+0.5)<<endl;
    }
}
