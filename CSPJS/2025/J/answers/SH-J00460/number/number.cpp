#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll d;
ll a[N];
string s;
bool cmp(ll x , ll y)
{
	return x > y;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for (int i = 0 ; i < s.size() ; i ++)
	{
		if (isdigit(s[i]))
		{
			a[++ d] = int(s[i] - 48);
		}
	}
	sort(a + 1 , a + d + 1 , cmp);
	for (int i = 1 ; i <= d ; i ++)
	{
		cout << a[i];
	}
	return 0;
}
