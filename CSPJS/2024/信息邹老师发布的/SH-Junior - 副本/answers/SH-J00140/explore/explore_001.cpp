#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,e = 0;
string w[1005];
int df[4][2] = {{0,1},
				{1,0},
				{0,-1},
				{-1,0}};
bool fff[1005][1005];
int h(int x,int y,int d,int u)
{
	if(u == 0)
	{
		return e;
	}
	if(x + df[d][0] > n || (y + df[d][1] > n) || (x + df[d][0] < 1) || y + df[d][1] < 1 || (w[x + df[d][0]][y + df[d][1]] == 'x'))
	{
		u--;
		return h(x,y,(d + 1) % 4,u - 1);
	}
	else
	{
		if(fff[x][y] == 0)
		{
			fff[x][y] = 1;
			u--;
			e++;
			return h(x + df[d][0],y + df[d][1],d,u - 1);
		}
		else
		{
			u--;
			return h(x + df[d][0],y + df[d][1],d,u - 1);
		}
	}
}

void em()
{
	for(int i = 1; i <= n; i++)
	{
		w[i] = "";
	}
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for(int j = 1; j <= n; j++)
		{
			cin >> w[j];
		}
		if(k == 1)
		{
			if(w[x + df[d][0]][y + df[d][1]] == 'x')
			{
				cout << 1 << endl;
			}
			else if(x + df[d][0] > n || y + df[d][1] > n || x + df[d][0] < 1 || y + df[d][1] < 1)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
		}
		em();
	}
	return 0;
}
