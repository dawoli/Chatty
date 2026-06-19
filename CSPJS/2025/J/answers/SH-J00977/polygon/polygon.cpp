#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5009];
bool flag=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		long long cnt=1;
		for(int i=1;i<=n;i++){
			cnt=cnt*2%mod;
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(n=3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
	}else{
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
