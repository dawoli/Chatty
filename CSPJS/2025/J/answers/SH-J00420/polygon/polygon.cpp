#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[5001],f[501][50001];
int solveBF(){
	int aa=pow(2,n),ans=0;
	for(long long i=0;i<aa;i++){
		int sm=0,mx=0,nm=0,t=i;
		for(int j=1;j<=n;j++){
			if(t&1){
				sm+=a[j];
				mx=max(a[j],mx);
				nm++;
			}
			t>>=1;
		}
		if(nm>2&&sm>mx*2) ans++;
		if(ans>=MOD) ans-=MOD;
	}
	return ans;
}
bool canSP(){
	for(int i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
int solveSP(){
	int ans=1;
	for(int i=0;i<n;i++) ans=(2*ans)%MOD;
	ans=(ans-n*(n+1)/2+MOD-1)%MOD;
	return ans;
}
int solveDP(){
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<50001;j++) f[i][j]=f[i-1][j];
		for(int j=a[i];j<50001;j++) f[i][j]=(f[i-1][j-a[i]]+f[i][j])%MOD;
	}
	int ans=0;
	for(int i=3;i<n;i++) for(int j=a[i]*2+1;j<=a[i+1]*2&&j<50001;j++){
		ans=(ans+f[i][j])%MOD;
	}
	for(int i=a[n]*2+1;i<50001;i++) ans=(ans+f[n][i])%MOD;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<21) cout<<solveBF();
	else if(canSP()) cout<<solveSP();
	else cout<<solveDP();
	return 0;
}
