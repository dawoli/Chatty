#include<bits/stdc++.h>
using namespace std;
int t,d[200005],v[200005],a[200005],p[200005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) f=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		int cnt=0;
		if(f==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(v[i]>V&&d[i]<=p[m]) cnt++;
			}
			cout<<cnt<<" "<<m-1<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i]<=p[m])
				{
					double x=sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]));
					if(x>V*1.0) cnt++;
				}
			}
			cout<<cnt<<" "<<m-1;
		}
	}
	return 0;
} 
