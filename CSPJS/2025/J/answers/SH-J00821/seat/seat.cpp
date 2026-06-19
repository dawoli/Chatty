#include<bits/stdc++.h>
using namespace std;
int x[100];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >>x[i];
    }
    int y = x[1];
    sort(x+1,x+n*m+1,cmp);
    int l = 0,r = 1;
    for(int i = 1;i <= n*m;i++)
    {
        if(r%2==1)
        {
            l++;
        }
        else l--;
        if(r%2==1&&l>n)
        {
            r++;
            l--;
        }
        else if(r%2==0&&l<1)
        {
            l++;
            r++;
        }
        if(x[i]==y)
        {
            cout <<r<<' '<<l;
            return 0;
        }
    }
}
