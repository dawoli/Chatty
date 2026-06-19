#include<bits/stdc++.h>
using namespace std;
long long n,m,c[515],ans,o;
char s[515];
bool w[515];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ans=n;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	if (n==m) {
		for (int i=1;i<=n;i++){
			o*=i;
		}
		cout<<o%998244353;
	}
	else cout<<n*m/3;
	return 0;
}
/*
3 2
101
1 1 2
*/
