#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5010],s[5010],f[5010][5010],cnt[5010];//h[i] represents the amount of a[?]<i;
long long sum;							 //f[i][j]:the ways there are to add up to i using the previous j a 
long long ksm(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1)res*=a,res%=MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res%MOD;
}
long long calc(int c,int n){
	if(c>n/2)c=n-c;
	long long res=1,t=1;
	for(int i=n;i>n-c;i--){
		res*=i;
		res*=ksm(res,MOD-1);
		while(res%t==0 and t<=c)res/=t,t++;
		if(t>c)res%=MOD;
	}
	return res%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		cnt[a[i]]++;
	}
	if(a[1]==1 and a[n]==1){
		for(int i=3;i<=n;i++){
			sum+=calc(i,n);
			sum%=MOD;
		}
		cout<<sum<<'\n';
	//	sum=0;
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5000;j++)f[j][i]=f[j][i-1]%MOD;
		for(int j=5000;j>=a[i];j--){
			f[j][i]+=f[j-a[i]][i-1]%MOD;
			f[j][i]%=MOD;
	//		cout<<f[j][i]<<' ';
		}
	}
//	for(int i=1;i<=5000;i++){
//		if(f[i][n]>0)cout<<i<<' '<<f[i][n]<<'\n';
//	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=5000;j++){
	//		if(f[j][i-1]<0)cout<<114514;
			if(j>s[i-1])break;
			sum+=f[j][i-1]%MOD;
			sum%=MOD;
		}
	//	cout<<i<<' ';
	}
	cout<<sum;
	return 0;
} 
//freopen("polygon.in","r",stdin);
/*

*/
