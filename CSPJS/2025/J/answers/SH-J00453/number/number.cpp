#include<bits/stdc++.h>
using namespace std; 

const int N = 1000005;
string s;
int a[N];
char t[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> s;
	int l = s.size(), cnt = 0;
	for(int i = 0; i < l; ++i)
	{
		char c = s[i];
		if(48 <= c && c <= 57) a[++cnt] = c - 48;
	}
	sort(a + 1, a + cnt + 1);
	if(a[cnt] == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = cnt; i > 0; --i)
	{
		int j = cnt - i;
		t[j] = a[i] + 48;
	}
	cout << t;
}
