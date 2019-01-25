//Created By sweet_fish
#include<bits/stdc++.h>
using namespace std;

const double eps=1e-10;
struct point
{
    int x,y;
}p[100005];
double cross(point a,point b)
{
    return 1.0*a.x*b.y-a.y*b.x;
}
int main()
{
    cout<<fixed<<setprecision(1);
    int _;
    cin>>_;
    for(int t=1;t<=_;++t)
    {
        int n;
        cin>>n;
        int tx=0,ty=0;
        for(int i=0;i<n;++i)
        {
            int x=0,y=0;
            cin>>x>>y;
            tx+=x,ty+=y;
            p[i].x=tx,p[i].y=ty;
        }
        cout<<"Scenario #"<<t<<":"<<endl;
        if(n==1)
        {
            cout<<"0 1 0"<<endl;
            continue;
        }
        double s=0;
        int b=0;
        for(int i=0;i<n;++i)
        {
            point p1=p[i],p2=p[(i+1)%n];
            s+=cross(p1,p2);
            b+=abs(__gcd(p1.x-p2.x,p1.y-p2.y));
        }
        s=0.5*fabs(s);
        int a=s-0.5*b+1;
        cout<<a<<' '<<b<<' '<<s<<endl;
        if(t!=_)
            cout<<endl;
    }
}
