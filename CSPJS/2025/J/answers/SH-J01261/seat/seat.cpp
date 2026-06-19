#include<bits/stdc++.h>
using namespace std;
int n,m;
int xrx,xry;
int a[114];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xr){
			xr=i;
		}
	}
	xrx=(xr+n-1)/n;
	xry=xr-n*(xrx-1);
	if(xrx%2==0){
		cout<<xrx<<" "<<n-xry+1;
	}
	else{
		cout<<xrx<<" "<<xry;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
