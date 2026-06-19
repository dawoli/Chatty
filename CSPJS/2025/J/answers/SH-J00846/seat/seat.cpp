#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int ans[105][105];
int imp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int tot = n*m;
	for(int i = 1;i <= tot;i++){
		cin >> b[i];
	}
	imp = b[1];
	sort(b+1,b+tot+1);
	for(int i = 1;i <= tot;i++){
		a[i] = b[tot-i+1];
	}
	for(int k = 1,i = 1,j = 1;k <= tot;){
		ans[1][1] = a[k];
		while(j >= 1 && j < m && i % 2 == 1){
			j++;
			k++;
			if(a[k] == imp){
				cout << i << ' ' << j << endl;
				return 0;
			}
			ans[i][j] = a[k];
		}
		i++;
		k++;
		while(j >= 1 && j <= m && i % 2 == 0){
			ans[i][j] = a[k];
			if(a[k] == imp){
				cout << i << ' ' << j << endl;
				return 0;
			}
			j--;
			k++;
		}
	}
	return 0;
}
