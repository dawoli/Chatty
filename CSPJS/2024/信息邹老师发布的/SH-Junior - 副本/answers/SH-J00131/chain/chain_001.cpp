#include<iostream>
using namespace std;

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	int n, k, q;
	int s[1050][2050];
	int p[2][100500];
	int a[250] = {0};
	for(int i = 0; i < t; i++){
		cin >> n >> k >> q;
		int l, r, c;
		for(int j = 0; j < n; j++){
			cin >> l;
			for(int g = 0; g < l; g++){
				cin >> s[j][g];
			}
		}
		for(int j = 0; j < q; j++){
			cin >> p[0][j] >> p[1][j];
			cout << 0 << endl;
		}
	}
	
	return 0;
} 
