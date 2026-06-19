#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define N 100009
int n,m,a[N],c[N],p[N];
void solveBF(){
	int ans = 0;
	for(int i = 1;i <= n;i++) p[i] = i;
	do{
		int num = 0,cnt = 0;
		for(int i = 1;i <= n;i++){
			if(num >= c[p[i]]){
				num++;
				continue; 
			}
			if(a[i]) cnt++;
			else num++;
		}
		if(cnt >= m) ans++;
	}while(next_permutation(p + 1,p + n + 1));
	cout<<ans<<endl;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		char c;
		cin>>c;
		a[i] = c - '0';
	}
	for(int i = 1;i <= n;i++) cin>>c[i];
	if(m == n){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0 || c[i] == 0){
				cout<<0<<endl;
				return 0;
			}
		}
		int ans = 1;
		for(int i = 1;i <= n;i++) (ans *= i) %= mod;
		cout<<ans<<endl;
	}else solveBF();
}

