#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N], s[N], maxn = -1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1){
			s[i] = a[i];
			continue;
		}
		s[i] = s[i - 1] ^ a[i];
	} 
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		
		for(int j = i; j <= n; j++){
//			printf("%d %d : %d \n", i, j, (s[i - 1] ^ s[j]));
			if((s[j] ^ s[i - 1]) == k){
				cnt++;
//				cout << i << " " << j << " " << cnt << endl;
				i = j + 1;
			}
		}
		maxn = max(maxn, cnt);
	}
	cout << maxn << endl;
	return 0;
}
/*
4 0
2 1 0 3
*/
