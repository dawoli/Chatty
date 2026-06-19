#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,L,V;
struct NODE{int d,v,a;}car[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>L>>V;
		int ans1=0,ans2=0,f=0;
		int p[100005];
		bool t[1000006];
		for(int i=1;i<=n;i++)
		{
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=1;i<=m;i++) cin>>p[i],t[p[i]]=1;
		for(int i=1;i<=n;i++)
		{
			f=0;
			for(int j=car[i].d;j<=L;j++)
			{
				if(car[i].v>V&&t[j]) f=1;
			}
			if(f) ans1++;
		}
		ans2=m-ans1+1;
		cout<<ans1<<' '<<ans2<<'\n';
	}
	return 0;
}
