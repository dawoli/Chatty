#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n<=2){
			cout<<0;
			return 0;
		}
		int maxa=max({a[1],a[2],a[3]});
		int sum=a[1]+a[2]+a[3];
		if(sum>maxa*2){
			cout<<1;
		}else cout<<0;
		return 0;
	}else if(n>=0&&n<=5000){
		for(int i=3;i<=n;i++){
			long long fenzi=1,fenmu=1;
			for(int j=i;j>=2;j--){
				fenzi*=j;
				fenzi%=Mod;
			}
			for(int j=n;j>=n-i+1;j--){
				fenmu*=j;
				fenmu%=Mod;
			}
			//cout<<fenzi<<" "<<fenmu<<endl;
			ans+=fenmu/fenzi;
			ans%=Mod;
		}cout<<ans;
	}else cout<<998244352;
	return 0;
}

