#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,k,a[N],s[N],ans;
int mxa;
bool flagA = 1,flagB = 1;
void taskA(){
	cout << n / 2;
	return;
}void taskB(){
	int sum1 = 0;
	for(int i = 1;i <= n;i++) if(a[i]) sum1++;
	if(k){
		cout << min(sum1,n - sum1);
	}else{
		cout << sum1 / 2 + (n - sum1) / 2;
	}
}
//void dfs(int u,int l,int cnt){
//	if(u == n+1){
//		ans = max(ans,cnt);
//		return;
//	}
//	dfs(u + 1,l,cnt);
//	dfs(u + 1,u + 1,cnt);
//	if((s[u]^s[l-1]) == k) dfs(u + 1,u + 1,cnt + 1);
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);//Don't forget freopen(stdin)!
	freopen("xor.out","w",stdout);//Don't forgrt freopen(stdout)!
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1) flagA = 0;
		if(a[i] > 1) flagB = 0;
		s[i] = s[i - 1] ^ a[i];
		mxa = max(mxa,a[i]);
	}
	if(flagA){
		taskA();
		return 0;
	}else if(flagB){
		taskB();
		return 0;
	}
	if(log2(k) > log2(mxa)){
		cout << 0;
		return 0;
	}
	int l = 1;
	while(l <= n){
		int r = l;
		while(r <= n){
			if((s[r] ^ s[l - 1]) == k){
				ans++;
				l = r;
				break;
			}
			r++;
		}
		l++;
	}
//	dfs(1,1,0);
	cout << ans;
	return 0;
}

