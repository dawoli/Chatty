#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m,target,a[105],seat[15][15];
bool cmp(int x,int y)
{

    return x > y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    target = a[1];
    int x = 1,y = 1,ab = 1,pos = 0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(ab == 1)
        {
            for(int j=1;j<=n;j++)
            {
                seat[j][i] = a[++pos];
                if(a[pos] == target)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
            ab = 2;
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                seat[j][i] = a[++pos];
                if(a[pos] == target)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
            ab = 1;
        }
    }




    return 0;
}
