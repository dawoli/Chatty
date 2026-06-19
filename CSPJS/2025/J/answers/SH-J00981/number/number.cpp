#include <bits/stdc++.h>
using namespace std;
string a;
int s[1000005], cnt;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] <= '9' && a[i] >= '0')
		{
			cnt++;
			s[cnt] = a[i]-'0';
		}
	}
	sort(s+1, s+cnt+1);
	if(s[cnt] == 0)
	{
		cout << 0 << endl;
		return 0; 
	}
	for(int i = cnt; i >= 1; i--) cout << s[i];
	return 0;
}
