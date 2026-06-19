#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],s[5005],f[505][50005];
void solve1(){ 
	cout<<1ll*n*(n-1)*(n-2)/6%mod;
}
void solveBF(){
	reverse(a+1,a+n+1);
	bool f[30];
	long long maxn,sum,cnt=0;
	for(long long p=1;p<(1<<n);p++){
		maxn=0,sum=0;
		for(int i=1;i<=n;i++)
			if(p>>(i-1)&1){
				f[i]=true,sum+=a[i];
				if(!maxn)
					maxn=a[i];
			}
		if(sum>maxn*2)
			cnt++;	
	}
	cout<<cnt;
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i]&&j<=100;j++)
			printf("%3d ",f[i][j]);
			puts("");
	}
}
void solve3(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=s[i];j++){
			if(j>=a[i])
				f[i][j]=f[i-1][j-a[i]]+1;
			f[i][j]=(f[i][j]+f[i-1][min(j,s[i-1])])%mod;
		}
	}
	//print();
	for(int i=3;i<=n;i++){
		ans=(ans+f[i][s[i]]-f[i][min(s[i],a[i]*2)]+mod)%mod;
		for(int j=1;j<i;j++)
			for(int k=j+1;k<=i;k++)
				if(a[j]+a[k]>a[i])
					ans=(ans+2+mod)%mod;
	}
	cout<<ans;
}
void solve(){
	solveBF();
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	if(n<=20)
		solveBF();
	else if(a[n]==1)
		solve1();
	else 
		solveBF();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
