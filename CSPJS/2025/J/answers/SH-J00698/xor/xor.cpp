#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt = 0;
	cin >> n >> k;
	vector<int> a(n,0);
	for (int i = 0;i < n;++i)
		for (int j = i;j < n;++j)
		{
			int t = i;
			for (int l = i + 1;l <= j;++l)
				t ^= a[l];
			if (t == k)
				++cnt;
		}
	cout << cnt << endl;
	return 0;
}
