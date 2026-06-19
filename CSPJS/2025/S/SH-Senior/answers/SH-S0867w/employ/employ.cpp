#include<bits/stdc++.h>
using namespace std;
#define forRange(i1,_a,_b) for(i1 = _a; i1 < _b; i1 ++)
const int MAXN = 5e2 + 10;
char s[MAXN]; int c[MAXN];
int n,m;
long long ans;
bool vis[MAXN];int cnt;

void g(int k){
	if(cnt > m - n) return;
	if(k <= 0){
		ans++;
		return;
	} 
	int i;
	forRange(i, 0, n){
		if(vis[i]) continue;
		vis[i] = true;
		if(c[i] >= cnt || s[i] == '0') cnt ++;
		g(k - 1);
		vis[i] = false;
		if(c[i] >= cnt - 1 || s[i] == '0') cnt --;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cnt = 0;
	for(int i = 0;i < n;i ++){
		cin >> s[i];
	}
	for(int i = 0;i < n;i ++){
		cin >> c[i];
	}
	g(n);
	cout << ans;
	return 0;
} 



