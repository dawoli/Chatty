#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5009];
const int mod=998244353;
bool allone(){
	for(int i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
int pow2(int x){
	int sum=1;
	for(int i=1;i<=x;i++) sum=sum*2%mod;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(allone()){
    	ans=pow2(n);
    	ans=ans-n-n*(n-1)/2-1;
    	ans=(ans+mod)%mod;
    	cout<<ans<<endl;
    	return 0;
	}
	int N=pow2(n)-1;
	for(int i=1;i<=N;i++){
		int choose[29]={},code=i,Num=0;
		for(int j=1;j<=n;j++){
			choose[j]=code%2;
			code/=2;
		}
		int sum=0,Max=-10000;
		for(int j=1;j<=n;j++){
			if(choose[j]==1){
				sum+=a[j];
				Max=max(Max,a[j]);
				Num++;
			}
		}
		if(sum>2*Max&&Num>=3) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
