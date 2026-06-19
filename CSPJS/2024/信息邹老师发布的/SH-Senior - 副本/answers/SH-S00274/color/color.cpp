#include<bits/stdc++.h>
using namespace std;
int a[200010],k1[2010][2010],k2[2010][2010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,zz,n,i,j,b,p,ma;
	cin>>t;
	for(zz=1;zz<=t;zz++)
	{
		ma=-1;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<2010;j++)
			{
				k1[i][j]=-10000000;k2[i][j]=-10000000;
			}
		}
		for(i=1;i<=n;i++) cin>>a[i];
		k1[1][0]=0;
		k2[1][0]=0;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=2010;j++)
			{
				if(j!=a[i-1])
				{
					k1[i][j]=k1[i-1][j];
					if(a[i]==a[i-1]) k1[i][j]+=a[i];
					k2[i][j]=k2[i-1][j-1];
					if(a[i]==a[i-1]) k2[i][j]+=a[i];
				}
				if(j==a[i-1])
				{
					k1[i][j]=k1[i-1][j];
					if(a[i]==a[i-1]) k1[i][j]+=a[i];
					for(p=1;p<i-1;p++)
					{
						b=k2[i-1][a[p]];
						if(a[p]==a[i]) b+=a[i];
						if(b>k1[i][j]) k1[i][j]=b;
					}
					b=k2[i-1][0];
					if(b>k2[i][j]) k1[i][j]=b;
					k2[i][j]=k2[i-1][j];
					if(a[i]==a[i-1]) k2[i][j]+=a[i];
					for(p=1;p<i-1;p++)
					{
						b=k1[i-1][a[p]];
						if(a[p]==a[i]) b+=a[i];
						if(b>k2[i][j]) k2[i][j]=b;
					}
					b=k1[i-1][0];
					if(b>k1[i][j]) k2[i][j]=b;
				}
			}
		}
		for(i=0;i<=2000;i++) ma=max(ma,k1[n][i]);
		for(i=0;i<=2000;i++) ma=max(ma,k2[n][i]);
		cout<<ma<<endl;
	}
	return 0;
}
