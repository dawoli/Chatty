#include <bits/stdc++.h>
using namespace std;
long long n,m,p[505],f1,f2,mod = 998244353,ans;
char c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> c[i];
		if(c[i]=='1') f1++;
	}
	for(int i = 1;i<=n;i++){
		cin >> p[i];
		if(p[i]>0) f2++;
	}
	if(f1<m||f2<m){
		cout << 0;
		return 0;
	}
	if(f1==n){
		ans = 1;
		for(int i = 1;i<=n;i++) ans = (n*ans)%mod;
		cout << ans;
	}
	return 0;
}
