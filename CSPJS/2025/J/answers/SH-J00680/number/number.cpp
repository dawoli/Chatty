#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt =0;
	for(int i = 1;i <= 10;i++)
	{
		if(s[i]=='a')
		cnt++;
	}
	cout << cnt+5;
	return 0;
}
