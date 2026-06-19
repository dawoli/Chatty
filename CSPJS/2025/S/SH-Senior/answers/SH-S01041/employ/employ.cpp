#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=998244353;
int p[505];
int vis[505];
int s[505];
string ss;
int c[505];
int cc=0;
int ans=0;
int n,m,k;
bool t11=1;

bool check(int x){
	int abdd=0;
	
	for (int i=1; i<=x; i++){
		if (s[i]==0 || abdd>=c[p[i]]){
			abdd++;
		}
		if (abdd>k) return false;
	}
	return true;
}

void solve(int dep){
	if (dep==n){
		if (check(dep)){
			ans++;
		}
		return;
	}
	for (int i=1; i<=n; i++){
		if (!vis[i]){
			vis[i]=1;
			p[dep+1]=i;
			solve(dep+1);
			vis[i]=0;
		}
	}
	
}

int t1(){
	int ans=1;
	for (int i=1; i<=n; i++){
		ans*=i;
		ans=ans%mod;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	k=n-m;
	cin >> ss;
	for (int i=0; i<n; i++){
		s[i+1]=ss[i]-'0';
		if (s[i+1]==0) t11=0;
	}
	for (int i=1; i<=n; i++) cin >> c[i];
	
	if (0){
		cout << t1();
		return 0;
	}
	solve(0);
	cout << ans;
	return 0;
}

