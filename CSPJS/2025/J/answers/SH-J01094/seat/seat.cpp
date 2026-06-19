#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	
	cin>>n>>m;
	
	int ooo=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[0];
	sort(a,a+n*m);
	for(int i=0;i<=n*m;i++){
		if(a[i]==xiaor){
			 ooo=n*m-i;	 
		}
	}
	int h=0,l=0;
	if(ooo%n==0){
		l=ooo/n;
	}
	else{
		l=ooo/n+1;
	}
	int ppp=0;
	if(ooo%n==0){
		ppp=m;
	}
	else{
		ppp=ooo%n;
	}
	if(l%2==1){
		h=ppp;
	}
	else{
		h=m-ppp+1;
	}
	
	cout<<l<<" "<<h;
	return 0;
}












