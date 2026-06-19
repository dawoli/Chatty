#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+10;
struct note1{
	int a1,b1,c1;
}z[N];
int maxn[N];
int dp[N];
bool teb;
int te[N];
int cnt;
int ban;
int index;
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n;
	teb = true;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		ban = x / 2;
		cnt = 0;
		for(int j = 1;j <= x;j++){
			cin >> z[j].a1 >> z[j].b1 >> z[j].c1;
			if(z[j].b1 != 0 or z[j].c1 != 0){
				teb = false;
			}
			maxn[j] = max(max(z[j].a1,z[j].b1),z[j].c1);
		}
		if(teb){
			for(int i = 1;i <= x;i++){
				te[i] = z[i].a1;
			}
			for(int i = 1;i <= ban;i++){
				int maxq = 0;
				for(int j = 1;j <= x;j++){
					if(te[j] > maxq and !vis[j]){
						maxq = te[j];
						index = j;
					}
				}
				vis[index] = true;
				cnt += maxq;
			}
			cout << cnt << endl;
		}else{
			for(int j = 1;j <= 3;j++){
				if(j == 1){
					dp[i][j] = z[i].a1 - z[i].b1 - z[i].c1;
					for(int f = 1;f <= x;f++){
						dp[i][j] -= z[j][z+1];
					}
				}else if(j == 2){
					dp[i][j] = z[i].b1 - z[i].z1 - z[i].c1;
					for(int f = 1;f <= x;f++){
						dp[i][j] -= z[j][z+1];
					}
				}else{
					dp[i][j] = z[i].b1 - z[i].z1 - z[i].c1;
					for(int f = 1;f <= x;f++){
						dp[i][j] -= z[j][z+1];
					}
				}
			}
			for(int j = 1;j <= x;j++){
				for(int z = 1;z <= 3;z++){
					for(int zf = 1;zf <= x;zf++){
						int maxxn = 0;
						if(dp[zf][z] > maxxn){
							maxxn = dp[zf][z];
						}
					}
				}
				cnt += maxxn;
			}
			cout << cnt;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
