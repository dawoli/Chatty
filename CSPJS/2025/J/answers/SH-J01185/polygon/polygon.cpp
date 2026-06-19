#include<bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int n,a[5050],plan[25];
long long ans,f[5050];
bool check(){
	int mx = 0,cnt = 0,sum = 0;
	for(int i = 1;i <= n;++i){
		if(plan[i] == 1){
			++cnt;
			sum+=a[i];
			mx = max(mx,a[i]);
		}
	}
	if(cnt < 3) return false;
	if(sum <= 2*mx) return false;
	return true;
}
bool ok(){
	for(int i = 2;i <= n;++i){
		if(a[i] != a[i-1]) return false;
	}
	return true;
}
inline long long C(int x,int y){
	long long res = 1;
	for(int i = y;i >= y-x+1;--i){
		res*=i;
		while(res%(y-i+1)!=0) res+=mod;
		res/=(y-i+1);
		res%=mod;
	}
	return res;
}
void dfs(int step){
	if(step > n){
		if(check()){
			++ans;
			if(ans >= mod) ans-=mod;
		}
		return ;
	}
	plan[step] = 1;
	dfs(step+1);
	plan[step] = 0;
	dfs(step+1);
}
inline long long calc(int x,int num){
	for(int i = 1;i <= num+1;++i) f[i] = 0;
	f[0] = 1;
	for(int i = 1;i <= x;++i){
		for(int j = num+1-a[i];j <= num;++j){
			f[num+1]+=f[j];
			if(f[num+1] >= mod) f[num+1]-=mod;
		}
		for(int j = num;j >= a[i];--j){
			f[j]+=f[j-a[i]];
			if(f[j] >= mod) f[j]-=mod;
		}
	}
	return f[num+1];
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;++i) cin>>a[i];
	if(ok()){
		for(int i = 3;i <= n;++i){
			ans+=C(i,n);
			while(ans >= mod) ans-=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n <= 20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;++i){
		ans+=calc(i-1,a[i]);
		if(ans >= mod) ans-=mod;
	}
	cout<<ans;
	return 0;
}
