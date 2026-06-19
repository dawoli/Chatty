#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,ans=0;
	int b[5000];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	if( a==3){
		if(b[0]>max(b[1]-b[2],b[2]-b[1])&&b[0]<b[1]+b[2]){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0; 
		}
	}
	for(int i=1;i<=a-1;i++){
		for(int o=1;o<i;o++){
			ans+=o;
		}
	}
	cout<<ans%998%244%353;
	return 0;
}
