#include<iostream>
using namespace std;
#define int long long
int P=31;
int n,q;
int mod=1e9+7;
int p[100010],q1[100010];
int t1[100010],t2[100010];
int fr[100010];
int n1[100010],n2[100010];
int sz[100010];
int Hash(string s,int q[])
{
	p[0]=1;
	for(int i=1;i<s.size();i++)
	{
		p[i]=p[i-1]*P%mod;
		q[i]=(q[i-1]*P+s[i]-'a')%mod;
	}
	int e=s.size()-1;
	return q[e];
}
int sub(int l,int r,int t[])
{
	return (t[r]-t[l-1]%mod*p[r-l+1]%mod+mod)%mod;
}
int a[100010];
void solve()
{
	string st1,st2;
	cin>>st1>>st2;
	st1=" "+st1;
	st2=" "+st2;
	Hash(st1,t1);
	Hash(st2,t2);
	int fron=0;
	for(int i=1;i<st1.size();i++)
	{
		if(st1[i]==st2[i])	fron=i;
		else	break;
	}
	int minus=t1[st1.size()-1]-t2[st2.size()-1];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(fron-fr[i]+1<=0 || fron-fr[i]+sz[i]>st1.size()-1)	continue;
		if(sub(fron-fr[i]+1,fron-fr[i]+sz[i],t1)==n1[i] && sub(fron-fr[i]+1,fron-fr[i]+sz[i],t2)==n2[i] && sub(fron-fr[i]+sz[i]+1,st1.size()-1,t1)==sub(fron-fr[i]+sz[i]+1,st1.size()-1,t2))	ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int x=1;x<=n;x++)
	{
		string s1,s2;
		cin>>s1>>s2;
		sz[x]=s1.size();
		s1=" "+s1;
		s2=" "+s2;
		for(int i=1;i<=sz[x];i++)
		{
			if(s1[i]==s2[i])	fr[x]=i;
			else break;
		}
		n1[x]=Hash(s1,q1);
		n2[x]=Hash(s2,q1);
	}
	for(int i=1;i<=q;i++)
	{
		solve();
	}
	return 0;
 } 
