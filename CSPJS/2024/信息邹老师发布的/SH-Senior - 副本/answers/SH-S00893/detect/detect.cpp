#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,v,cszs=0,zscs=1,a[100009],b[100009],c[100009],d[100009];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cszs=0;
		zscs=1;
		cin>>n>>m>>l>>v;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int j=1;j<=m;j++)
	    {
			cin>>d[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(c[j]==0)
			{
				if(b[j]>v)
				{
					cszs++;
				}
			}
			else if(c[j]>0)
			{
				if(a[j]>d[m])continue;
				if((v*v-b[j]*b[j])<((d[m]-a[j])*2*c[j]))
				{
					cszs++;
				}
			}
			else if(c[j]<0)
			{
				if(b[j]>v)
				{
					cszs++;
					zscs++;
				}
			}
		}
		cout<<cszs<<" "<<m-zscs<<endl;
	}
}
