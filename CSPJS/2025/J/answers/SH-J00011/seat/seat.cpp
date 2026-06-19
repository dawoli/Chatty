#include <bits/stdc++.h>
using namespace std;
int li[10010];
int res[110][110]; 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> li[i];
	} 
	int ans = li[1]; // 小R的成绩 
	sort(li + 1, li + 1 + n * m);
	reverse(li + 1, li + 1 + n * m);
	int cnt = 1;
	for (int i = 1; i <= m; i++){ // 遍历列数 
		if (i % 2 == 1){
			for (int j = 1; j <= n; j++){ // 正向遍历行 
				res[i][j] = li[cnt];
				if (li[cnt] == ans){
					cout << i << " " << j << endl;
					return 0;
				}
				cnt++;
			} 
		} else if (i % 2 == 0){
			for (int j = n; j >= 1; j--){ // 逆向遍历行 
				res[i][j] = li[cnt];
				if (li[cnt] == ans){
					cout << i << " " << j << endl;
					return 0;
				}
				cnt++;
			}
		} 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
