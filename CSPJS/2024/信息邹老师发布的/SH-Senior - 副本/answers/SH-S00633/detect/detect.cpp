#include<bits/stdc++.h>
using namespace std;
int d[100001],v[100001],a[100001],q[100001],b[100001];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,vx;
	cin>>t;
	while(t--)
	{
		int sum=0,ans=0,s=0;
		cin>>n>>m>>l>>vx;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
		{
			cin>>q[i];
			s++;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]>vx)
				{
					sum++;
					for(int j=1;j<=m;j++)
					{
						if(d[i]<q[j])
							b[q[j]]++;
						else b[q[j]]=-1;
					}
				}
			}
		}
		for(int i=1;i<=l;i++)
			if(b[i]>1||b[i]==-1) ans++;
		cout<<sum<<" "<<m-ans<<endl;
	}
	return 0;
}
