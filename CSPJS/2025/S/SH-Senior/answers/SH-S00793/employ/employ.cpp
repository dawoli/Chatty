#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long long mod = 998244353;
int n,m,cnt = 0,maxn;
long long sum = 0;
bool vis[N];
int wait[N];
string s;

long long quick_pow(long long a,long long b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long ta = quick_pow(a*a%mod,b/2)%mod;
	if(b%2 == 1) return ta*a%mod;
	return ta;
}
void dfs(int step,int num){
	if(maxn-cnt < m) return;
	if(num == m){
		sum += quick_pow(1ll*(n-step+1),1ll*(n-step+1));
		sum %= mod;
		//printf("³ÉÀ¤");
		return;
	}
	if(step > n){
		//printf("À¤");
		return;
	}
	if(s[step-1] == '0'){
		for(int i = 1;i <= n;i++){
			if(vis[i]) continue;
			vis[i] = 1;
			//printf("%d",i);
			dfs(step+1,num);
			vis[i] = 0;
		}
	}else{
		for(int i = 1;i <= n;i++){
			if(vis[i]) continue;
			vis[i] = 1;
			//printf("%d",i);
			if(wait[i] <= step-1-num) {
				cnt++;
				dfs(step+1,num);
				cnt--;
			}
			else{
				dfs(step+1,num+1);
			}
			vis[i] = 0;
		}
	}
	//printf("À¤");
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(nullptr);
	
	
	scanf("%d %d",&n,&m);
	cin >> s;
	for(int i = 0;i < n;i++){
		maxn += (s[i]-'0');
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&wait[i]);
	}
	dfs(1,0);
	cout << sum;
	return 0;
}
