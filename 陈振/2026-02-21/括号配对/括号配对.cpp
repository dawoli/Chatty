// Problem URL: E:\编程\C++\陈振\2026-02-21\括号配对\题面.png
// Finish Time: 2026/2/23 18:39:13 WA
// Finish Time: 2026/2/23 17:25:51 WA
// Start Time: 2026/2/23 16:45:57

// Categories: 动态规划
#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
typedef long long int ll;
string s;
int n,ans=0;
stack<int> k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('||s[i]=='[')
		{
			k.push(i);
		}
		else
		{
			if(!k.empty()&&((s[i]==')'&&s[k.top()]=='(')||(s[i]==']'&&s[k.top()]=='[')))
				k.pop();
			else
				ans++;
		}
	}
	ans+=k.size();
	cout<<ans;
	return 0;
}