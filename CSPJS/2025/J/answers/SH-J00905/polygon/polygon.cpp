#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int stick[5010];


int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> stick[i];
	}
	int maxn = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		maxn = max(maxn, stick[i]);
		sum += stick[i];
	}
	if(sum > maxn * 2) cout << 1;
	else cout << 0;
	return 0;
}
