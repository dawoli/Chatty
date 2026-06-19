#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k, x, y, d, map[101][101], cnt = 1;
		cin >> n >> m >> k >> x >> y >>d;
		bool flg = false;
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j =1 ; j <= m ; j ++)
			{
				char c1;
				cin >> c1;
				if(c1 == 'x')map[i][j] = 0;
				else map[i][j] = 1;
				if(map[i][j] == 0)flg = true;
			}
		}
//		for(int i = 0 ; i <= n ; i ++)
//		{
//			for(int j = 0; j <= m ; j ++)
//			{
//				cout << map[i][j];
//			}
//			cout << endl;
//		}
		for(int i = 1; i <= k ; i ++)
		{
			int a = 0, b = 0;
			if(d==0)a = 1;
			if(d==1)b = -1;
			if(d==2)a = -1;
			if(d==3)b = 1;
			int fx = x, fy = y;
			fx += a;
			fy += b;
//			cout <<"d:" << d<< "fx:" <<fx <<"fy:" << fy << "m:" << m << "n:" << n << "map[fx][fy]" << map[fx][fy]<<endl;
			bool a_ = fx >= 0;
			bool b_ = fx <= m;
			bool c_ = fy >= 0;
			bool d_ = fy <= n;
//			cout << a_ << b_ << c_ << d_ << e_ << endl;
			if(a_ and b_ and c_ and d_)
			{
				cnt ++;
				map[fx][fy] = -1;
				x = fx;
				y = fy;	
			}else
			{
				d = d + 1;
				if(d == 4)d = 0;
			}
		 } 
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
