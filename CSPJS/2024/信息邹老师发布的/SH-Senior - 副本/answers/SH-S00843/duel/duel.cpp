#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
int a[N];

int main()
{
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int b;
		scanf("%d" , &b);
		a[b]++;
	}
	long long res = 0;
	for(int i = 1;i < N;i++)
	{
		if(!a[i]) continue;
		res = max(res , (long long)a[i]);
	}
	cout << res;
	return 0;
 } 
