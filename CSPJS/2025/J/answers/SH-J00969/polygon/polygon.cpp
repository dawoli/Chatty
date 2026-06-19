#include<bits/stdc++.h>
using namespace std;
int n;
int a[3];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	if(n<3||n>3)cout<<0;
	else if(n==3){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[2]+a[1]>a[0])cout<<1;
		else cout<<0;
	}
	return 0;
}
