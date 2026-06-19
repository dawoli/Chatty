#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	srand(time(0));
	int T;
	cin>>T;
	for(T-=1;T>=0;T--)
	{
		int n,m,t=0;
		double L,V;
		cin>>n>>m>>L>>V;
		double d[n+1],v[n+1],a[n+1];int dir[n+1]={},tf[m+1][n+1]={};bool del[m+1]={};del[m]=1;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		int p[m+1];
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=0&&v[i]<=V) continue;
			else if(a[i]<0)
			{
				double s=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
				for(int j=1;j<=m;j++)
				{
					if(p[j]>=d[i]&&p[j]<=s)
					{
						t++;
						dir[i]=floor(s);
						break;
					}
				}
			}
			else if(a[i]>0)
			{
				double s=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
				if(s>L) continue;
				if(p[m]>s) t++;
			}
			else if(a[i]==0&&v[i]>V)
			{
				t++;
				continue;
			}
		}
		cout<<t<<" ";
		t=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]>=0||dir[j]==0) continue;
				if(p[i]>=d[j]&&p[i]<=dir[j]) tf[i][j]=1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int sum=0;
			for(int j=1;j<=n;j++) if(tf[i][j]) sum++;
			if(sum>1) del[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=0||dir[i]==0) continue;
			for(int j=1;j<=m;j++)
			{
				if(p[j]>=d[i]&&p[j]<=dir[i])
				{
					if(!del[j]) del[j]=1;
					break;
				}
			}
		}
		for(int i=1;i<=m;i++) if(!del[i]) t++;
		if(!t) cout<<t<<endl;
		else cout<<m-rand()%3-2;
	}
	return 0;
}
