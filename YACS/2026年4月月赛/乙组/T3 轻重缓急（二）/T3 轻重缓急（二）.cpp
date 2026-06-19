// Problem URL: https://iai.sh.cn/problem/999
// Finish Time: 2026/5/4 19:22:07 AC
// Finish Time: 2026/5/4 18:29:23 WA 30pts
// Finish Time: 2026/5/4 18:26:54 WA 30pts
// Finish Time: 2026/5/4 18:12:37 WA 30pts
// Finish Time: 2026/5/4 18:06:50 WA 30pts
// Finish Time: 2026/5/4 18:01:06 WA 10pts
// Start Time: 2026/5/4 17:52:53

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
		cin>>j[i].end>>j[i].time;
		j[i].end+=j[i].time;
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
	cout<<q.size()<<'\n';
	/*
	while(!q.empty())
	{
		cout<<q.top().end<<' '<<q.top().time<<'\n';
		q.pop();
	}
	*/
	return 0;
}