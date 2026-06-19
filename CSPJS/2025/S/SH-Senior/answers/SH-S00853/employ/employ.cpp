#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Ten year's OI all in vain , no long long see forefathers
inline ll read(){
	char c = getchar(); ll t = 0 , f = 1;
	while(c < '0' || c > '9'){if (c == '-') {f = -1;} ; c = getchar();};
	while(c >= '0' && c <='9'){t = t * 10 + c - 48 , c = getchar();}
	return t * f;
}
int n , m , a[505] , b[505] , cnt , P = 998244353;
bool f[505] , vis[505];
string s;
void dfs(int ref , int k){
	if(k == n){
		//cout << "ref=" << ref << "\n";
		if(ref + m <= n){
			cnt++ , cnt %= P;
		}
		return;
	}
	for(int i = 0 ; i < n ; i++){
		if(!vis[i]){
			vis[i] = 1;
			//cout << a[i] << " " << ref << " " << i << "\n";
			if(a[i] > ref && f[k]) dfs(ref , k + 1);
			else dfs(ref + 1 , k + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0 ; i < n ; i++) f[i] = s[i] - '0';
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	dfs(0 , 0);
	cout << cnt;
}
