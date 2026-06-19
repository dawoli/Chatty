#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n,m;
//int c[509][509];
string s;
int tol[509],p[509];
const int MOD = 998244353;	
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
//	for(int i=n;i>=2;i--) {
//		ans*=i;
//		ans%=MOD;
//	}
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>tol[i];
	}
//	for(int i=1;i<=n;i++) {
//		c[0][i]=1;
//		c[i][i]=1;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) {
//			c[i][j]=c[i-1][j]+c[i-1][j-1];
//			c[i][j]%=MOD;
//		}
//	}
//	ll ans2=0;
//	for(int i=m;i<=n;i++) {
//		ans2+=ans*c[m][n];
//	}
//	cout<<ans2;
	for(int i=1;i<=n;i++) {
		p[i]=i;
	}
	do {
		int tot=0,fail=0;
		for(int i=1;i<=n;i++) {
			if(fail>=tol[p[i]]) {
				fail++;
				continue;
			}
			if(s[i-1]=='1') {
				tot++;
			}else {
				fail++;
			}
		}if(tot>=m){
			ans++;
			if(ans>MOD) {
				ans-=MOD;
			}
//			for(int i=1;i<=n;i++) {
//				cout<<p[i]<<" ";
//			}
//			cout<<endl;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0; 
}
