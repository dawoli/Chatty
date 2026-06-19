#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m,L,V;
		int ans1=0,ans2=0;
		int cc[100005];
		int b[100005],c[100005];
		int d[100005],a[100005],v[100005],p[100005];
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			b[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			c[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=0&&v[i]>V)
			{
				for(int j=1;j<=m;j++)
				{
					if(p[j]>=d[i])
					{
						b[i]=1;
					}
				}
			}
			else if(a[i]>0&&v[i]<=V)
			{
				int s=(0-(V*V-v[i]*v[i])%(a[i]*2)+(V*V-v[i]*v[i]))/a[i]/2;
				for(int j=1;j<=m;j++)
				{
					if(p[j]>d[i]+s)
					{
						b[i]=1;
					}
				}
			}
			else if(a[i]<0&&v[i]>=V)
			{
				int s=(0-(v[i]*v[i]-V*V)%(0-a[i]*2)+(v[i]*v[i]-V*V))/(0-a[i])/2;
				if((v[i]*v[i]-V*V)%(0-a[i]*2)==0) s--;
				if(p[m]>=d[i]&&p[m]<=d[i]+s)
				{
						b[i]=1;
						break;
				}
				for(int j=1;j<=m-1;j++)
				{
					if(p[j]>=d[i]&&p[j]<=d[i]+s)
					{
						b[i]=1;
						c[j]++;
						cc[i]=1;
					}
				}
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans1+=b[i];
			ans2+=cc[i];
		}
		int ccc=0;
		for(int j=1;j<=m;j++)
		{
			ccc=max(ccc,c[j]);
		}
		cout<<ans1<<" "<<m-ans2+ccc-2<<endl;
	}
	return 0;
}
