#include <iostream>
#include <cstdio>
using namespace std;
const int MOD = 998244353;
int n,m,c[25],sum[25],ans,k[25];
bool vis[25];
char p[25];
void dfs(int x){
	if(x == n + 1){
		int cnt = 0,cnt1 = 0;
		for(int i = 1;i <= n;i++){
			if(c[k[i]] <= cnt && p[i] == '1'){
				cnt1++;
			}
			else cnt++;
		}
		if(cnt1 >= m) ans = (ans + 1) % MOD;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			k[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> p[i];
	}
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
} 
