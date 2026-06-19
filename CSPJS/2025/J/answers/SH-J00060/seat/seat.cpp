#include<bits/stdc++.h>
using namespace std;
int n,m,xrp;
struct P{
	int scr,num;
}a[110];
bool cmp(const P&a1,const P&a2){
	return a1.scr>a2.scr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].scr;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i].num==1){
			xrp=i;
		}
	}
	int x,b;
	if(xrp%n==0){
		x=xrp/n;
	}else{
		x=xrp/n+1;
	}
	if(x%2==0){
		b=n-xrp%n+1;
	}else{
		if(xrp%n==0) b=n;
		else b=xrp%n;
	}
	cout<<x<<" "<<b;
	return 0;
}
