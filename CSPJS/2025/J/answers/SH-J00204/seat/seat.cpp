#include <bits/stdc++.h>
using namespace std;

int n, m, score, idx, arr[105], brr[11][11];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++){
		cin >> arr[i];
		if (i == 1)  score = arr[i];
	}
	sort(arr + 1, arr + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++){
		if (arr[i] == score) idx = i;
	}
	for (int i = 1, j = 1, k = 1; j <= m; k ++){
		if (k == idx) cout << j << " " << i;
		if (j % 2){
			if (i == n){
				j ++;	
			}else{
				i ++;
			}
		}else{
			if (i == 1){
				j ++;	
			}else{
				i --;
			}
		}
	}

	return 0;
}
