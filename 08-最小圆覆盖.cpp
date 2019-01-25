//Created by sweet_fish
point geto(point a,point b,point c)
{
    point o;
    double a1 = b.x - a.x;
    double b1 = b.y - a.y;
    double c1 = (a1 * a1 + b1 * b1) / 2.0;
    double a2 = c.x - a.x;
    double b2 = c.y - a.y;
    double c2 = (a2 * a2 + b2 * b2) / 2.0;
    double d = a1 * b2 - a2 * b1;
    o.x = a.x + (c1 * b2 - c2 * b1) / d;
    o.y = a.y + (a1 * c2 - a2 * c1) / d;
    return o;
}
point o;
double r2;
void mc(int n)
{
    random_shuffle(p,p+n);
    o=p[0];
    r2=0;
    for(int i=1;i<n;++i)
        if(fabs(dist2(p[i],o)-r2)>=eps)
        {
            o=p[i],r2=0;
            for(int j=0;j<i;++j)
                if(fabs(dist2(p[j],o)-r2)>=eps)
                {
                    o=(p[i]+p[j])*0.5;
                    r2=dist2(p[i],o);
                    for(int k=0;k<j;++k)
                        if(fabs(dist2(p[k],o)-r2)>=eps)
                        {
                            o=geto(p[i],p[j],p[k]);
                            r2=dist2(o,p[i]);
                        }
                }
        }
}
