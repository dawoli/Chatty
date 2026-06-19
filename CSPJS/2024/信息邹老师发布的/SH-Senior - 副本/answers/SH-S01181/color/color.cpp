//26/10/24 16:35
#include<bits/stdc++.h>
using namespace std;

int T, n, a[200005], mx;
bool ch[200005];
void dfs(int k){
	if(k > n){
		int ans = 0; 
		for(int i = 2; i <= n; ++ i){
			for(int j = i - 1; j >= 1; -- j){
				if(ch[j] == ch[i]){
					if(a[i] == a[j])
						ans += a[i];
					break;
				}
			}
		}
		mx = max(mx, ans);
		return;
	}
	ch[k] = false;
	dfs(k + 1);
	ch[k] = true;
	dfs(k + 1);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n;
		for(int i = 1; i <= n; ++ i)
			cin >> a[i];
//		printf("------\n");
		mx = 0;
		dfs(1);
		cout << mx << endl;
	}
	return 0;
}
