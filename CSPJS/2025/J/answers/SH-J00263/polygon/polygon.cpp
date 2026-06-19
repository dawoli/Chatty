#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define N 10009
inline void add(int &x,int y){
	x += y;
	while(x >= mod) x -= mod;
}
int n,a[N],f[N],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	f[0] = 1;
	int tmp = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 5001;j > a[i];j--) add(ans,f[j]);
		for(int j = 5000;j >= a[i];j--) add(f[j],f[j - a[i]]);
		(tmp *= 2) %= mod;
		f[5001] = tmp;
		for(int j = 0;j <= 5000;j++) add(f[5001],mod - f[j]);
	}
	cout<<ans<<endl;
}
