#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
int x, y, d;
int ans;
int directions[4][2];

string strMap[1010];
bool flag[1010][1010];

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	directions[0][0] = 0;
	directions[0][1] = 1;
	
	directions[1][0] = 1;
	directions[1][1] = 0;
	
	directions[2][0] = 0;
	directions[2][1] = -1;
	
	directions[3][0] = -1;
	directions[3][1] = 0;
	
	cin >> T;
	for (int _ = 0; _ < T; _++){
		memset(flag, 0, sizeof(flag));
		
		ans = 1;
		
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		
		x--;
		y--;
		
		flag[x][y] = true;
		
		for (int i = 0; i < n; i++){
			cin >> strMap[i];
		}
		
		for (int i = 0; i < k; i++){
			int newX = x + directions[d][0], newY = y + directions[d][1];
			if ((newX >= 0) && (newX < n) && (newY >= 0) && (newY < m) && (strMap[newX][newY] == '.')){
				x = newX;
				y = newY;
				if (!flag[x][y]){
					flag[x][y] = true;
					ans++;
				}
			}
			else{
				d = (d + 1) % 4;
			}
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
