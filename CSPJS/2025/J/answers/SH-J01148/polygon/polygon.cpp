#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2) cout<<0;
	else if(n==3){
		int maxn=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		long long sum=0;
		for(int i=3;i<=n;i++){
			long long h=1,h2=1;
			for(int j=n;j>n-i;j--){
				h*=j%998%244%353;
			}
			for(int j=1;j<=i;j++){
				h2*=j%998%244%353;
			}
			sum+=(h/h2)%998%244%353;
		}
		cout<<sum;
	}
	return 0;
}
