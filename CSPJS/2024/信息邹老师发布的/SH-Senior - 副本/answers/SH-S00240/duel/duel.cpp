#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
queue<int>q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		if(!q.empty()&&q.front()<r[i])q.pop();
		q.push(r[i]);
	}
	cout<<q.size()<<endl;
	return 0;
}
