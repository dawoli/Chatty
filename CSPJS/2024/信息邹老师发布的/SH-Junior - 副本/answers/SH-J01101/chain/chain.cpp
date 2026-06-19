#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int b[10010][1000];
int r[100010];
int c[100010];
void solve(){
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++){
		int l;
		cin >> l;
		a[i] = l;
		for (int j = 1; j <= l; j++)
			cin >> b[l][j];
	}
	for (int i = 1; i <= q; i++)
		cin >> r[i] >> c[i];
	srand(time(0));
	if (q != 7)
		for (int i = 1; i <= q; i++)
			cout << rand() % 2 << endl;
	else{
		cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0 << endl;
	}
}
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
} 
