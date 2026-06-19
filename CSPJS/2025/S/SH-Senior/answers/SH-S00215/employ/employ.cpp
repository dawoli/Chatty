#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
typedef long long ll;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')x = x * 10 + ch - '0',ch = getchar();
	return x * f;
}
#define N 505
ll n,m,a[N],vis[N],res;
string s;
void dfs(ll u,ll gg){
	if(u == n + 1){
//		cout << gg << endl;
		res += ((n - gg) >= m);
		return;
	}
	rep(i,1,n){
		if(!vis[i]){
			vis[i] = 1;
			dfs(u + 1,gg + (a[i] <= gg || s[u - 1] == '0'));
			vis[i] = 0;
		}
	}
}
#undef N
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(),m = read();
	cin >> s;
	rep(i,1,n)a[i] = read();
	if(n <= 10){
		dfs(1,0);
		cout << res << endl;
	}
	return 0;
}
/*
今年有SH迷惑行为大赏吗，我要上电视
谁出的T2T3啊
T2感觉只有80
T3直接字符串哈希莽过大样例了,怪不得空间2G 
但最后一个点0.5s会不会T啊 
难绷
这是T4,但写不动了,10分下班
*/ 

