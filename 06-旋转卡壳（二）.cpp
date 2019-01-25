//Created by sweet_fish
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
point a[100005],b[100005],cen;
double dist2(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(point a,point b)
{
    return a.x*b.x+a.y*b.y;
}
double mind(point p,point a,point b)
{
    double r=dot(b-a,p-a);
    if(r<=eps)
        return sqrt(dist2(p,a));
    double d=dist2(a,b);
    if(r>=d)
        return sqrt(dist2(p,b));
    return fabs(cross(p-a,p-b)/sqrt(d));
}
bool cmp(const point &p1,const point &p2)
{
    double cro=cross(p1-cen,p2-cen);
    if(fabs(cro)<=eps)
        return dist2(p1,cen)<dist2(p2,cen);
    return cro>=eps;
}
double rot(int n,int m)
{
    for(int i=1;i<n;++i)
        if(a[i].y<a[0].y)
            swap(a[i],a[0]);
    cen=a[0];
    a[n]=a[0];
    sort(a+1,a+n,cmp);
    for(int i=1;i<m;++i)
        if(b[i].y>b[0].y)
            swap(b[i],b[0]);
    cen=b[0];
    b[m]=b[0];
    sort(b+1,b+m,cmp);
    double ans=1e10;
    int j=0;
    for(int i=0;i<n;++i)
    {
        while(cross(a[i]-b[j],a[i+1]-b[j])<cross(a[i]-b[j+1],a[i+1]-b[j+1]))
            j=(j+1)%m;
        ans=min(ans,mind(b[j],a[i],a[i+1]));
        ans=min(ans,mind(a[i],b[j],b[j+1]));
        ans=min(ans,mind(a[i+1],b[j],b[j+1]));
    }
    return ans;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0;i<n;++i)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=0;i<m;++i)
            scanf("%lf%lf",&b[i].x,&b[i].y);
            double ans=rot(n,m);
        printf("%.10f\n",ans);
    }
}
