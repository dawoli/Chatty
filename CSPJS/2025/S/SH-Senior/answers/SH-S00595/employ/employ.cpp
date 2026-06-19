#include<bits/stdc++.h>
using namespace std;

const int maxn=500,mod=998244353;
int n,m,c[maxn+5];
bool s[maxn+5],remain[maxn+5];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	int cnt0=0;
	bool flag=true;
	long long fac=1;
	for (int i=0; i<n; i++) {
		cin>>s[i];
		if (s[i]==0) flag=false;
		fac=fac*(i+1)%mod;
	}
	for (int i=0; i<n; i++) {
		cin>>c[i];
		if (c[i]==0) cnt0++;
	}
	if (flag) {
		if (n-cnt0<m) cout<<0;
		else ;
		return 0;
	}
}
