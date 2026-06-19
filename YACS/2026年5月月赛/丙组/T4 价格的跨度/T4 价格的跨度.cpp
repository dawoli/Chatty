#include <bits/stdc++.h>
using namespace std;
int a[1000005],span[1000005];
int stk[1000005],top;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; ++i)
	{
		while(top>0&&a[stk[top]]<=a[i])
		{
			--top;
		}
		span[i]=(top==0)?i:i-stk[top];
		stk[++top]=i;
	}
	for(int i=1; i<=n; ++i)
	{
		cout<<span[i]<<'\n';
	}
	return 0;
}