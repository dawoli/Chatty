#include<bits/stdc++.h>
using namespace std;
string s;
long long sum[10], ans;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long sl = s.size();
	for(int i = 0; i < sl; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			sum[s[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= sum[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
