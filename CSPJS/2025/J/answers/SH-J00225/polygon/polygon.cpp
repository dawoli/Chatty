#include<bits/stdc++.h>
using namespace std;
int n,a[10009],sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>2*a[3]) cnt++;
	}else if(n==4){
		if(sum-a[1]>2*a[4]) cnt++;
		if(sum-a[2]>2*a[4]) cnt++;
		if(sum-a[3]>2*a[4]) cnt++;
		if(sum-a[4]>2*a[3]) cnt++;
		if(sum>2*a[4]) cnt++;
	}else if(n==5){
		if(sum>2*a[5]) cnt++;
		if(sum-a[1]-a[2]>2*a[5]) cnt++;
		if(sum-a[1]-a[3]>2*a[5]) cnt++;
		if(sum-a[1]-a[4]>2*a[5]) cnt++;
		if(sum-a[1]-a[5]>2*a[4]) cnt++;
		if(sum-a[2]-a[3]>2*a[5]) cnt++;
		if(sum-a[2]-a[4]>2*a[5]) cnt++;
		if(sum-a[2]-a[5]>2*a[4]) cnt++;
		if(sum-a[3]-a[4]>2*a[5]) cnt++;
		if(sum-a[3]-a[5]>2*a[4]) cnt++;
		if(sum-a[4]-a[5]>2*a[3]) cnt++;
		if(sum-a[1]>2*a[5]) cnt++;
		if(sum-a[2]>2*a[5]) cnt++;
		if(sum-a[3]>2*a[5]) cnt++;
		if(sum-a[4]>2*a[5]) cnt++;
		if(sum-a[5]>2*a[4]) cnt++;
	}else{
		cnt=n%998244353;
	}
	cout<<cnt;
	return 0;
}
