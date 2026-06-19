#include<bits/stdc++.h>
using namespace std;
int a[105];
int seat[15][15];
bool cmp(int a,int b) {
	return a>b;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m ;
	for (int i=1;i<=n*m;i++) cin >> a[i] ;
	int hao=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int curx=1,cury=1;
	bool curdir=0;
	for (int i=1;i<=n*m;i++) {
		seat[curx][cury]=a[i];
		if (i%n==0) {
			cury++;
			curdir=!curdir;
		}else if (curdir==0) curx++;
		else curx--;
	} 
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (seat[i][j]==hao) {
				cout << j << " " << i << endl ;
				return 0;
			}
		}
		//cout << endl ;
	}
	return 0;
}
