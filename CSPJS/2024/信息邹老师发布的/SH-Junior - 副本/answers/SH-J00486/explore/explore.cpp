#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d,num = 1;
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i ++){
		cin >> n >> m >> k >> x >> y >> d;

		for(int j = 1;j <= n;j ++){
			for(int k = 1;k <= m;k ++){
				cin >> a[j][k];
			}
		}
		for(int j = 1;j <= k;j ++){
			if(d == 0){
				int x1 = x, y1 = y + 1,d1 = d;
				if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && a[x1][y1] == '.'){
					x = x1;y = y1;
					num ++;
				}
				else d = (d1 + 1) % 4;continue;
			}
			if(d == 1){
				int x1 = x + 1, y1 = y,d1 = d;
				if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && a[x1][y1] == '.'){
					x = x1;y = y1;
					num ++;
				}
				else d = (d1 + 1) % 4;continue;
			}
			if(d == 2){
				int x1 = x, y1 = y - 1,d1 = d;
				if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && a[x1][y1] == '.'){
					x = x1;y = y1;
					num ++;
				}
				else d = (d1 + 1) % 4;continue;
			}
			if(d == 3){
				int x1 = x - 1, y1 = y,d1 = d;
				if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && a[x1][y1] == '.'){
					x = x1;y = y1;
					num ++;
				}
				else d = (d1 + 1) % 4;continue;
			}
		}
		cout << num << endl;
		num = 1;
	}
	return 0;
}
