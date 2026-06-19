#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,k=1,h,l;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	for(int i=1;i<n*m;i++){
		if(a[i]>b)k++;
	}
	if(k%n==0){
		l=k/n;
	}else{
		l=k/n+1;
	}
	int c=k-n*(l-1);
	if(l%2==0){
		h=n-c+1;
	}else{
		h=c;
	}
	cout<<l<<" "<<h;
	return 0;
}
