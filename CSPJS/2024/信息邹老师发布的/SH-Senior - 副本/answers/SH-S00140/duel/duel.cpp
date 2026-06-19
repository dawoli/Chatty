#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool sd[100005];

int con(int x,int n)
{
	int r = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == x)
		{
			r++;
		}
	}
	return r;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int u;
	cin >> u;
	for(int i = 1; i <= u; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + u + 1);
	if(a[u] <= 2)
	{
		if(con(1,u) <= con(2,u))
		{
			cout << con(2,u);
		}
		else
		{
			cout << con(1,u);
		}
	}
	else cout << 1;
	return 0;
}
/*
freopen(".in","r",stdin);
	freopen(".out","w",stdout);
*/
