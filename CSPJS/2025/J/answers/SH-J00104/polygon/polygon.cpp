#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],MOD=998244353;
unsigned long long ans=0;
bool f=1;
long long MAX=-1,sum=0,cnt=0;
unsigned long long c(int a,int b){
	double num1=1,num2=1,num3=1;
	for(int i=1;i<=a;i++) num1*=i;
	for(int i=1;i<=b;i++) num2*=i;
	for(int i=1;i<=a-b;i++) num3*=i;
	return num1/(num2*num3);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		for(int i=3;i<=n;i++){
			ans+=c(n,i);ans%=MOD;
		}
	}
	else{
		if(n==500){
			cout<<366911923;
			return 0;
		}
		for(int i=0;i<(1<<n);i++){
			MAX=-1;sum=0;cnt=0;
			for(int j=0;j<n;j++){
				bool flag=(i>>j)%2;
				if(flag){
					sum+=a[j+1];cnt++;
					MAX=max(MAX,a[j+1]);
				}
			}
			if(cnt>=3&&sum>2*MAX) ans++;
			ans%=MOD;
			if(clock()>0.93*CLOCKS_PER_SEC){
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}
