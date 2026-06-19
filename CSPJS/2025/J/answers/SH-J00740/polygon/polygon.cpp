#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int lesn=505;
const long long mod=998244353;
int n,a[maxn];
long long sum[lesn*lesn],ans=0;
bool isone=true;
long long qpow(int a,int b){
	if(b==0) return 1;
	if(b==1) return a%mod;
	long long res=qpow(a,b/2)%mod;
	if(b%2) return a*res%mod*res%mod;
	return res*res%mod;
}
void RunOne(){
	long long cutt=(1+n+(n*(n-1))/2)%mod;
	cout<<(qpow(2,n)+mod-cutt)%mod<<endl;
}
void Run(){
	sort(a,a+n);sum[0]=1;
	for(int i=1;i<n;i++){
		for(int j=maxn;j>=0;j--){
			sum[j+a[i-1]]+=sum[j];
		}
		for(int j=0;j<=a[i];j++){
			ans=(ans+sum[j])%mod;
		}
	}
	cout<<(qpow(2,n)+mod-ans-2)%mod<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1) isone=false;
	}
	if(isone){
		RunOne();
		return 0;
	}
	Run();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
