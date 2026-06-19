#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
const ll mod=1000000007,P=13331;
const ll N=200005,M=5000005;
struct node
{
	ll h1,h2,siz;
} a[N];
ll n,q,p[M];
string in;
string u,v;
ll h1[M],h2[M],m,l,r,ans;
ll get1(ll l,ll r)
{
	return (h1[r]-h1[l-1]*p[r-l+1]);
}
ll get2(ll l,ll r)
{
	return (h2[r]-h2[l-1]*p[r-l+1]);
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();p[0]=1;
	for(int i=1;i<=5000000;++i) p[i]=p[i-1]*P;
	for(int i=1;i<=n;++i)
	{
		cin>>u>>v;
		a[i].h1=a[i].h2=0;a[i].siz=u.size();
		for(int j=0;j<a[i].siz;++j)
		{
			a[i].h1=a[i].h1*P+u[j];
			a[i].h2=a[i].h2*P+v[j];
		}
//		cout<<a[i].h1<<' '<<a[i].h2<<"\n";
	}
	while(q--)
	{
		cin>>u>>v;m=u.size();
		if(u.size()!=v.size())
		{
			cout<<"0\n";
			continue;
		}
		h1[0]=h2[0]=0;
		for(int i=1;i<=m;++i) h1[i]=h1[i-1]*P+u[i-1],
							  h2[i]=h2[i-1]*P+v[i-1];
//		for(int i=1;i<=m;++i) cout<<h1[i]<<" ";cout<<"\n";cout<<get1(3,4)<<" ";cout<<a[3].h1<<' '<<a[3].h1*p[2]<<"\n";
		ans=0;
		for(int i=0;i<=m;++i)
		{
			if(h1[i]!=h2[i]) break;
			for(int j=1;j<=n;++j)
			{
				int len=a[j].siz;
//				cout<<i<<" "<<j<<"\n";
				if(i+len>m) continue;
//				cout<<"ok1";
				if(a[j].h1!=get1(i+1,i+len)) continue;
//				cout<<"ok2";
				if(a[j].h2!=get2(i+1,i+len)) continue;
//				cout<<"ok3";
				if(i+len>m||get1(i+len+1,m)!=get2(i+len+1,m)) continue;
				++ans;
//				cout<<i<<" "<<j<<"\n";
			}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}
