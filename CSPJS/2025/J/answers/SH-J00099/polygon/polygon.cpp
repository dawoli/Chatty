#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt,ma=-1,tt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(a[i]==1) tt++;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cnt++;
		cout<<cnt<<endl;
	}
	else if(n==4){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) cnt++;
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))) cnt++;
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))) cnt++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))) cnt++;
		cout<<cnt<<endl;
	}
	else if(n==5){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) cnt++;
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5]))) cnt++;
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))) cnt++;
		if(a[1]+a[3]+a[5]>2*max(a[1],max(a[3],a[5]))) cnt++;
		if(a[1]+a[4]+a[5]>2*max(a[1],max(a[4],a[5]))) cnt++;
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))) cnt++;
		if(a[2]+a[3]+a[5]>2*max(a[2],max(a[3],a[5]))) cnt++;
		if(a[2]+a[4]+a[5]>2*max(a[2],max(a[4],a[5]))) cnt++;
		if(a[3]+a[4]+a[5]>2*max(a[3],max(a[4],a[5]))) cnt++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))) cnt++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(a[1],max(a[2],max(a[3],a[5])))) cnt++;
		if(a[1]+a[2]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[4],a[5])))) cnt++;
		if(a[1]+a[3]+a[4]+a[5]>2*max(a[1],max(a[3],max(a[4],a[5])))) cnt++;
		if(a[2]+a[3]+a[4]+a[5]>2*max(a[2],max(a[3],max(a[4],a[5])))) cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))) cnt++;
		cout<<cnt<<endl;
	}
	else if(ma==1){
		cout<<(tt%998244353*(tt-1)%998244353*(tt-2)%998244353/6)%998244353<<endl;
	}
	else if(n<3) cout<<0<<endl;
	return 0;
}
//feropenferopenferopenferopenint mianint mianint mian11451411451419198101919810
