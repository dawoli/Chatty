#include <iostream>
using namespace std;
int n,a[5010],cnt = 0;

void dfs(int p,int sum,int maxn,int num)
{
	if (p > n) return;
	dfs(p+1,sum,maxn,num);
	num++;
	sum += a[p];
	if (a[p] > maxn)
	{
		maxn = a[p];
	}
	if (sum > 2*maxn && num >= 3)
	{
		cnt++;
	}
	dfs(p+1,sum,maxn,num);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(1,0,0,0);
	cout << cnt << endl;
	return 0;
}
