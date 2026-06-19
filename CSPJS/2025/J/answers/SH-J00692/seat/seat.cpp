#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N*N+7];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w=0,num=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		if(i==1) {
			w = a[i];
		}
		if(a[i]>=w) {
			num++;
		}
	}
	if(num%m==0) {
		c = num/m;
	}
	else c = (num-(num%m))/m+1;
	if(c%2==1) {
		r = num-(c-1)*m;
	}
	else {
		r = n+1-(num-(c-1)*m);
	}
	cout<<c<<" "<<r;
	return 0;
} 
