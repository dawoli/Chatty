#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[1000010];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt++;
			num[cnt] = s[i] - '0';
		}
	} 
	sort(num + 1, num + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++)
	{
		cout << num[i];
	}
	return 0;
} 
