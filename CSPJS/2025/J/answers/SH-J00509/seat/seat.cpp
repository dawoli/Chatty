#include<bits/stdc++.h>
using namespace std;
long long n,a[105],m,st,id;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	st=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==st)id=i;
	}
	int sx,sy,k;
	if(id%n==0)sy=id/n;
	else sy=id/n+1;
	k=id%(2*n);
	if(k==0)k=2*n;
	if(k<=n){
		sx=k;
	}else sx=2*n-k+1;
	cout<<sy<<" "<<sx;
	return 0;
}
