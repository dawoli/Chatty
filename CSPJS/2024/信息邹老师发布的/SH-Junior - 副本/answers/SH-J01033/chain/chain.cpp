#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x,k,q;
		cin >> x >> k >> q;
		for (int i = 1; i <= q; i++) cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
