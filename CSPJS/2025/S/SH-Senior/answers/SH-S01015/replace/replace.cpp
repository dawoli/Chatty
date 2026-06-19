#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,q,v=2,ans,inf=1e18;
ull hs[2005][2],qp[2005];
ull h[2005],hh[2005];
ll z=1e18,y=0;
string ss,s;
map<ull,ull> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	qp[0]=1;
	for(int i=1;i<=2000;i++) qp[i]=qp[i-1]*37;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>ss;
		for(int j=0;j<s.size();j++)
		{
			hs[i][0]=hs[i][0]*37+s[j]-'a'+1;
			hs[i][1]=hs[i][1]*37+ss[j]-'a'+1;
		}
		mp[hs[i][0]]=hs[i][1];
	}
	while(q--)
	{
		cin>>s>>ss;
		ans=0;
		z=inf,y=0;
		if(ss.size()!=s.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(ll i=0;i<s.size();i++)
			if(s[i]!=ss[i]) z=min(z,i),y=max(y,i);
		for(int i=0;i<s.size();i++) h[i+1]=h[i]*37+s[i]-'a'+1;
		for(int i=0;i<s.size();i++) hh[i+1]=hh[i]*37+ss[i]-'a'+1;
		for(int i=y;i<s.size();i++)
			for(int j=-1;j<z;j++)
			{
				if(mp.count(h[i+1]-h[j+1]*qp[i-j]))
				{
					if(hh[i+1]-hh[j+1]*qp[i-j]==mp[h[i+1]-h[j+1]*qp[i-j]]) ans++;
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
