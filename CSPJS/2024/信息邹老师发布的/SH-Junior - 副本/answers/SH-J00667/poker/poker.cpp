#include<bits/stdc++.h>
using namespace std;

int n = 0,cnt = 52;
string poke;
bool vis[6][20] = {false};

int to_int(char s)
{
	if(s == '1')return 1;
	if(s == '2')return 2;
	if(s == '3')return 3;
	if(s == '4')return 4;
	if(s == '5')return 5;
	if(s == '6')return 6;
	if(s == '7')return 7;
	if(s == '8')return 8;
	if(s == '9')return 9;
} 

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i ++)
	{
		cin>>poke;
		if(poke[0] == 'D')
		{
			if(poke[1] == 'T')vis[0][10] = true;
			else if(poke[1] == 'A')vis[0][1] = true;
			else if(poke[1] == 'J')vis[0][11] = true;
			else if(poke[1] == 'Q')vis[0][12] = true;
			else if(poke[1] == 'K')vis[0][13] = true;
			else vis[0][to_int(poke[1])] = true;
		}
		else if(poke[0] == 'C')
		{
			if(poke[1] == 'T')vis[1][10] = true;
			else if(poke[1] == 'A')vis[1][1] = true;
			else if(poke[1] == 'J')vis[1][11] = true;
			else if(poke[1] == 'Q')vis[1][12] = true;
			else if(poke[1] == 'K')vis[1][13] = true;
			else vis[1][to_int(poke[1])] = true;
		}
		else if(poke[0] == 'H')
		{
			if(poke[1] == 'T')vis[2][10] = true;
			else if(poke[1] == 'A')vis[2][1] = true;
			else if(poke[1] == 'J')vis[2][11] = true;
			else if(poke[1] == 'Q')vis[2][12] = true;
			else if(poke[1] == 'K')vis[2][13] = true;
			else vis[2][to_int(poke[1])] = true;
		}
		else if(poke[0] == 'S')
		{
			if(poke[1] == 'T')vis[3][10] = true;
			else if(poke[1] == 'A')vis[3][1] = true;
			else if(poke[1] == 'J')vis[3][11] = true;
			else if(poke[1] == 'Q')vis[3][12] = true;
			else if(poke[1] == 'K')vis[3][13] = true;
			else vis[3][to_int(poke[1])] = true;
		}
	}
	for(int i = 0;i < 4;i ++)
	{
		for(int j = 1;j <= 13;j ++)
		{
			if(vis[i][j] == true)cnt --;
		}
	}
	cout<<cnt;
	fclose(stdin); 
	fclose(stdout);
	return 0;
} 
