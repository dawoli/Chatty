#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin >> n;
	cin >> m;
	int r;
	for(int i=1;i <= n;i++){
		for(int j=1;j <= m;j++){
			cin >> a[i][j];
			b[(i-1)*m+j] = a[i][j];
		}
		r = a[1][1];
	}
	sort(b+1,b+n*m+1,greater<int>());
	int order;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[(i-1)*m+j] == r){
				order = (i-1)*m+j;
			}
		}
	}
	bool f = false;
	int k = 0;
	for(int i=1;i<=n;i++){
		if(f){
			for(int j = m;j >= 1;j--){
				k++;
				if(k == order){
					cout << i << " " << j << "\n";
				}
			}
			f=false;
			continue;
		}
		for(int j = 1;j <= m;j++){
			k++;
			if(k == order){
				cout << i << " " << j << "\n";
			}
		}
		f=true;
	}
	return 0;
}
