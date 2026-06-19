#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3+10;
int n, m, k;
bool vis[N][N];
struct Node{
	int x, y, d;
}now;
char mp[N][N];
string s;

Node nxt(Node now){
	if(now.d == 0)
		return (Node){now.x,now.y+1,now.d};
	if(now.d == 1)
		return (Node){now.x+1,now.y,now.d};
	if(now.d == 2)
		return (Node){now.x,now.y-1,now.d};
	if(now.d == 3)
		return (Node){now.x-1,now.y,now.d};
}

signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		cin >> now.x >> now.y >> now.d;
		vis[now.x][now.y] = true;
		for(int i = 1; i <= n; ++i){
			cin >> s;
			mp[i][0] = 'x';
			for(int j = 1; j <= m; ++j)
				mp[i][j] = s[j-1];
			mp[i][m+1] = 'x';
		}
		for(int j = 0; j <= m+1; ++j) mp[0][j] = mp[n+1][j] = 'x';
		for(int i = 1; i <= k; ++i){
			Node npos = nxt(now);
			if(mp[npos.x][npos.y] == '.')
				now = npos;
			else now.d = (now.d+1) & 3;
			vis[now.x][now.y] = true;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(vis[i][j]) ++ans, vis[i][j] = false;
		cout << ans << endl; 
	}
}
