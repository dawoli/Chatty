// Problem URL: https://www.luogu.com.cn/problem/P4053
// Finish Time: 2026/5/5 16:46:17 AC
// Start Time: 2026/5/5 16:45:03

#include <bits/stdc++.h>
#define end first
#define time second
#define int long long
using namespace std;
int n,nt=0;
pair<int,int> j[300005];
priority_queue<int> q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>j[i].time>>j[i].end;
	}
	sort(j+1,j+n+1);
	for(int i=1;i<=n;i++)
	{
		nt+=j[i].time;
		q.push(j[i].time);
		if(nt>j[i].end)
		{
			nt-=q.top();
			q.pop();
		}
	}
	cout<<q.size();
	return 0;
}