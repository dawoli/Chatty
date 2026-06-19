#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[200], r, ind;

bool cmp(int l, int r){
	return l > r;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i ++)if(a[i] == r)ind = i;
	int ansn = 0, ansm = 0;
	ansm = ind / n + 1;
	ansn = ind % n;
	if(ansn == 0){ansn = n; ansm = ind / n;}
	//cout << ind << " " << ansn << " " << ansm << endl;
	if(ansm % 2 == 0)ansn = (n - ansn + 1);
	cout << ansm << " " << ansn << endl;
	return 0;
}
