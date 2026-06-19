#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+5;

struct Stg
{
	ll l,r;
};

bool operator<(Stg a,Stg b)
{
	return a.l<b.l;
}

ll n,q,ls[N],rs[N],cs[N],lt[N],rt[N],ct[N];
set<Stg> s;
string a,b;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1,x,y,z;i<=n;i++)
	{
		cin>>a>>b;
		ll na=a.size()-1;
		ll nb=b.size()-1;
		x=0;
		while(a[x]!=b)
		{
			x++;
		}
		y=x;
		ls[i]=y-1;
		rs[i]=na-y;
		x=0;
		while(b[x]!=b)
		{
			x++;
		}
		z=x;
		cs[i]=y-z;
	}
	for(int i=1,x,y,z;i<=q;i++)
	{
		cin>>a>>b;
		ll na=a.size()-1;
		ll nb=b.size()-1;
		x=0;
		while(a[x]!=b)
		{
			x++;
		}
		y=x;
		lt[i]=y-1;
		rt[i]=na-y;
		x=0;
		while(b[x]!=b)
		{
			x++;
		}
		z=x;
		cs[i]=y-z;
	}
	return 0;
}
