#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO{
char buf[8888888],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin)),*p2=0,*p1++)
char ibuf;
int rd(int x=0)
{
	bool f=0;
	for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=1;
	for(;isdigit(ibuf);ibuf=getchar())x=(x<<1)+(x<<3)+(ibuf^48);
	return f?-x:x;
}
}using IO::rd;//namespace IO
int l[100010];
int r[100010];
int cnt[1000100];
struct aaa
{
	int b,e;
}a[100010];
int p[100010];
bool operator<(aaa a,aaa b)
{
	return a.e<b.e;
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T=rd();while(T--)
	{
		int n=rd(),m=rd(),L=rd(),V=rd();
		for(int i=0;i<=L+1;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int d=rd(),v=rd(),a=rd();
			if(a==0)
			{
				if(v>V)l[i]=d,r[i]=L;
				else l[i]=L+1,r[i]=-1;
			}
			if(a<0)
			{
				if(v>V)l[i]=d,r[i]=min(L,(v*v-V*V-1)/(-2*a)+d);
				else l[i]=L+1,r[i]=-1;
			}
			if(a>0)
			{
				if(v>V)l[i]=d,r[i]=L;
				else
				{
					int x=(V*V-v*v)/(2*a)+1+d;
					if(x>L)l[i]=L+1,r[i]=-1;
					else l[i]=x,r[i]=L;
				}
			}
			// cout<<l[i]<<' '<<r[i]<<endl;
		}
		for(int i=1;i<=m;i++)cnt[p[i]=rd()+1]++;
		for(int i=1;i<=L+1;i++)cnt[i]+=cnt[i-1];
		int ans=0;int k=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[r[i]+1]-cnt[l[i]]>0)ans++,a[k++]={l[i]+1,r[i]+1};
		}
		sort(a,a+k);
		int cur=-1;int sum=m;
		for(int i=0;i<k;i++)
		{
			if(cur>=a[i].b)continue;
			else
			{
				int q=upper_bound(p+1,p+m+1,a[i].e)-p-1;
				cur=p[q];sum--;
			}
			// cout<<cur<<endl;
		}
		printf("%lld %lld\n",ans,sum);
	}
	return 0;
}