#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,score,pos,moni;
int a[105];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[++pos];
        }
    }
    score = a[1];
    sort(a+1,a+pos+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[++moni] == score)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(a[++moni] == score)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
