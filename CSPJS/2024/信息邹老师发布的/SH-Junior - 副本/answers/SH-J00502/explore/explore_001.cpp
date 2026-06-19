#include <bits/stdc++.h>

char mp[1005][1005];
bool vis[1005][1005];

int main(){
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int T;
	
	for (std::cin >> T;T--;){
		
		int n,m,k,x_0,y_0,d_0,cnt = 0;
		
		memset(vis,false,sizeof(vis));
		std::cin >> n >> m >> k >> x_0 >> y_0 >> d_0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				std::cin >> mp[i][j];
		vis[x_0][y_0] = true;
		while (k--){
			
			int x_1 = x_0,y_1 = y_0;
			
			if (d_0 == 0) y_1++;
			else if (d_0 == 1) x_1++;
			else if (d_0 == 2) y_1--;
			else if (d_0 == 3) x_1--;
			if (x_1 <= n && y_1 <= m && mp[x_1][y_1] == '.') x_0 = x_1,y_0 = y_1;
			else d_0 = (d_0 + 1) % 4;
			vis[x_0][y_0] = true;
			
		}
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (vis[i][j]) cnt++;
		std::cout << cnt << '\n';
		
	}
	
	return 0;
}
