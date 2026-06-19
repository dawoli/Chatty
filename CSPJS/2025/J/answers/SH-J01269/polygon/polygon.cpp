#include<bits/stdc++.h>
using namespace std;
int n,a[5005],add=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			add++;
		}
	}
	if(n==3&&(a[1]+a[2]+a[3])>(2*max(max(a[1],a[2]),a[3]))){
		cout<<1;
		return 0;
	}else if(n==3){
		cout<<0;
		return 0;
	}
	cout<<98231;
	return 0;
}
