#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool b[1005][1005];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		char tp,nm;
		cin >> tp >> nm;
		if (!b[tp][nm])
		{
			b[tp][nm] = true;
			cnt++;
		}
	}
	cout << 52 - cnt << endl;
	return 0;
}
