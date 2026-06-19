#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
}
using IO::rd;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cout.tie(0);
	int T=rd();while(T--)
	{
		int n=rd();
		int sum=0;
		priority_queue<int>P[3];
		for(int i=0;i<n;i++)
		{
			int a=rd(),b=rd(),c=rd();
			int ma=max({a,b,c});
			int maa=max(a,b)^max(b,c)^max(c,a);
			int d[3]={a,b,c};
			int p=max_element(d,d+3)-d;
			P[p].push(maa-ma);
			sum+=ma;
		}
		for(int i=0;i<3;i++)while(P[i].size()>n/2)
			sum+=P[i].top(),P[i].pop();
		cout<<sum<<'\n';
	}
}