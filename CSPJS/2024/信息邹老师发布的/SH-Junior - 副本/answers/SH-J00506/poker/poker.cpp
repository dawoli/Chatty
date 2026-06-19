#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,cnt;
string s;
map<string,bool> ls; 
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		if (!ls[s]) cnt++;
		ls[s] = 1;
	}
	cout << 52 - cnt;
	return 0;
}
