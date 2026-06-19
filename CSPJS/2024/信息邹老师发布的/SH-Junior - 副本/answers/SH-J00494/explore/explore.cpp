#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int T;
	cin >> T;
	for( int i = 0 ; i < T ; i ++ )
	{
		//cout << "1" << endl;
		int n , m , k;
		cin >> n >> m >> k;
		int map[n+1][m+1];

		int x , y , d;
		cin >> x >> y >> d;
		for( int nx = 0 ; nx < n ; nx ++ )
		{
			string way;
			cin >> way;
			for( int l = 0 ; l < m ; l ++ )
			{
				if ( way[l] == 'x' ) map[nx+1][l+1] = 1;
				else map[nx+1][l+1] = 0;
			}
		}
		int dx = 0;
		int dy = 0;
		int tx,ty;
		map[x][y] = 2;
		for( int kx = 0 ; kx < k ; kx ++ )
		{
			if ( d == 0 )
			{
				dx = 0;
				dy = 1;
			}
			if ( d == 1 )
			{
				dx = 1;
				dy = 0;
			}
			if ( d == 2 )
			{
				dx = 0;
				dy = -1;
			}
			if ( d == 3 )
			{
				dx = -1;
				dy = 0;
			}
			tx = x + dx;
			ty = y + dy;
			if ( (tx > n) or (ty > m) or (tx <= 0) or (ty <= 0) or (map[tx][ty] == 1))
			{
				d = (d+1)%4;
			}
			else 
			{
				x = tx;
				y = ty;
			}
			map[x][y] = 2;
		}
		int cnt = 0;
		for ( int xp = 0 ; xp < n ; xp ++ )
		{
			for ( int yp = 0 ; yp < m ; yp ++ )
			{
				if (map[xp+1][yp+1] == 2) cnt += 1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
