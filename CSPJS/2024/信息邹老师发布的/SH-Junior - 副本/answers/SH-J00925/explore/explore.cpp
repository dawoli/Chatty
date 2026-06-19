#include<bits/stdc++.h>
using namespace std;
int sx[4] = {1 , 0 , -1 , 0};
int sy[4] = {0 , 1 , 0 , -1};
bool rd[1005][1005];
bool ma[1005][1005];
void solve(){
//	cout << "进入solve函数求解\n";
	int n , m , k;
	cin >> n >> m >> k;
	int x , y , d;
	cin >> x >> y >> d;
//	cout << "输入成功\n";	
	rd[x][y] = 1;
	
	for(int i = 1; i <= n; i++){
		string c;
		cin >> c;
		for(int j = 0; j < c.length(); j++){
			if(c[j] == '.'){
				ma[i][j + 1] = 1;
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << ma[i][j];
//		}
//		cout << endl;
//	}
//	cout << "输入MAP成功\n";
	while(k != 0){
//		cout << "在(" << x << ',' << y << ")\n";
//		cout << "ma[" << x + sx[d] << "][" << y + sy[d] << "]:" << ma[x + sx[d]][y + sy[d]];
		if(ma[y + sy[d]][x + sx[d]] == true){
			x += sx[d];
			y += sy[d];
			rd[y][x] = 1;
//			cout << "走到(" << x << ',' << y << ")\n";
		}else{
//			cout << "改变方向" << d + 1 << "\n"; 
			d++;
			d %= 4;
		}
		k -= 1;
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << rd[i][j];
//		}
//		cout << endl;
//	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(rd[i][j]) ans += 1;
		}
	}
	cout << ans << endl;
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
