#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i] - '0';
		if (0 <= n && n <= 9)
		{
			a[++cnt] = n;
		}
	}
	sort(a + 1, a + cnt + 1, greater<int>());
	for (int i = 1; i <= cnt; i++)
	{
		cout<<a[i];
	}
	return 0;
} 
