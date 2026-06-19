#include<bits/stdc++.h>
using namespace std;
bool is(int sum,int maxi){
	return sum>2*maxi;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5002];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3) cout<<0;
	else{
		if(a[0]+a[1]+a[2]>2*a[2]) cout<<1;
		else cout<<0;
	}
	return 0;
}
