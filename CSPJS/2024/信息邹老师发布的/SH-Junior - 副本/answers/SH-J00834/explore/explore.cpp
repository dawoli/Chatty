#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n,m,k,T,x,y,d;
int ans;
string input;
bool mp[1010][1010];//mp[ÐÐ][ÁÐ] 
bool vis[1010][1010];
int step_x[4] = {0,1,0,-1};
int step_y[4] = {1,0,-1,0};
bool flag;
void __init()
{
	ans = 0;
	n = 0;
	m = 0;
	k = 0;
	memset(mp , 0 , sizeof(mp));
	memset(vis , 0 , sizeof(vis));
}


bool is_available(int cx ,int cy , int cd)
{
	return (cx+step_x[cd] >= 1 && cx+step_x[cd] <=n && cy+step_y[cd] >=1 && cy+step_y[cd] <=m  && mp[cx+step_x[cd]][cy+step_y[cd]] == 0 );
}

void dfs(int nx, int ny , int nd,int nk)
{
	if(nk > k) return;
	if(!vis[nx][ny]) ans ++;
	vis[nx][ny] = 1;
	//if(flag) cout << nx << " " << ny << " " << nk << '\n';
	int tx = nx;
	int ty = ny;
	int td = nd;
	int tk = nk;
	for(int i = 0;i<4;i++)
	{
		tk++;
		if(is_available(tx,ty,td)) 
		{
			dfs(tx+step_x[td] , ty+step_y[td] , td , tk);
			break;
		}
		else
		{
			td = (td+1) %4;
			
		} 
		
	}
}


inline void solve()
{
	cin >> n >> m >> k;
	cin >> x >> y >> d;
	for(int i = 1;i<=n;i++)
	{
		cin >> input;
		for(int j = 0;j<m;j++)
		{
			if(input[j] == 'x') mp[i][j+1] = 1;
			else mp[i][j+1] = 0;
		}
	}
	
	//cout  << -1 << '\n';
	dfs(x , y , d ,0);
	cout  << ans << '\n';
}

int main()
{
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	cin >> T;
	int nt = T;
	while(T--)
	{
		__init();
		//if(nt > T) flag = 1;
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
