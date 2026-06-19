#include<bits/stdc++.h>
using namespace std;

int n;
bool pokers[20][20] = {0};

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		char a, b; // a是点数，b是花色 
		cin>>b>>a;
		int x, y;
		if(a == 'A') x = 1;
		else if(a == 'T') x = 10;
		else if(a == 'J') x = 11;
		else if(a == 'Q') x = 12;
		else if(a == 'K') x = 13;
		else x = a - '0';
		if(b == 'D') y = 1;
		else if(b == 'C') y = 2;
		else if(b == 'H') y = 3;
		else if(b == 'S') y = 4;
		pokers[x][y] = 1; // 横是点数，纵是花色 
	}
	int ans = 0;
	for(int i = 1; i <= 13; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(pokers[i][j] == 0) ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
