#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,x;
	cin>>n>>m;
	int zong=m*n;
	int a[zong]={0};
	for(int i=0;i<zong;i++){
		cin>>a[i];
	}
	w=a[0];
	for(int i=0;i<zong;i++){
		for(int j=i;j<zong;j++){
		if(a[i]<a[j]){
			int z=a[i];
			a[i]=a[j];
			a[j]=z;
		}
	}
	}
	for(int i=0;i<zong;i++){
		if(a[i]==w){
			x=i+1;
		}
	}
	int yu=x%n;
	int yu2=n-yu;
	int lie=x/n;
	if(x%n!=0){
		if(lie%2==1){
		cout<<lie<<" "<<yu;	
		}
		if(lie%2==0){
		cout<<lie<<" "<<yu2;	
	}
	}
	if(x%n==0){	
		if(lie%2==1){
			cout<<lie<<" "<<n;
	}
		if(lie%2==0){
		cout<<lie<<" "<<1;	
	}		
}
	return 0;
}
