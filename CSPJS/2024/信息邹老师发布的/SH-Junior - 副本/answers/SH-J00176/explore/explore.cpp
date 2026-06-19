#include<bits/stdc++.h>
using namespace std;
bool b[1009][1009], vis[1009][1009];
int n,m,x,y,d,k,t;
int move_x(int x, int d)
{
	if(d == 1)return ++x;
	else if(d == 3)return --x;
	else return x;
}
int move_y(int y, int d)
{
	if(d == 0)return ++y;
	else if(d == 2)return --y;
	else return y;
}
bool move_ok(int x, int y, int d)
{
	return b[move_x(x,d)][move_y(y,d)];
}
char c;
int main()
{
	freopen("explore.in","r",stdin); //chong yi deng jiang
    freopen("explore.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int cnt = 0;
		memset(vis,0,sizeof vis);
		memset(b,0,sizeof b);
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> c;
				if(c == '.')b[i][j]=true;
			}
		}
		if(!vis[x][y])
		{
			cnt++;
		}
		vis[x][y]=true;
		while(k--)
		{
			if(move_ok(x,y,d))
			{
				x=move_x(x,d);
				y=move_y(y,d);
			}
			else d=(d+1)%4;
			if(!vis[x][y])
			{
				cnt++;
			}
			vis[x][y]=true;
		}
		cout << cnt << endl;
	}
	return 0;
}
