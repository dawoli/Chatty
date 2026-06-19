#include<iostream>
#include<algorithm>
using namespace std;

int a[110];
bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int y=1;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int xR=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            for(int j=m;j>=1;j--)
            {
                if(a[y]==xR)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                y++;
            }
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
                if(a[y]==xR)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                y++;
            }
        }
    }
    return 0;
}
