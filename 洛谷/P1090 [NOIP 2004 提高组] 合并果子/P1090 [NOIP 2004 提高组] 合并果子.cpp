#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
int n;
ull ans=0;
priority_queue<ull,vector<ull>,greater<> > q;
signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	while (q.size()>1)
	{
		const int a=q.top();
		q.pop();
		const int b=q.top();
		q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
}