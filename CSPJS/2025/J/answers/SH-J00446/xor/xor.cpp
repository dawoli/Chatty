#include<iostream>
#include<cstring>
using namespace std;
int a[500005] , f[500005] , pos[1 << 20];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k; cin >> n >> k;
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	memset(pos , -1 , sizeof(pos));
	pos[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] ^= a[i - 1];
		f[i] = f[i - 1];
		if (pos[a[i] ^ k] != -1) f[i] = max(f[i] , f[pos[a[i] ^ k]] + 1);
		pos[a[i]] = i;
	}
	cout << f[n];
	return 0;
}
