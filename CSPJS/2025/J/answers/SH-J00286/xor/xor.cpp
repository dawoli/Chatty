#include<bits/stdc++.h>
using namespace std;

const int _  = 5e5 + 9;
int n, k, a[_];
bool f(int x)
{
	int sum = 0, cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		sum ^= a[i];
		if(sum == k)
			sum = 0, cnt++;
	}
	return cnt >= x;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int L = 0, R = n + 1;
	while(R - L > 1)
	{
		int mid = (L + R) / 2;
		if(f(mid))
			L = mid;
		else
			R = mid;
	}
	cout << L;
	
	return 0;
}
