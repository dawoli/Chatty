#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n;
long long a[5001],s[5001],yhtr[5005][5005];
long long search(long long j,long long i,long long lim){
	if(j==1){
		long long pos=upper_bound(a+1,a+i+1,lim)-a;
		if(pos>i) return 0;
		return (i-pos+1)%mod;
	}
	long long cnt=0;
	for(int z=j;z<=i;z++) cnt=(cnt+search(j-1,z-1,lim-a[z]))%mod;
	return cnt%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	yhtr[1][1]=1;
	for(int i=2;i<=n+1;i++){
		for(int j=1;j<=i;j++) yhtr[i][j]=(yhtr[i-1][j]+yhtr[i-1][j-1])%mod;
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<=i-1;j++){
			cnt=(cnt+search(j,i-1,a[i]))%mod;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
