#include<bits/stdc++.h>
using namespace std;
int T,t,n,x,y,z,sum;
int a[100005];
int b[100005];
int c[100005];
int f[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int I=1;I<=T;I++)
	{
		cin>>n;x=0;y=0;z=0;t=0;sum=0;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				sum+=a[i];
				x++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				sum+=b[i];
				y++;
			}
			else if(c[i]>=a[i]&&c[i]>=b[i])
			{
				sum+=c[i];
				z++;
			}
		}
		if(x+x>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=b[i]&&a[i]>=c[i])
				{
					t++;
					if(b[i]>=c[i])f[t]=a[i]-b[i];
					else f[t]=a[i]-c[i];
				}
			}
			sort(f+1,f+t+1);
			for(int i=t-(n>>1);i>=1;i--)sum-=f[i];
		}
		if(y+y>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i]>=a[i]&&b[i]>=c[i])
				{
					t++;
					if(a[i]>=c[i])f[t]=b[i]-a[i];
					else f[t]=b[i]-c[i];
				}
			}
			sort(f+1,f+t+1);
			for(int i=t-(n>>1);i>=1;i--)sum-=f[i];
		}
		if(z+z>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(c[i]>=a[i]&&c[i]>=b[i])
				{
					t++;
					if(a[i]>=b[i])f[t]=c[i]-a[i];
					else f[t]=c[i]-b[i];
				}
			}
			sort(f+1,f+t+1);
			for(int i=t-(n>>1);i>=1;i--)sum-=f[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
