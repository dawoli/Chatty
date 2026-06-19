#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10,mod = 998244353;
int n,ans;
int a[maxn];

bool cmp(int a,int b){
	return a > b;
}

void dfs(int i,int sum,int val){
	if(sum + (n - i + 1) * a[i] <= val)	return;
	if(sum > val){
		ans = (1LL * ans + (1 << (n - i + 1))) % mod;
		return;
	}
	if(i == n + 1)	return;
	dfs(i + 1,sum + a[i],val);
	dfs(i + 1,sum,val);
}

void solve1(){
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n - 2;i ++){
		dfs(i + 1,0,a[i]);
	}
}

int power(int b){
	int a = 2,res = 1;
	while(b > 0){
		if(b % 2 == 1)	res = (1LL * res * a) % mod;
		b /= 2;
		a = (1LL * a * a) % mod;
	}
	return res;
}

void solve2(){
	ans = (power(n) - 1 - n - 1LL * (n - 1) * n / 2) % mod;
	ans = (ans + mod) % mod; 
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a[i]);
	}
	if(n <= 20)	solve1();
	else	solve2();
	printf("%d",ans);
	return 0;
} 
