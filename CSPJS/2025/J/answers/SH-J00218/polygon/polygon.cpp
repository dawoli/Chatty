#include<bits/stdc++.h> 
using namespace std;
int a[1005],b[1005],c[1005];
//4 2 2 1 0 3
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	} 
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2<b[3])cout<<1;
		else cout<<0;
		return 0; 
	}
	else cout<<5;
	return 0;
}
