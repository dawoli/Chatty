#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon3.in","r",stdin);
freopen("polygon3.out","w",stdout);
int n,m,ii,g;
cin>>n>>m;
int a[m*n];
for(int i=0;i<n*m;i++){
	cin>>a[i];
	 ii=a[0];
	
}
for(int i=0;i<n*m;i++){
for(int i=0;i<n*m;i++){
	
	if(a[i]<a[i+1]){																						
    	int j=a[i];
		a[i]=a[i+1];
		a[i+1]=j; 
	} 
	    if(a[i]>a[i-1]){
    	int j=a[i];
		a[i]=a[i-1];
		a[i-1]=j; 
	}	
	
}
}
for(int i=0;i<n*m;i++){
if(a[i]==ii){
	g=i;
}
}
cout<<g/m<<"  "<<g%m;








return 0;










}
