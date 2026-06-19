#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int mx;
void dfs(int cnt,string s){
	if(cnt == n + 1){
		int ans = 0;
		int fb = 0,fr = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0'){
				if(a[fb] == a[i]){
					ans += a[i];
				}
				fb = i;
			}else{
				if(a[fr] == a[i]){
					ans += a[i];
				}
				fr = i;
			}
		}
		mx = max(mx,ans);
		return ;
	}
	dfs(cnt + 1,s + '0');
	dfs(cnt + 1,s + '1');
}
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		mx = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		dfs(2," 0");
		cout << mx << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
}
