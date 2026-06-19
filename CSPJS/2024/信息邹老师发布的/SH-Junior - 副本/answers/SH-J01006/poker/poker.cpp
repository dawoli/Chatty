#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string s;
	cin >> n;
	int ans = 52;
	while(n--)
	{
		cin >> s;
		if(a[s[0]][s[1]] == 0)
		{
			a[s[0]][s[1]] ++;
			ans --;
		}
	}
	cout << ans << endl;
	return 0;
}
