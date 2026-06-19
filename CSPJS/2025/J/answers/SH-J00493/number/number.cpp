#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10] = {0}; // 代表0-9各有多少个数字 
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin>>s;
	for(int i = 0; i < s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			cnt[s[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= cnt[i]; j++) cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
