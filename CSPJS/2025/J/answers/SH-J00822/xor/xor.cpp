#include <bits/stdc++.h>
using namespace std;
const int maxn=500001;
int a[maxn],f[maxn],c[maxn];
/*int yiyu(int x,int y)
{
	int i1=1,i2=1,i;
	int xl[2^21+1],yl[2^21+1];
	while(x>1)
	{
		xl[i1]=x%2;
		x/=2;
		i1++;
	}
	while(y>2)
	{
		yl[i2]=y%2;
		y/=2;
		i2++;
	}
	for(i=1;i<=min(i1,i2);i++)
	{
		if(yl!=xl)
		{
			if(i2>i1)
				yl[i]=0;
			else
				yl[i]=0;
		}
		else
		{
			if(i2>i1)
				yl[i]=1;
			else
				yl[i]=1;
		}
	}
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,l,r,i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(l=1;l<=n;l++)
		for(r=l;r<=n;r++)
		{
			j=r-l;
			if(j==0)
				f[r]=c[r];
			else
				f[r]=f[r-1]^c[r];//yiyu(f[r-1],c[r]);//f[r-1]^c[r];
			cout<<l<<r<<" "<<f[r]<<endl;
			if(f[r]==k)
				ans++;
		}
	cout<<ans<<endl;
	return 0;
}
