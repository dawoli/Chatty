#include<bits/stdc++.h>
using namespace std;
struct node {
	int x;
	int y;
};
struct nodetwo {
	int num;
	bool isSB;//ÊÇsomebody
};
node wdmap[105];
bool mycmp(nodetwo a,nodetwo b) {
	if(a.num > b.num) {
		return true;
	}
	return false;
}
nodetwo cj[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> m >> n;
	for(int i = 1; i <= m*n; i++) {
		cin >> cj[i].num;
	}
	cj[1].isSB = true;
	int k = 1;
	for(int i = 1; i <= m; i++) {
		if(i%2 == 1) {
			for(int j = 1; j <= n; j++) {
				wdmap[k] = {i,j};
				k++;
			}
		} else {
			for(int j = n; j >= 1; j--) {
				wdmap[k] = {i,j};
				k++;
			}
		}
	}
	sort(cj,cj+m*n,mycmp);
	for(int i = 0; i <= 100; i++) {
		if(cj[i].isSB) {
			cout << wdmap[i+1].x << " " << wdmap[i+1].y;
			return 0;
		}
	}
	return 0;
}
/*
4 4
16 2  15 3
14 4  13 11
12 10 9  8
7  6  5  1
*/


