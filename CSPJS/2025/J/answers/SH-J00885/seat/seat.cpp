#include<bits/stdc++.h>

using namespace std;

int n, m, s;
int a[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i ++){
		cin >> a[i];
	}
	s = a[0];
	sort(a, a + n * m);
	for(int i = 0; i < n * m; i ++){
		if(a[i] == s){
			s = n * m - i;
			break;
		}
	}
	cout << ceil((s * 1.0) / m) << ' ';
	if((int)ceil((s * 1.0) / m) % 2 == 1){
		if(s % n == 0){
			cout << n << endl;
		}
		else{
			cout << s % n << endl;
		}
	}
	else{
		if(s % n == 0){
			cout << 1 << endl;
		}
		else{
			cout << n - s % n + 1 << endl;
		}
	}
	return 0;
}
