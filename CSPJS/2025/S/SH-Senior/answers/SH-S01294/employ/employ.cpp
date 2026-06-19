#include <bits/stdc++.h>
#define singletest
// #define debugging
using namespace std;
int n,m;
string s;
int patient[100010];
class ProvedSolution
{
	public:
	vector<int> v;
	void getarray()
	{
		for(int i=0;i<n;i++) v.push_back(i);
	}
	int solve()
	{
		int ans=0;
		do
		{
			int cnt=n,unem=0;
			//cout<<"arr:";
			//for(auto i:v) cout<<i;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='0') unem++,cnt--;
				else if (unem>=patient[v[i]]) unem++,cnt--;
			}
			if(cnt>=m) ans++,n%=998'244'353;
			//cout<<endl;
		}while(next_permutation(v.begin(),v.end()));
		return ans;
	}
	int entry()
	{
		getarray();
		return solve();
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
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>patient[i];
	cout<<ProvedSolution().entry();
}
int main()
{
	#ifndef debugging
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
}
