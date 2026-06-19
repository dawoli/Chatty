#include <iostream>
#include <cstring> 
using namespace std;
long long t;
string a[1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(long long i = 0;i < t;i++)
	{
		long long n, m, k;
		long long x, y, d;
		cin >> n >> m >> k;
		cin >> x >> y >> d; 
		for(long long j = 0;j < n;j++)
		{
			cin >> a[j];
		}
		long long cnt = 1;
		x--;
		y--;
		for(long long j = 0;j < k;j++)
		{
			
			if(d == 4)
			{
				d = 0;
			}
			if(d == 0)
			{
				if( x >= 0 && y+1 >= 0 && x < n && y+1 < m&&a[x][y+1] != 'x' )
				{
					a[x][y] = ',';
					if(a[x][y+1] != ',') 
					{
						cnt++;
					}
					y++;
				} 
				else
				{
					d++;
				}
				
			}else if(d == 1) {
				if( x+1 >= 0 && y >= 0 && x+1 < n && y < m&&a[x+1][y] != 'x' )
				{
					a[x][y] = ',';
					if(a[x+1][y] != ',') 
					{
						cnt++;
					} 
					x++;
				} 
				else
				{
					d++;
				}
			}
			else if(d == 2)
			{
				if(x >= 0 && y-1 >= 0 && x < n && y-1 < m&&a[x][y-1] != 'x' )
				{
					a[x][y] = ',';
					if(a[x][y-1] != ',') 
					{
						cnt++;
					} 
					y--;
				} 
				else
				{
					d++;
				}
			}
			else if(d == 3)
			{
				if( x-1 >= 0 && y >= 0 && x-1 < n && y < m && a[x-1][y] != 'x' )
				{
					a[x][y] = ',';
					if(a[x-1][y] != ',') 
					{
						cnt++;
					}
					x--;
				} 
				else
				{
					d++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
