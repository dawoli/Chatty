#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, a[N][4], maxn = -1;
long long ans[6];
bool flag;

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	for(int c = 0; c < t; c++){
		
		cin >> n;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
			if(a[i][2] != 0 || a[i][3] != 0){
				flag = 1;
			}
			ans[c] += max(a[i][1], max(a[i][2], a[i][3]));
		}
		
		if(n == 2){
			for(int i = 1; i < 4; i++){
				for(int j = 1; j < 4; j++){
					if(i != j){
						maxn = max(maxn, (a[0][i] + a[1][j]));
					}
				}
			}
			ans[c] = maxn;
		}
		
		else if(!flag){
			ans[c] = 0;
			int b[N];
			for(int i = 0; i < n; i++){
				b[i] = a[i][1];
			}
			sort(b, b + n);
			for(int i = 0; i <= n / 2; i++){
				ans[c] += b[n - i];
			}
			for(int i = 0; i < n; i++){
				cout << b[i] << endl;
			}
		}
		
		/*else if(n <= 30){
			ans[c] = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					
				}
			}
		}*/
		
	}
	
	for(int i = 0; i < t; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}
