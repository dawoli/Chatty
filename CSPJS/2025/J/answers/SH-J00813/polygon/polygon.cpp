#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[5010],maxn=LONG_LONG_MIN,flag_1=1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		if(sum>=2*maxn)cout<<"1";
		else cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag_1=0;
			break;
		}
	}
	if(flag_1==1){
		int ans=0,sum_n=1,sum_m=1,tmp_m=1;
		for(int i=3;i<=n;i++){
			sum_n=1,sum_m=1,tmp_m=1;
			for(int j=1;j<=n;j++)sum_n*=j;
			for(int j=1;j<=i;j++)sum_m*=j;
			for(int j=1;j<=n-i;j++)tmp_m*=j;
			ans+=sum_n/(sum_m*tmp_m);
		}
		cout<<ans;
	} 
	return 0;
}
