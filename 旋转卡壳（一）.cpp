#include<bits/stdc++.h>
using namespace std;

const double eps=1e-10;
const double pi=acos(-1);
struct point
{
    double x,y;
    point operator-(const point &t)const
    {
        return{x-t.x,y-t.y};
    }
};
point p[100005],a[100005];
int dist2(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
bool cmp(const point &a,const point &b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int Andrew(int n)
{
    sort(p,p+n,cmp);
    int sz=0;
    for(int i=0;i<n;++i)
    {
        while(sz>1&&cross(p[i]-a[sz-2],p[i]-a[sz-1])<=eps)
            --sz;
        a[sz++]=p[i];
    }
    int tp=sz;
    for(int i=n-2;i>=0;--i)
    {
        while(sz>tp&&cross(p[i]-a[sz-2],p[i]-a[sz-1])<=eps)
            --sz;
        a[sz++]=p[i];
    }
    return --sz;
}
int rot(int n)
{
    a[n+1]=a[0];
    int ans=0;
    int j=2;
    for(int i=0;i<n;++i)
    {
        while(cross(a[i+1]-a[i],a[j]-a[i])<cross(a[i+1]-a[i],a[j+1]-a[i]))
            j=(j+1)%n;
        ans=max(ans,dist2(a[j],a[i]));
        ans=max(ans,dist2(a[j],a[i+1]));
    }
    return ans;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        int sz=Andrew(n);
        printf("%d\n",rot(sz));
    }
}
