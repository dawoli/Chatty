#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],sc,pos=0,c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc)pos=i;
	}
	if(pos%n==0)c=pos/n;
	else c=pos/n+1;
	if(c%2==1){
		if(pos%n==0)r=n;
		else r=(pos%n);
	}
	else{
		if(pos%n==0)r=1;
		else r=n-(pos%n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
