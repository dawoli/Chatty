#include<bits/stdc++.h> 
using namespace std;
int a[5010];
int c(int x,int y){
	int q=1;
	for(int j=y;j<=x;j++)q*=j;
	return q;
}
int main(){
	//freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=3){
		int d=max(a[0],max(a[1],a[2]));
		if(d*2<(a[0]+a[1]+a[2]))cout<<"1";
		else cout<<"0";
	}
	else {
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i+1)/c((n-i),1);
			ans%=998;
			ans%=244;
			ans%=353;
		}
		cout<<ans;
	}
	return 0;
}
