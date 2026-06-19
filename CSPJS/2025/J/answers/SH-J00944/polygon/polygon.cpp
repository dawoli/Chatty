#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
int maxx,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(maxx*2<sum)
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}
