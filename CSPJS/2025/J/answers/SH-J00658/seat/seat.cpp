#include <bits/stdc++.h>
using namespace std;
int n, m, rval, rspot;
int a[205];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n* m; i++){
		cin >> a[i];
	}
	
	rval = a[1];
	sort(a + 1, a + n* m + 1, cmp);
	
	for(int i = 1; i <= n* m; i++){
		if(a[i] == rval){
			rspot = i;
			break;
		}
	}
	
	int c = ceil((double)rspot / (double)n);
	int r;
	if(c % 2 == 0){
		r = n - (rspot - (c - 1)* n) + 1;
	}else{
		r = rspot - (c - 1)* n;
	}
	
	cout << c << " " << r;
}
