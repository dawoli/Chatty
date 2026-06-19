#include <iostream>
#include <cstring>

char mp[1001][1001];
bool is[1001][1001];

int dx[] = { 1, 0,-1, 0};
int dy[] = { 0, 1, 0,-1};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;std::cin >> t;
for(int it_j = 0;it_j<t;it_j++)
{
	int n, m, k;std::cin >> n >> m >> k;
	int x, y, d;std::cin >> y >> x >> d;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			std::cin >> mp[i][j];
	
	int ans = 0;
	memset(is,0,sizeof(is));
	for(int i = 0;i<k;i++){
		if(!is[y][x]){
			is[y][x] = true;
			++ans;
		}
		int xt = x+dx[d], yt = y+dy[d];
		if(xt>0&&yt>0&&xt<=m&&yt<=n&&mp[yt][xt]=='.')
			x = xt, y = yt;
		else
			d = (d+1)%4;
	}std::cout << (is[y][x]?ans:ans+1) << std::endl;
}
}
