// Problem URL: https://www.luogu.com.cn/problem/P2294
// Finish Time: 2026/5/16 20:55:40 AC
// Start Time: 2026/5/16 20:32:36

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	int s,t,u;
	bool operator<(const node &a)const
	{
		if(s==a.s)return t>a.t;
		return s>a.s;
	}
}a;
int w,n,m;
priority_queue<node> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>w;
	while(w--)
	{
		cin>>n>>m;
		while(!q.empty())q.pop();
		for(int i=1;i<=m;i++)
		{
			cin>>a.s>>a.t>>a.u;
			q.push(a);
		}
		a=q.top();
		q.pop();
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(a.s==t.s)
			{
				if(a.t==t.t)
				{
					if(a.u!=t.u)
					{
						cout<<"false\n";
						goto end;
					}

				}
				else
				{
					if(a.t<t.t)
					{
						a.s=a.t+1;
						a.t=t.t;
						a.u=t.u-a.u;
						q.push(a);
					}
				}
			}
			a=t;
		}
		cout<<"true\n";
	end:;
	}
	return 0;
}