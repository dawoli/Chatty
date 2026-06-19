#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
int a[100005];
int c[100005];

int main(){
	cin >> t;
	while(t--){
		freopen("color.in", "r", stdin);
		freopen("color.out", "w", stdout);
		ans = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		
		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		
		for(int i = n - 1; i >= 0; i--){
			for(int j = i - 1; j >= 0; j--){
				if(a[i] == a[j]) ans += a[i];
			}
		}
		
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
