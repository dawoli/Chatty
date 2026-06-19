#include<bits/stdc++.h> 
using namespace std;
int n, m, a[1000], loc;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin >> n >> m;
	for(int i = 0; i < n*m; i++) cin >> a[i];
	sort(a + 1, a + n*m);
	loc = n * m - 1;
	for(int i = n*m - 1; i > 0; i--) {
		if(a[0] > a[i]) {
			loc = n*m - i - 1; break;
		}
	}
	//cout << loc << endl;
	int c = loc / n + 1;
	int r = (c % 2 == 0 ? n - loc % n : loc % n + 1);
	cout << c << " " << r;
	return 0;
}
