#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
void f(int l,int len,int maxa,int step){
//	cout<<l<<' '<<len<<' '<<maxa<<' '<<step<<endl;
	if(step>n){
		if(l>=3&&len>2*maxa) {
			ans++;
		}
		return;
	} 
	f(l,len,maxa,step+1);
	f(l+1,len+a[step],max(maxa,a[step]),step+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(x==1){
		for(int i=3;i<=n;i++){
			long long sum=1;
			for(int j=0;j<i;j++){
				sum*=n-j;
				sum/=j+1;
			}
			ans+=sum;
		}                             
	}
	else f(0,0,0,1);
	cout<<ans%998244353;
	return 0;
}
