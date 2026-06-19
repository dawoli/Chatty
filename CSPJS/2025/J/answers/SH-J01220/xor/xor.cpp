#include<bits/stdc++.h>
using namespace std;
int n,k;
bool a[500005][25];
int b[500005],g[500005];
bool p[25],q[25];

int yihuo(int x,int y)
{
	if(x==y) return g[x];
	memset(p,0,sizeof(p));
	int ma=0,jie=0;
	for(int i=x;i<=y;i++) ma=max(ma,b[i]);
//	cout<<ma<<endl;
	for(int i=1;i<=ma;i++)
	{
		int cnt=0;
		for(int j=x;j<=y;j++)
		{
			if(a[j][i]==1) cnt++;
		}
		if(cnt%2==1) p[i]=1;
		if(cnt%2==0) p[i]=0;
	 }
	for(int i=ma;i>=1;i--)
	{
		jie*=2;		
		jie+=p[i];
	  } 
	 return jie;  
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int k1=0;
		cin>>g[i];
		int g1=g[i];
		while(g1>0)
		{
			k1++;
			a[i][k1]=g1%2;
			g1/=2;
		}
		b[i]=k1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(yihuo(i,j)==k) 
			{
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
