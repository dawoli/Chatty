#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node {
	string s,t;
} a[N], b[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n,q;
	cin>>n>>q;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i].s>>a[i].t;
	}
	for (int i = 1; i <= q; i++)
	{
		cin>>b[i].s>>b[i].t;
	}
	return 0;
}
