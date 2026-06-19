#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int s[500005];
unordered_map<int,priority_queue<int>>mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		s[i]=a[i]^s[i+1];
		mp[s[i]].push(i);
	}
	int last=n+1,now=k;
	for(int i=n;i>=1;i--)
	{
		if(mp.count(now))
		{
			auto it=mp[now];
			if(!it.empty())
			{
				if(i<last)
				{
					ans++;
					last=it.top();
				}
				else
				{
					if(it.top()>last)last=it.top();
				}
			}
		}
		now^=a[i];
		mp[s[i]].pop();
	}
	cout<<ans<<endl;
	return 0;
}
