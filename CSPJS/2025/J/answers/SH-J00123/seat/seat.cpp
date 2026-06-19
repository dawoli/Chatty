#include <bits/stdc++.h>
using namespace std;
int n,m,dig[150],siz,a[12][12],now,me;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	siz=n*m;
	for(int i=1;i<=siz;i++) cin>>dig[i];
	if(n==1&&m==1) {
		cout<<dig[1];
		return 0;
	}
	me=dig[1];
	sort(dig+1,dig+siz+1,cmp);
	for(int j=1;j<=m;j++) {      //先循环列号，列号每n次变动一次 
		int plu;//1~n/n~1 
		bool f;//如果j是奇数，则升序加；否则降序加 
		if(j%2) plu=1,f=true;
		else plu=n,f=false;
		for(int i=1;i<=n;i++) {  //再循环行号，行号不断变动
			a[i][j]=dig[now*n+plu];
			if(f) plu++;
			else plu--;
		}
		now++;
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=m;j++) {
//			cout<<a[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			if(a[i][j]==me) {
				cout<<j<<' '<<i;
				return 0;
			}
}
