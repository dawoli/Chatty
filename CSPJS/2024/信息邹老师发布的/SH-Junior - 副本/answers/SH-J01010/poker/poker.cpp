#include<bits/stdc++.h>
using namespace std;
int poker[15][10];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if(s[0] == 'D')
		{
			if(s[1] == 'A') poker[1][1]++;
			if('2' <= s[1] && s[1] <= '9') poker[s[1] - '0'][1]++; 
			if(s[1] == 'T') poker[10][1]++;
			if(s[1] == 'J') poker[11][1]++;
			if(s[1] == 'Q') poker[12][1]++;
			if(s[1] == 'K') poker[13][1]++;
		}
		if(s[0] == 'C')
		{
			if(s[1] == 'A') poker[1][2]++;
			if('2' <= s[1] && s[1] <= '9') poker[s[1] - '0'][2]++; 
			if(s[1] == 'T') poker[10][2]++;
			if(s[1] == 'J') poker[11][2]++;
			if(s[1] == 'Q') poker[12][2]++;
			if(s[1] == 'K') poker[13][2]++;
		}
		if(s[0] == 'H')
		{
			if(s[1] == 'A') poker[1][3]++;
			if('2' <= s[1] && s[1] <= '9') poker[s[1] - '0'][3]++; 
			if(s[1] == 'T') poker[10][3]++;
			if(s[1] == 'J') poker[11][3]++;
			if(s[1] == 'Q') poker[12][3]++;
			if(s[1] == 'K') poker[13][3]++;
		}
		if(s[0] == 'S')
		{
			if(s[1] == 'A') poker[1][4]++;
			if('2' <= s[1] && s[1] <= '9') poker[s[1] - '0'][4]++; 
			if(s[1] == 'T') poker[10][4]++;
			if(s[1] == 'J') poker[11][4]++;
			if(s[1] == 'Q') poker[12][4]++;
			if(s[1] == 'K') poker[13][4]++;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= 13; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(poker[i][j] < 1) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
} 
