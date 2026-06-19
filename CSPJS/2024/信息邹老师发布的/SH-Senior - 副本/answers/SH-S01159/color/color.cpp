#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],ansa,b[100005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++)
	{
		ansa=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			/*p[i]=q[a[i]];
			b[i]=1;
			b[q[a[i]]]=1;
			q[a[i]]=i;*/ 
		}
		for(int i=0;i<((1<<n)-1);i++)
		{
			int v=i;
			for(int j=1;j<=n;j++)
			{
				int u=v%2;
				b[j]=u;
				v/=2;
			}
			int p=0,q=0,ans=0;
			for(int j=1;j<=n;j++)
			{
				if((a[j]==a[p]&&b[j]==0)||(a[j]==a[q]&&b[j]==1))
				{
					ans+=a[j];
				}
				if(!b[j])
					p=j;
				else
					q=j;
			}
			ansa=max(ans,ansa);
		}
		cout<<ansa<<endl;
	}
	return 0;
}
