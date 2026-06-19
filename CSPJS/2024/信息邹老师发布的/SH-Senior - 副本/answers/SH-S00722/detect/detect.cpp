#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define f(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+10;
int T,n,m,L,V,d[N],v[N],a[N],p[N],t,ans,res,pmax;
bool st=false;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		memset(d,0,sizeof d);
		memset(v,0,sizeof v);
		memset(a,0,sizeof a);
		memset(p,0,sizeof p);
		ans=m,res=0,t=0,pmax=0,st=false;
		cin>>n>>m>>L>>V;
		F(i,1,n)cin>>d[i]>>v[i]>>a[i];
		F(i,1,m)
		{
			cin>>p[i];
			pmax=max(pmax,p[i]);
		}
		F(i,1,n)if(v[i]>V&&pmax>=d[i])ans=m-1,res++,st=true;
		if(st==true)cout<<res<<' '<<ans<<'\n';
		else if(st==false)cout<<res<<' '<<m<<'\n';
	}
	return 0;
} 
