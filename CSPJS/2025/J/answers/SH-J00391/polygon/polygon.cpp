#include<bits/stdc++.h>
using namespace std;
const long long p=998244353ll;
long long n,a[5009],ans,dp[5009],f[5009][5009];
void solve1(){
	long long k=2,x=n;
	ans=1;
	while(x){
		if(x&1)ans=ans*k%p;
		k=k*k%p;
		x>>=1;
	}
	ans-=n;
	ans-=n*(n-1)/2;
}
void solveBF(long long i,long long sum,long long mx,long long k){
	if(i>n){
		if(k<3)return;
		if(sum<=2*mx)return;
		ans++;
		return;
	}
	solveBF(i+1,sum+a[i],max(mx,a[i]),k+1);
	solveBF(i+1,sum,mx,k);
}
void solve_n3(){
	dp[3]=(a[1]+a[2]>a[3]);
	for(long long i=4;i<=n;i++){
		dp[i]=dp[i-1];
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(long long j=1;j<i;j++){
			f[j][0]=f[j-1][0]*2%p;
			for(long long k=1;k<=a[i]+1;k++){
				f[j][k]=f[j-1][k]+f[j-1][max(0ll,k-a[j])];
				f[j][k]%=p;
			}
		}
		dp[i]+=f[i-1][a[i]+1];
		dp[i]%=p;
	}
	ans=dp[n];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==1&&a[n]==1)solve1();
	else if(n<=20)solveBF(1,0,-1,0);
	else solve_n3();
	cout<<ans<<endl;
	return 0;
}
