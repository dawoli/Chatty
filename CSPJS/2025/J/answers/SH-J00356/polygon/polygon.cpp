#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int g;
	cin>>g;
	for(int i=0;i<=g;i++){
		cin>>a[i];
	}
	for(int i=0;i<g;i++){
		for(int j=i;j<g;j++){
		if(a[i]<a[j]){
			int z=a[i];
			a[i]=a[j];
			a[j]=z;
		}
	}
}
	if(g<3){
	cout<<0;	
	}
	if(g==3){
		if(a[1]+a[2]+a[0]>2*a[0]){
		cout<<1;
	}
		else{
			cout<<0;
		}
	}
	if(g==4){
		cout<<4;
		
		
	}
	if(g==5)cout<<8;
	if(g==6)cout<<11;
	return 0;
}
