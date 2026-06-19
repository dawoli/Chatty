#include <bits/stdc++.h>
using namespace std;
const long M=500009;
int n,m,ans;
int a[M];
int main() {
	freopen("xor.in","r",stdin);
  	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int f[n-i+1];
		for(int j=i;j<=n;++j){
			f[j-i+1]=f[j-i]|a[j];
			if(f[j]==m) ans=max(j-i,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
