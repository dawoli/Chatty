#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[1050],k;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	int l,h;
	if(k%m==0) l=m+1-k/m;
	else l=m-k/m;
	if(l%2==0){
		h=k%n;
		if(k%n==0) h=n;
	}
	else{
		h=n+1-k%n;
		if(k%n==0) h=1;
	}
	cout<<l<<" "<<h;
	return 0;
}
