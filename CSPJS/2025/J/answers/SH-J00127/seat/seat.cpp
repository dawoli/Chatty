#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[500], b;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++){
		cin >> a[i];
	}
	b = a[0];
	sort(a, a + n * m);
	int x = 1, y = 1, dx = 1;
	for(int i = n * m - 1; i >= 0; i--){
		if(a[i] == b) break;
		if(1 <= x + dx && x + dx <= n){
			x += dx;
		}else{
			y++;
			dx = -dx;
		}
	}
	cout << y << ' ' << x;
	
	return 0; 
}
