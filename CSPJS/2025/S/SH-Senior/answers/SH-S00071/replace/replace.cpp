#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
string s1[202020],s2[202020],t1[202020],t2[202020];
bool check(string s)
{
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='b') cnt++;
		else if(s[i]!='a') return 0;
	}
	return (cnt==1);
}
struct node{
	int posl,posr,delta;
}t[202020];
vector<node>g[2020202];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=0;j<s1[i].size();j++) if(s1[i][j]=='b') pos=j;
		t[i].posl=pos,t[i].posr=s1[i].size()-pos+1;
		for(int j=0;j<s2[i].size();j++) if(s2[i][j]=='b') t[i].delta=j-pos;
		g[t[i].delta+1000000].push_back({t[i].posl,t[i].posr,t[i].delta});
	}
	for(int i=1;i<=q;i++)
	{
		int pos=0,d=0;
		for(int j=0;j<t1[i].size();j++) if(t1[i][j]=='b') pos=j;
		for(int j=0;j<t2[i].size();j++) if(t2[i][j]=='b') d=j-pos;
		int ans=0;
		for(auto tmp:g[d+1000000]) if(pos>=tmp.posl&&t1[i].size()-pos+1>=tmp.posr) ans++;
		if(t1[i].size()!=t2[i].size()) cout<<"0\n";
		else cout<<ans<<endl;
	}
}
void solve2()
{
	for(int h=1;h<=q;h++)
	{
		if(t1[h].size()!=t2[h].size())
		{
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+s1[i].size()-1<t1[h].size();j++)
			{
				if(t1[h].substr(j,s1[i].size())==s1[i])
				{
					string s0=t1[h].substr(0,j)+s2[i]+t1[h].substr(j+s1[i].size(),t1[h].size()-j-s1[i].size());
					if(s0==t2[h]) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(!check(s1[i])||!check(s2[i])) flag=0;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		if(!check(t1[i])||!check(t2[i])) flag=0;
	}
	if(flag) solve1();
	else solve2();
	return 0;
}

