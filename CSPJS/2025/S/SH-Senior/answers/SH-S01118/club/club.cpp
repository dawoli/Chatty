#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], mxppl, ans, r[3], s[100005], typeA = 0, typeB = 0;
int dp[100005];
void dfs(int now, int sum){
	if(now > n){
		if(sum > ans) ans = sum;
		return;
	}
	if(sum+s[n]-s[now-1] <= ans) return;
	for(int i = 0;i < 3;i++){
		if(r[i] == mxppl) continue;
		r[i]++;
		dfs(now+1, sum+a[now][i]);
		r[i]--;
	}
	return;
}
struct tb{
	int a, b;
};
			tb b[100005];
bool cmp(tb x, tb y){
	return x.a > y.a;
}
void dfs2(int now, int sum){
	if(now > n){
		if(sum > ans) ans = sum;
		return;
	}
	if(sum+s[n]-s[now-1] <= ans) return;
	for(int i = 0;i < 2;i++){
		if(r[i] == mxppl) continue;
		r[i]++;
		dfs(now+1, sum+a[now][i]);
		r[i]--;
	}
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		typeA = 0;
		typeB = 0;
//		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		mxppl = n/2;
		for(int i = 1;i <= n;i++){
			int minppl = min(mxppl, i);
			for(int j = 0;j < 3;j++){
				cin>>a[i][j];
			} 
			if(!typeA &&( a[i][1] != 0 || a[i][2] != 0)) typeA = 1;
			if(!typeB && a[i][2] != 0) typeB = 1;
			s[i] = s[i-1]+max(a[i][0], max(a[i][1], a[i][2]));
		}
		ans = 0; r[0] = 0; r[1] = 0; r[2] = 0;
		if(!typeA){
			int b[100005];
			for(int i = 1;i <= n;i++) b[i] = a[i][0];
			sort(b+1, b+n+1);
			for(int i = 1;i <= mxppl;i++) ans += b[n-i+1]; 
		}else if(!typeB){
			for(int i = 1;i <= n;i++) b[i] = {a[i][0], a[i][1]};
			sort(b+1, b+n+1, cmp);
			for(int i = 1;i <= mxppl;i++) ans += b[i].a; 
			for(int i = mxppl+1;i <= n;i++) ans += b[i].b; 
//			dfs2(1, 0);
		}
		else{
			dfs(1, 0);
		}
		printf("%d\n", ans);
//		cout<<"---------------------\n";
	}
	return 0;
}
