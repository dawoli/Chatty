#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,idx,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m*n/2;i++)swap(a[i],a[m*n-i+1]);
	for(int i=1;i<=m*n;i++)
		if(a[i]==r)idx=i;
	y=(idx+n-1)/n;
	if(y%2)x=idx%n;
	else x=(n-idx%n+1)%n;
	if(x==0)x=n;
	cout<<y<<" "<<x;
	return 0;
}
