#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[15],m=-10e9,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k+=a[i];
		if(a[i]>m)m=a[i];
	}
	if(n==3 && k>2*m)cout<<1;
	else cout<<0;
	return 0;
}
