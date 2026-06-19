#include<bits/stdc++.h>
using namespace std;
int n,m,c[109];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>c[(i-1)*m+j];
		}
	}
	int t=c[1],id;
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(c[i]==t) {
			id=i;
			break;
		}
	}
	//cout<<id;
	int mod=(id-1)/n+1;
	cout<<mod<<" ";
	int p=id%n;
	if(p==0) p=n;
	if(mod%2==1) {
		cout<<p;
	}
	else {
		cout<<n-p+1;
	}
	return 0;
}
//int mian()
//freopen("seat1.in","r",stdin);
//uid:±ÀÌú138429001 
//ÅÔ±ßµÄÈËÔÚÒ÷ËÐË®ÁúÒ÷ .jpg
