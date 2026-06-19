#include<bits/stdc++.h>
using namespace std;
long long f;
int T[120],T1[120][30],n,a,ans=0,b1,b2,dp[120],x=0;
int main(){
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		x=0;
		cin>>T[i];
		if(T[i]==a){
			ans++;
			dp[i]=1;
		}
		while(T[i]>0){
			T1[x][i]=T[i]%=2;
			T[i]/=2;
			x++;
		}
	}
	while(a>0){
		f*=10;
		f+=a%2;
		a/=2;
	}
	cout<<ans;
	return 0;
}
