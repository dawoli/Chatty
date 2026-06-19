#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int s[N];
struct Node {
	int l,r;
} length[N];
bool cmp (Node x, Node y)
{
	return x.l < y.l;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k;
	cin>>n>>k;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int cnt = 0;
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			if (s[r] ^ s[l - 1] == k)
			{
				++cnt;
				length[cnt].l = l;
				length[cnt].r = r;
			}
		}
	}
	sort(length + 1, length + cnt + 1, cmp);
	int last = 0;
	int ans = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (last < length[i].l)
		{
			ans++;
			last = length[i].r;
		}
	}
	cout<<ans;
	return 0;
}
