#include <iostream>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[500010];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	int last = 0;
	for (int i = 1;i <= n;i++)
	{
		last = (last xor a[i]);
		if (last == k)
		{
			cnt++;
			last = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}
