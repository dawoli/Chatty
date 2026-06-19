#include <bits/stdc++.h>
using namespace std;
int T;
bool vis[2005][2005];
bool mp[2005][2005]; 

int main(){
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin >> T;
	while(T){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		
		T--;
		
		int n,m,k;
		int x,y,d;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		
		for(int i = 1;i<=n;i++){
			for(int j =1;j<=m;j++){
				char ch;
				cin >> ch;
				if(ch == '.') mp[i][j] = 1;
				else mp[i][j] = 0;
			}
		}
		
		int nx = x,ny = y,nd = d;
		vis[x][y] = 1;
		long long ans = 1;
		
		while(k){
			int nextx,nexty;
			if(nd == 0){
				nextx = nx;
				nexty = ny + 1;
			}
			if(nd == 1){
				nextx = nx + 1;
				nexty = ny;
			}
			if(nd == 2){
				nextx = nx;
				nexty = ny - 1;
			}
			if(nd == 3){
				nextx = nx - 1;
				nexty = ny;
			}
			
			if(mp[nextx][nexty] == 1 && nextx >= 1 && nextx <=n && nexty >=1 && nexty <= m  ){
				nx = nextx;
				ny = nexty;
				if(!vis[nextx][nexty]){
					ans++;
					vis[nextx][nexty] = 1;
				}
			}
			else nd = (nd+1) % 4;	
			
			k--;
		}
		
		cout << ans << endl;
	}
	
	
	return 0;
}
