#include<bits/stdc++.h>
using namespace std;
int n,a[5000],sum=0,MAX=0,cnt0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		MAX=max(MAX,a[i]);
		if(a[i]==0)cnt0++;
	}
	n-=cnt0;
	if(n==3){
		if(sum>MAX*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(MAX==0){
		cout<<0;
		return 0;
	}
	if(MAX==1){
		cout<<n-2;
		return 0;
	}
	return 0;
}
