#include <bits/stdc++.h>
using namespace std;
int n,maxn = 0,cnt = 0,ans = 0;
bool flag = true;
int a[1010];
void dfs(int i,int sum,int cnt){
	if(i == n+1){
		if(sum <= 2*maxn) return ;
		ans = max(ans,cnt+1);
		cnt++;
		return ;
	}
	dfs(i+1,sum+a[i],cnt+1);
	dfs(i+1,sum,cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 1) flag = true;
		else flag = false;
		maxn = max(maxn,a[i]);
	}
	if(n <= 3){
		if(a[1]+a[2]+a[3] > 2*maxn) cout << 1;
		else cout << 0;
		return 0;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
