#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int a[100010],b[21010][3];
    int c[5];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int t,n;
    int cur=0;
    int maxn,minn,midd,ans,maxnn,minnn=0;
    cin>>t;
    for(int n=1;n<=t;n++)
    {
        cin>>a[n];
        ans=0;
        for(int i=1;i<=a[n];i++)
        {
            memset(c,0,sizeof(c));
        	for(int j=1;j<=3;j++)
        	{
        		cin>>b[i][j];
        		if(b[i][maxn]<=b[i][j])
                {
                    maxn=j;
                    b[i][maxn]=b[i][j];
                    c[maxn]++;
                }
				if(b[i][minn]<=b[i][j]){minn=j;b[i][minn]=b[i][j];}
				if(b[i][j]<b[i][maxn]&&b[i][j]>b[i][minn]){midd=j;b[i][midd]=b[i][j];}
        	}
            if(c[maxn]>(a[n]/2))
            {
                int k;
                for(int k=1;k<=i;k++)
                {
                    if(b[minnn][maxn]<=b[k][maxn]){minnn=k;b[minnn][maxn]=b[k][maxn];}
                    b[minnn][maxn]=b[minnn][midd];
                }
            }
			ans+=b[i][maxn];
		}
		cout<<ans<<endl;
    }
    return 0;
}
