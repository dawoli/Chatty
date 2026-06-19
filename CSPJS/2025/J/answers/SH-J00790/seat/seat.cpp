#include<bits/stdc++.h>
using namespace std;
int n,m,s,r,sx,sy;
int a[110];
int b[20][20];
int cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(s==a[i])r=i;
	}
	sx=r/n;
	r%=n;
	if(r!=0)sx++;
	if(sx%2==1)sy=r;
	else sy=n-r+1;
	if(r==0)sy=n;
	cout<<sx<<" "<<sy;
	return 0;
}
