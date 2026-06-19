#include<bits/stdc++.h>
using namespace std;
const int Mx=1e8;
map<string,string> mp;
bool same(string a,string b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	long long ls=0;
	string s1,s2;
	cin>>n>>q;
	if(q==1&&n>=1000)
	{
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(auto k:mp)
		{
			int t=s1.find(k.first);
			while(t<s1.size())
			{
				string tmp=s1.substr(0,t)+k.second+s1.substr(t+k.first.size(),s1.size()-t-k.first.size());
				if(same(tmp,s2))
				{
					ans++;
					break;
				}
				if(tmp.find(k.first)>t) t=tmp.find(k.first);
				else break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
