#include<bits/stdc++.h>
using namespace std;

int a[110];


bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sort(a+2,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	int pos=n*m; 
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i]){
			pos=i-1;
			break;
		}
	} 
//	cout<<pos<<endl;
	int r,c;
	c=(pos+n-1)/n; 
	if(c%2==0){
		if(pos%n==0) r=1;
		else r=n-(pos-1)%n;
	}
	else{
		if(pos%n==0) r=n;
		else r=pos%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
