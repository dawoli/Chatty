#include <bits/stdc++.h>
#define singletest
using namespace std;
string s;
class ProvedSolution
{
	public:
	static bool cmp(char a,char b)
	{
		return a>b;
	}
	string mainentry()
	{
		sort(s.begin(),s.end(),cmp);
		return s;
	}
};
class Solution
{
	public:
	void mainentry()
	{
		
	}
};

void init()
{
	s="";
}
void solve()
{
	init();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]>='0'&&s[i]<='9')) s.erase(i,1),i--;
	} 
	cout<<ProvedSolution().mainentry();
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
	return 0;
}
