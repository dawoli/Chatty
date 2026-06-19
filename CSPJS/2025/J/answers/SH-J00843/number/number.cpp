#include<bits/stdc++.h>
using namespace std;

string s;
long long a[1000010], cnt = 0;

bool cmp(long long x, long long y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(long long i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[i] = int(s[i] - '0');
			cnt++;
		}
	}
	sort(a, a + s.size(), cmp);
	for(long long i = 0; i < cnt; i++)
	{
		cout << a[i];
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
