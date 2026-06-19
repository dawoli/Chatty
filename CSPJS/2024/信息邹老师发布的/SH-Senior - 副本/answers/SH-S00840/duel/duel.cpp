#include<bits/stdc++.h>
using namespace std;
int a[100001];
int sum[100001];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,maxn=0,maxx=0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
		maxx=max(maxx,x);
	}
	for(int i = 1; i <= maxx; i++)
	{
		maxn=max(maxn,a[i]);
	}
	cout << maxn;
}
