#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,xf,yf,d;
	cin>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>m>>k;
		cin>>xf>>yf>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		if(k==1)
		{
			if((d==0&&yf+1<=m&&a[xf][yf+1]!='x')||(d==1&&xf+1<=n&&a[xf+1][yf]!='x')||(d==2&&yf-1>0&&a[xf][yf-1]!='x')||(d==3&&xf-1>0&&a[xf-1][yf]!='x'))
				cout<<2;
			else cout<<1;
		}
		else
		{
			while(k>=0)
			{
				if((d==0&&yf+1<=m&&a[xf][yf+1]!='x')||(d==1&&xf+1<=n&&a[xf+1][yf]!='x')||(d==2&&yf-1>0&&a[xf][yf-1]!='x')||(d==3&&xf-1>0&&a[xf-1][yf]!='x'))
				{
					if(d==0)
					{
						yf=yf+1;
						k--;
						sum++;
					}
					if(d==1)
					{
						xf=xf+1;
						k--;
						sum++;
					}
					if(d==2)
					{
						yf=yf-1;
						k--;
						sum++;
					}
					if(d==3)
					{
						xf=xf+1;
						k--;
						sum++;
					}
				}
				else
				{
					if(d<=2) d++;
					else d=0;
					k--;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
