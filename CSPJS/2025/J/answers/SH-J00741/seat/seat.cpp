#include <bits/stdc++.h>
using namespace std;

	int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int t = n * m;
	int x = 0,y = 1,z = 0;
	cin >> x;
	for (int i = 2;i <= t;i++){
		cin >> z;
		if (z > x){
			y++;
		}
	}
	x = y;
	y = x / n;
	z = x % n;
	if (z != 0){
		y++;
	}
	cout << y << " ";
	if (y % 2 == 1){
		if (z == 0){
			cout << n;
		}
		else{
			cout << z;
		}
	}
	else{
		if (z == 0){
			cout << 1;
		}
		else{
			cout << n - z + 1;
		}
	}
	return 0;
}
