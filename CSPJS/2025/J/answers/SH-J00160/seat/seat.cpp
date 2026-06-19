#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int rji=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			rji=i;
			break;
		}
	}
	int s=n*m-rji+1;
	int l=(s+n-1)/n;
	int h;
	if(l%2==0){
		if(s%n==0){
			h=1;
		}
		else{
			h=n-s%n+1;
		}
	}
	else{
		h=s%n;
		if(h==0){
			h=n;
		}
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}
