#include <bits/stdc++.h>
using namespace std;

struct seat
{
    int num;
    int id;
};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    seat a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i].num;
        a[i].id=i+1;
    }
    for(int i=0;i<n*m;i++)
    {
        for(int j=i+1;j<n*m;j++)
        {
            if(a[i].num<a[j].num)
            {
                swap(a[i].id,a[j].id);
            }
        }
    }
    int c=1,r,t=a[0].id-n;
    while(t>0)
    {
        t-=n;
        c++;
    }
    r=a[0].id%n;
    if(r==0)
        r=n;
    if(c%2==0)
    {
        r=n-r+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
