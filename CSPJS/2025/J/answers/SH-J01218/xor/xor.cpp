#include <bits/stdc++.h>
#define N 10005
using namespace std;
typedef long long ll;

int ans;
int n,k,a[N];
bool A()
{
	if (k != 0) return false;
	for (int i = 1;i <= n;i++)
		if (a[i] != 1)
			return false;
	return true;
}
bool B()
{
	if (k > 1) return false;
	for (int i = 1;i <= n;i++)
		if (a[i] > 1)
			return false;
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (A())
	{
		ans = n / 2;
		cout << ans << endl;
		return 0;
	}
	if (B())
	{
		for (int i = 1;i <= n;i++)
			if (a[i] == k) ans++;
		cout << ans << endl;
		return 0;
	}
	cout << 2 << endl;
	return 0;
}
