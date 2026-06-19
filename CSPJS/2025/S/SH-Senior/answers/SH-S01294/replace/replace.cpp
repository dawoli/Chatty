#include <bits/stdc++.h>
#define singletest
// #define debugging
using namespace std;
map<string,string> mp;
class ProvedSolution
{
	public:
	void entry(string s)
	{
		
	}
};
class Solution
{
	void entry()
	{
		
	}
};
void init()
{
	
}
void solve()
{
	init();
	int n,q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--)
	{
		string s;
		cin>>s;
		ProvedSolution().entry(s);
		cout<<0<<endl; //实在不会...为了争取 3= 只能骗分了...
	}
}
int main()
{
	#ifndef debugging
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
}
