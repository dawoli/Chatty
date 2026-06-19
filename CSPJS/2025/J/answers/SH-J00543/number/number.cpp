#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
using namespace std;
string str;
int p[1000006], num;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for(ui i = 0; i < str.length(); i++)
		if(str[i] >= '0' && str[i] <= '9')
			p[++num] = str[i] - '0';
	sort(p + 1, p + num + 1);
	for(int i = num; i >= 1; i--)
		cout << p[i];
	return 0;
}
//please put me on the QIPADASHANG (LG UID: 1029108)
//100pts
