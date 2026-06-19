#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],r,h,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	l=ceil(r*1.0/n);
	if(l%2==1){
		h=r%n;;
		if(h==0)h=n;
	}
	else {
		h=n-r%n+1;
		if(h==n+1)h=1;
	}
	cout<<l<<" "<<h;
	return 0;
}
