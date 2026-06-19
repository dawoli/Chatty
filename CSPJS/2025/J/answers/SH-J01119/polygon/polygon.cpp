#include <bits/stdc++.h>
using namespace std;
long long f[5001][5001],a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		f[i][1]=a[i];
		f[1][i]=a[1];
	}
	for(long long i=2;i<=n;i++){
		for(long long j=2;j<=n;j++){
			if(j>=i){
				f[i][j]=a[i]+f[i-1][j];
			}else{
				f[i][j]=a[i]+f[i-1][j-1];
			}
			if(f[i][j]>2*a[i] && j>=3){
				cnt++;
			}
		}
	}
	long long ans=cnt%998244353;
	cout<<ans;
	return 0;
}
