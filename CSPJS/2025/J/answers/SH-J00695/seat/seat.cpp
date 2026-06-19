#include<bits/stdc++.h>
using namespace std;
struct node {
	int s,tyx;
} a[1145];
bool cmp(node x,node y) {
	return x.s>y.s;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].s;
		a[i].tyx=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i].tyx==1) {
			cout<<(int)ceil(i*1.0/n)<<" ";
			if((int)ceil(i*1.0/n)%2==1) {
				if(i%n==0)cout<<n;
				else cout<<i%n;
			} else {
				int g;
				if(i%n==0)g=n;
				else g=i%n;
				cout<<n+1-g;
			}
		}
	}
}
