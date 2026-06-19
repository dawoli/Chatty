#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(a[1]+a[2]>a[0]&&a[0]+a[2]>a[1]&&a[0]+a[1]>a[2]){
			cout<<1;
		}
	}
	else{
		cout<<n-2;
	}
	return 0;
}
