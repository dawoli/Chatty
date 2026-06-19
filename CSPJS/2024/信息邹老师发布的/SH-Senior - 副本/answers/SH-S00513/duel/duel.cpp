#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x < y;
}
int a[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	int cnt1 = 0,cnt2 = 1;
	for (int i = 2; i <= n; i ++)
	{
		if (a[i] == a[i - 1])
		{
			cnt2 ++;
			if (cnt1 != 0)
			cnt1 --;
		}
		else
		{
			cnt1 += cnt2;
			cnt2 = 1;
			if (cnt1 != 0)
			cnt1 --;
		}
	}
	cout << cnt1 + cnt2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
