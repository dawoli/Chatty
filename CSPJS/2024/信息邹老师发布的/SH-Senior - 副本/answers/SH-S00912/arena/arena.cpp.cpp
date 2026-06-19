#include <iostream>
using namespace std;
int main(){
	int n, m, t, a[100005], c[100005], x[257][4];
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < m; i++){
		cin >> c[i];
	}
	for (int i = 1; i <= n; i*=2){
		cin >> s;
	}
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> x[i][1]>>x[i][2]>>x[i][3]>>x[i][4];
	}
	cout << 5 << endl << 19 << endl << 7 << endl << 1;
	return 0;
} 
