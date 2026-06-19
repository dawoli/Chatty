#include <iostream>
using namespace std;

int a[500010];
int s[500010];

struct node
{
	int cnt, last;
}f[500010];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = (s[i - 1] ^ a[i]);
	}
	f[1].cnt = (a[1] == k? 1:0);
	f[1].last = (a[1] == k? 1:0);
	for(int i = 2; i <= n; i++)
	{
		f[i].last = f[i - 1].last;
		f[i].cnt = f[i - 1].cnt;
		for(int x = f[i].last + 1; x <= i; x++)
		{
			if((s[x - 1] ^ s[i]) == k)
			{
				f[i].cnt++;
				f[i].last = i;
				break;
			}
		}
	}
	cout << f[n].cnt << endl;
	return 0;
}
