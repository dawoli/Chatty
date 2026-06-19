#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,xx,yy,dd,cntt = 1;
char mp[10010][10010];
bool vis[10010][10010];
int turn_1(int tt){
	if(tt == 0) return yy++;
	if(tt == 1) return xx++;
	if(tt == 2) return yy--;
	if(tt == 3) return xx--;
}
int turn_2(int tt){
	if(tt == 0) return yy--;
	if(tt == 1) return xx--;
	if(tt == 2) return yy++;
	if(tt == 3) return xx++;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int aa = 1;aa <= t;aa++){
		cntt = 1;
		cin >> n >> m >> k;
		cin >> xx >> yy >> dd;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> mp[i][j];
			}
		}
		for(int i = 1;i <= k;i++){
			vis[xx][yy] = 0;
			turn_1(dd);
			if(xx > n || xx < 1 || yy > m || yy < 1 || mp[xx][yy] == 'x'){
				turn_2(dd);
				dd = (dd+1)%4;
				continue;
			}
			if(vis[xx][yy] == 0){
				cntt++;
				vis[xx][yy] = 1;
			} 
		}
		cout << cntt <<endl;
	}
	return 0;
}

