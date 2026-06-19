#include <iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int now = n - 1;
	int result = n;
	for (int i = n; i; i--)
	{
		while (now && a[now] == a[i])
		{
			now--;
		}
		if (now)
		{
			result--;
			now--;
		}
	}
	cout<<result; 
}
