#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int a[105],n,m,s[15][15];
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int c=a[1]; 
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;i<=n;i++)
            {
                cnt++;
                s[i][j]=a[cnt];
            }
        }

        else if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                cnt++;
                s[i][j]=a[cnt];
            }
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;i++)
        {
            if(s[i][j]==c)
			{
				cout<<j<<" "<<i;
				break;
			 }
        }
    }
    return 0;
}

