#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], b[15][15], tmp, idx=1;
bool cmp(int x, int y){
	if(x>y){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
		if(i==1){
			tmp=a[i];
		}
	}
	sort(a+1, a+n*m+1, cmp);
	for(int i=1; i<=m; i++){
		if(i%2==1){
			for(int j=1; j<=n; j++){
				b[j][i]=a[idx];
				idx++;
			}
		}
		else{
			for(int j=n; j>=1; j--){
				b[j][i]=a[idx];
				idx++;
			}
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(b[j][i]==tmp){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	
	return 0;
}
