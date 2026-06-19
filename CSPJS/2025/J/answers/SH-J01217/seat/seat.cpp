#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int s[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) {
		cin >>s[i];
	}
	int aps=s[1];
	sort(s+1, s+n*m+1, greater<int>());
	for(int i = 1; i <= n*m; i++) {
		if(((i-1)/n)%2==0){
			a[(i-1)/n+1][(i-1)%n+1] = s[i];
		}
		else
			a[(i-1)/n+1][n+1-((i-1)%n+1)] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1 ; j <=m; j++) {
			if(a[i][j] == aps) {
				cout << i << " " << j << endl;
				break;
			}
		}
	}
	return 0;
}
