#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,k;
int x,y,d;
int ans = 0;
char mp[1001][1001];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int answer[6];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int t;
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		ans = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int j = 1;j <= n;j++)
		{
			char a[1001];
			cin >> a;
			for(int p = 0;p < m;p++)
				mp[j][p+1] = a[p];
		}
		if(mp[x+dx[d%4]][y+dy[d%4]] == '.')
			ans = 1;

		answer[i] = ans;
	}
	for(int i = 0;i < t;i++)
		cout << answer[i] << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
