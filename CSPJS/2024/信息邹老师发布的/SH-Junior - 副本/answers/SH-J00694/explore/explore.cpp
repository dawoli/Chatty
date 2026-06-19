#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,cnt = 0;
int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};
set<pair<int,int> > s;
int a[1005][1005];
bool check(int i,int j)
{
	return i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == 1;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				char c;
				cin >> c;
				if(c == '.')
				{
					a[i][j] = 1;
				}
				else if(c == 'x')
				{
					a[i][j] = 0; 
				}
			}
		}
		s.clear();
		s.insert(make_pair(x,y));
		while(k--)
		{
			if(check(x + dx[d],y + dy[d]))
			{
				x += dx[d];
				y += dy[d];
				s.insert(make_pair(x,y));
			}
			else
			{
				d = (d + 1) % 4;
			}
		}
		cout << s.size() << endl;
	}
	return 0;
}
