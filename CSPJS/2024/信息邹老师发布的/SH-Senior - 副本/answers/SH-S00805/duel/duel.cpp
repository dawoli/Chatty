#include <bits/stdc++.h>
using namespace std;
int n,r[100005],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >>  r[i];
	}
	sort(r+1,r+n+1);
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!q.empty()&&q.front()<r[i])
		{
			q.pop();
			q.push(r[i]);
		}
		else
		{
			q.push(r[i]);
		}
	}
	cout << q.size();
	return 0;
}
