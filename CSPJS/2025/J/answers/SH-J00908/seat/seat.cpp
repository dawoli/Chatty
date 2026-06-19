#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
    int sc,x;
};
Node a[110];

bool cmp(Node x,Node y)
{
    return x.sc>y.sc;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i].sc;
        a[i].x=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int p;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].x==1)
        {
            p=i;
            break;
        }
    }
    int s,t;
    if(p%n) t=p%n;
    else t=n;
    if(p%n) s=p/n+1;
    else s=p/n;
    if(s%2)
    {
        cout << s << ' ' << t;
    }
    else
    {
        cout << s << ' ' << (n-t+1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
