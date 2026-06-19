#include<bits/stdc++.h>
using namespace std;
long long n,q;
long long len[1000005];
const long long P=998244353;
using ull=unsigned long long;
using pll=pair<ull,ull>;
map<pll,long long>mp;
ull hsh1[1000005],hsh2[1000005];
string s1[1000005],s2[1000005];
long long tr[1000005][26],tot=0;
long long ls,lt;
void ins(string s,long long pl)
{
	long long now=0;
	for(int i=1;i<=pl;i++)
	{
		if(!tr[now][s[i]-'a'])
		{
			tr[now][s[i]-'a']=++tot;
		}
		now=tr[now][s[i]-'a'];
	}
}
void dfs(long long now)
{
	for(int i=0;i<=25;i++)
	{
		if(tr[now][i])
		{
			dfs(tr[now][i]);
		}
	}
}
void solve()
{
	string s,t;
	cin>>s>>t;
	ls=(long long)s.size(),lt=(long long)t.size();
	s="%"+s,t="@"+t;
	if(ls!=lt)
	{
		cout<<0<<endl;
		return;	
	}
	for(int i=1;i<=ls;i++)
	{
		hsh1[i]=hsh1[i-1]*P+s[i]-'a'+1;
	}
	for(int i=1;i<=lt;i++)
	{
		hsh2[i]=hsh2[i-1]*P+t[i]-'a'+1;
	}
	long long pr=0,sr=n+1;
	for(int i=1;i<=ls;i++)
	{
		if(s[i]!=t[i])
		{
			pr=i-1;
			break;
		}
	}
	for(int i=ls;i>=1;i--)
	{
		if(s[i]!=t[i])
		{
			sr=i+1;
			break;
		}
	}
	if(pr==0)
	{
		cout<<0<<endl;
		return;
	}
	ins(s,ls);
	ins(t,lt);
	long long ans=0;
	for(int i=1;i<=pr;i++)
	{
		ull hs1=0,hs2=0;
		for(int j=i;j<=ls;j++)
		{
			hs1=hs1*P+s[j]-'a'+1;
			hs2=hs2*P+t[j]-'a'+1;
			if(j>=sr-1) ans+=mp[{hs1,hs2}];
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=(long long)s1[i].size();
		s1[i]='$'+s1[i],s2[i]='#'+s2[i];
		ull hs1=0,hs2=0;
		for(int j=1;j<=len[i];j++)
		{
			hs1=hs1*P+s1[i][j]-'a'+1;
			hs2=hs2*P+s2[i][j]-'a'+1;
			mp[{hs1,hs2}]++;
		}
	}
	while(q--)
	{
		solve();
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
