#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5000010
#define p 29
#define mod 998244353
#define M 1010
map <int,int> mp;
int a[N],b[N];
int hsh(string s)
{
	int n=s.size(),ans=0;
	for(int i=0;i<=n-1;i++) ans=(ans*p%mod+(s[i]-'a'+1))%mod;
	return ans;
}
void init(string s)
{
	int n=s.size();
	for(int i=1;i<=n;i++) a[i]=(a[i-1]*p%mod+(s[i-1]-'a'+1))%mod;
}
int h(int l,int r)
{
	return (a[r]+mod-a[l-1]*b[r-l+1]%mod)%mod;
}
string ssx[M],ssy[M],sx[M],sy[M];
vector <pair<int,int> > g[N<<1];
vector <int> m[N<<1];
int pos(string s)
{
	int n=s.size();
	for(int i=1;i<=n;i++)
		if(s[i-1]=='b')
			return i;
}
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	b[0]=1;
	for(int i=1;i<=N-10;i++) b[i]=b[i-1]*p%mod;
	int n,tt,l1=0,l2=0;
	cin>>n>>tt;
	for(int i=1;i<=n;i++)
	{
		cin>>ssx[i]>>ssy[i];
		l1+=ssx[i].size();
		l1+=ssy[i].size();
	}
	for(int i=1;i<=tt;i++)
	{
		cin>>sx[i]>>sy[i];
		l2+=sx[i].size();
		l2+=sy[i].size();
	}
	if(max(l1,l2)<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			string x=ssx[i],y=ssy[i];
			mp[hsh(x)]=hsh(y);
		}
		for(int i=1;i<=tt;i++)
		{
			int ans=0;
			string x=sx[i],y=sy[i];
			if(x.size()!=y.size())
			{
				cout<<0<<endl;
				continue;
			}
			int t=x.size(),tar=(hsh(y)+mod-hsh(x))%mod;
			init(x);
			for(int i=1;i<=t;i++)
			{
				for(int j=i;j<=t;j++)
				{
					int os=h(i,j);
					if(!mp.count(os)) continue;
					if((mp[os]+mod-os)%mod*b[t-j]%mod==tar)
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		int d=N-10;
		for(int i=1;i<=n;i++)
		{
			string x=ssx[i],y=ssy[i];
			int px=pos(x),py=pos(y);
			g[px-py+d].push_back(make_pair(px-1,x.size()-px));
		}
		for(int i=0;i<=2*d;i++)
		{
			if(g[i].size()==0) continue;
			else
			{
				sort(g[i].begin(),g[i].end());
				int minn=1e12;
				for(auto x:g[i])
				{
					minn=min(minn,x.second);
					m[i].push_back(minn);
				}
			}
		}
		for(int i=1;i<=tt;i++)
		{
			int ans=0;
			string x=sx[i],y=sy[i];
			if(x.size()!=y.size())
			{
				cout<<0<<endl;
				continue;
			}
			int t=x.size(),px=pos(x),py=pos(y);
			int dx=px-py+d;
			if(g[dx].size()==0) continue;
			if(px-1>g[dx][g[dx].size()-1].first) continue;
			auto pt=lower_bound(g[dx].begin(),g[dx].end(),make_pair(px,0ll))-g[dx].begin()-1;
			if(pt<0) continue;
//			if(f[dx][min(pt,dx.size()-1)]<=t-px) continue;
//			int pt=upper_bound(g[px-py+d].upper_bound(make_pair(1,0));
		}
		
	}
	return 0;
}

