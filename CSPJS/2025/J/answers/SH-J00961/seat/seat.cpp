#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int m, n, s[19][19], a[109], b, ansx, ansy;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	b = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				cnt++;
				if(a[cnt] == b){
					cout << i << " " << j << endl;
					break;
				}
			}
		}
		else{
			for(int j = n; j >= 1; j--){
				cnt++;
				if(a[cnt] == b){
					cout << i << " " << j << endl;
					break;
				}
			}
		}
	}
	return 0;
}
