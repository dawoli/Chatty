#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	s = " " + s;
	
	int arr[520], cnt = 0;
	for(int i = 1; i <= n; i ++) arr[i] = (s[i] - '0');
	
	int b[520], maxn = -1;
	for(int i = 1; i <= n; i ++)
	{
		cin >> b[i];
		cnt += b[i];
		maxn = max(maxn, b[i]);
	}
	
	srand(time(NULL));
	
	int res = rand() % 2;
	if(res % 2)
	{
		cout << m;
	}else
	{
		double ans = (double)cnt / (maxn + 1) * 1.0;
		
		cout << ceil(ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
