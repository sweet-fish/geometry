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

double dist2(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}

//Grahan_Scan
bool cmp1(const point &a,const point &b)
{
    double dot=cross(a-p[0],b-p[0]);
    if(fabs(dot)<eps)
        return dist(a,p[0])<=dist(b,p[0]);
    return dot>=eps;
}
int Grahan_Scan(int n)
{
    double miny=1e8;
    int id=0;
    for(int i=0;i<n;++i)
        if(p[i].y<miny)
        {
            miny=p[i].y;
            id=i;
        }
    swap(p[0],p[id]);
    sort(p+1,p+n,cmp1);
    int sz=0;
    a[sz++]=p[0];
    a[sz++]=p[1];
    for(int i=2;i<n;++i)
    {
       while(cross(p[i]-a[sz-2],p[i]-a[sz-1])<eps)
            --sz;
       a[sz++]=p[i];
    }
    return sz;
}

//Andrew
bool cmp2(const point &a,const point &b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int Andrew(int n)
{
    sort(p,p+n,cmp2);
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
