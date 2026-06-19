
#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		set<pair<int,int> > st;
		int n, m, k, x, y, d;
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> mp[i][j];
			} 
		}
		st.insert({x,y});
		while(k--){
			int x1, y1;
			if (d == 0){
				x1 = x, y1 = y + 1;
			}
			if (d == 1){
				x1 = x + 1, y1 = y;
			}
			if (d == 2){
				x1 = x, y1 = y - 1;
			}
			if (d == 3){
				x1 = x - 1, y1 = y;
			}
			if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && mp[x1][y1] == '.'){
				x = x1, y = y1;
			}else{
				d++;
				d %= 4;
			}
			st.insert({x,y});
//			cout << x << " " << y << " " << d << endl;
		}
		cout << st.size() << endl;
	}
} 

