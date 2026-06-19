#include <bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int mark;
};
int n,m;
node a[110],zw[15][15];
bool cmp(node x,node y) {
	return x.mark>y.mark;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) {
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int curx,cury;
	for (int i=1;i<=n*m;i++) {
		if (i<n*2) {
			if (i>n)curx=n-i%n+1;
			else curx=i;
			if (i>n) cury=2;
			else if (i<=n) cury=1; 
		}
		else if (i%(n*2)>n||i%(n*2)==0) {
			curx=n-i%(n*2)%n+1;
			if (i%n!=0)cury=i/n+1;
			else cury=i/n;
		} else {
			curx=i%(2*n);
			if (i%n!=0)cury=i/n+1;
			else cury=i/n;
		}
		zw[curx][cury].mark=a[i].mark;
		zw[curx][cury].id=a[i].id;
		if (zw[curx][cury].id==1) {
			cout<<cury<<" "<<curx;
			return 0;
		}
	}
	return 0;
}
