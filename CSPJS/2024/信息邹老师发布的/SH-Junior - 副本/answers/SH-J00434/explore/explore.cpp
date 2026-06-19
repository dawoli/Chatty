#include <bits/stdc++.h>
using namespace std;
long long mmm[1005][1005] = {0}, vis[1005][1005] = {0};
long long solver(long long cnt, long long x, long long y, long long n, long long m, long long d, long long k)
{
	if(k == 0)
		return cnt;
	long long x1, y1;
	if(d == 0){
		x1 = x, y1 = y + 1;
	}else if(d == 1){
		x1 = x + 1, y1 = y;
	}else if(d == 2){
		x1 = x, y1 = y - 1;
	}else if(d == 3){
		x1 = x - 1, y1 = y;
	}
	k -- ;
	if(x1 > n || y1 > m || x1 < 1 || y1 < 1 || mmm[x1][y1] == 0)
	{
		d ++ ;
		d %= 4;
		return solver(cnt, x, y, n, m, d, k);
	}else{
		if(vis[x1][y1] != 1){
			cnt ++;
			vis[x1][y1] = 1;
		}
		return solver(cnt, x1, y1, n, m, d, k);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	char a;
	
	long long T, n, m, k, x, y, d;
	
	cin >> T;
	while(T -- )
	{
		cin >> n >> m >> k ;
		cin >> x >> y >> d ;
		
		for(long long i = 1;i <= n;i ++ ){
			for(long long j = 1;j <= m;j ++ ) 
			{
				cin >> a;
				vis[i][j] = 0;
				if(a == '.'){
					mmm[i][j] = 1;
				}else{
					mmm[i][j] = 0;
				}
			}
		}
		vis[x][y] = 1;
		cout << solver(1, x, y, n, m, d, k) << endl;
		
	}
	return 0;
}
