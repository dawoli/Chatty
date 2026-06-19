#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
struct state
{
	int cnt,exp;
	double pior;
	state(int a=0,int b=1): cnt(a),exp(b)
	{
		int temp_cnt=0;
		double temp_exp=b;
		while(temp_exp<=n)
		{
			temp_exp*=2;
			temp_cnt++;
		}
		pior=(temp_cnt+3)*0.8+cnt*0.2;
	}
	bool operator<(const state &s) const
	{
		return pior<s.pior;
	}
};
priority_queue<state> q;
unordered_set<int> vis;
vector<int> u(1,1);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(true)
	{
		cin>>n;
		if(n==0) break;
		if(n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		while(!q.empty()) q.pop();
		u.resize(1,1);
		vis.clear();
		q.push(state());
		vis.insert(1);
		while(!q.empty())
		{
			state s=q.top();
			q.pop();
			if(s.exp==n)
			{
				cout<<s.cnt<<'\n';
				break;
			}
			for(int i=0; i<u.size(); i++)
			{
				int t=s.exp+u[i];
				if(t>n)t-=2*u[i];
				if(t>0&&vis.find(t)==vis.end())
				{
					q.push(state(s.cnt+1,t));
					vis.insert(t);
				}
			}
			u.push_back(s.exp);
		}
	}
	return 0;
}