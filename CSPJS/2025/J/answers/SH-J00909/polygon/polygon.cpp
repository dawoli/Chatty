#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
	}
	if(n==3){
		if(a[1]+a[2]<=a[3]){
			cout<<0;
			return 0;
		}
		if(a[2]+a[3]<=a[1]){
			cout<<0;
			return 0;
		}
		if(a[1]+a[3]<=a[2]){
			cout<<0;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(n==4){
		int ans=0;
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=4;k++){
					if((a[i]+a[j]>a[k])&&(a[j]+a[k]>a[i])&&(a[i]+a[k]>a[j])){
						ans++;
					}
				}
			}
		}
		if((a[1]+a[2]+a[3]>a[4])&&(a[1]+a[2]+a[4]>a[3])&&(a[1]+a[4]+a[3]>a[2])&&(a[4]+a[2]+a[3]>a[1])){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		ans=0;
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=5;k++){
					if((a[i]+a[j]>a[k])&&(a[j]+a[k]>a[i])&&(a[i]+a[k]>a[j])){
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=5;k++){
					for(int m=k+1;m<=5;m++){
						int v=max(j,max(k,max(m,i)));
						if(i+j+k+m>2*v){
							ans++;
						}
					}
				}
			}
		}
		sort(a,a+n);
		if(2*a[n]<a[1]+a[2]+a[3]+a[4]+a[5]){
			ans++;
		}
		cout<<ans;
	}
	long long ans=0,ans2=1,k=1;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			k*=j;
			k%=998244353;
		}
		for(int j=n;j>=n-i+1;j--){
			ans2*=j;
			ans2%=998244353;
		}
		ans2/=k;
		ans+=ans2;
		ans%=998244353;
		ans2=1;
		k=1;
	}
	cout<<ans%998244353;
	return 0;
}
