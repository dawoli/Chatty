#include <iostream>
using namespace std;

struct A
{
	char a;
	bool b;
};

void E()
{
	
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int T;
	cin >> T;
	
	int a[T];
	
	for(int i = 0; i < T; i++)
	{
		int n = 0, m = 0, k;
		int x, y, d;
		int num = 0;
		
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		x--;
		y--;
		
		A e[n][m];
	
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> e[i][j].a;
				e[i][j].b = 0;
			}
		}
	
		e[x][y].b = 1;
		num++;
	
		for(int i = 0; i < k; i++)
		{
			if((d == 0 && (y + 1 == m || e[x][y + 1].a == 'x')) || (d == 1 && (x + 1 == n || e[x + 1][y].a == 'x')) || (d == 2 && (y == 0 || e[x][y - 1].a == 'x')) || (d == 3 && (x == 0 || e[x - 1][y].a == 'x')))
			{
				d = (d + 1) % 4;
			}
			else if(d == 0)
			{
				y++;
			}
			else if(d == 1)
			{
				x++;
			}
			else if(d == 2)
			{
				y--;
			}
			else if(d == 3)
			{
				x--;
			}
			
			if(e[x][y].b == 0)
			{
				e[x][y].b = 1;
				num++;
			}
		}
		cout << num << endl;
	}
	
	return 0;
}
