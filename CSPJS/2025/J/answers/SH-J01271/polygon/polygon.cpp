#include <bits/stdc++.h>
using namespace std;
int n,num;
int a[10000];
bool b[10000];
long long cnt;
bool judge()
{
	int sum = 0,summ = 0,summax = 0;
	for(int i = 1;i <= n;i++)
	{
		if(b[i])
		{
			sum += a[i];
			summ++;
			summax = i;
		}
	}
	if (sum > 2 * a[summax] and summ > 2)
	{
		return true;
	}
	return false;
}
void count()
{
	num++;
	if(num > n)
	{
		if(judge())
		{
			cnt++;
		}
		num--;
		return;
	}
	b[num] = true;
	count();
	b[num] = false;
	count();
	num--;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	count();
	cout << cnt % 998244353;
	return 0;
}
