#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x,y,z,max1;
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	cin>>x>>y>>z;
	max1=max(x,max(y,z));
	if(x+y+z>2*max1){
		cout<<1;
	}
	else{
		cout<<0;
	}
} 
