#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char c[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt++;
			c[cnt] = s[i];
		}
	}
	sort(c + 1,c + cnt + 1);
	for(int i = cnt;i >= 1;i--)
	{
		cout << c[i];
	}
	return 0;
 } 
