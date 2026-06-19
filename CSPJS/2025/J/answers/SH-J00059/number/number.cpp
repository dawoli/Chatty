#include<bits/stdc++.h>
using namespace std;
string s;
int c[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(isdigit(s[i]))c[s[i]-'0']++;
	}
	for(int i = 9; i >= 0; i--)
		while(c[i]>0)
		{
			cout << i;
			c[i]--;
		}
	return 0;
}
