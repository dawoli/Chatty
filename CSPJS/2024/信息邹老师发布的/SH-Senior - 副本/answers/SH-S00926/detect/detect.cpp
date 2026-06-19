#include<bits/stdc++.h>
using namespace std;
int T,t1,t2;
int n,m,L,V;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
int ans[30][5];
bool f=1;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		cin>>n>>m>>L>>V; 
		for(int i=0;i<=n+3;i++)
		{
			d[i]=0;
			v[i]=0;
			a[i]=0;
		}
		for(int i=0;i<=m+3;i++)
		{
			p[i]=0;
		}
		f=1;
		t1=0;
		t2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0)
			{
				f=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+1+m);
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=0)
			{
				if(p[m]-d[i]>(1.0*(V*V-v[i]*v[i]))/(2*a[i]))
				{
					ans[ii][1]++;
					t1=m;
				}
			}
			else
			{
				t1=1;
				while(p[t1]<d[i] and t1<=m+1)
				{
					t1++;
				}
				if(t1<=m)
				{
					if(p[t1]-d[i]<(1.0*(V*V-v[i]*v[i]))/(2*a[i]))
					{
						ans[ii][1]++;
						t2=t1;
					}
				}
			}
		}
		if(f==1)
		{
			ans[ii][2]=m-1;
		}
		else
		{
			ans[ii][2]=(m+5)/2;
		}
	}
	for(int i=1;i<=T;i++)
	{
		cout<<ans[i][1]<<" "<<ans[i][2];
	}
	return 0;
}
