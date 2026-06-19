#include <bits/stdc++.h>
using namespace std;


int t;
int n, k, q;
int dis[114514][114];
int knw[114515][250];//第i位人的词库位n 
int main(){
	cin >> t;
	while(t--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++){
			int num;
			cin >> num;
			for(int j = 1; j <= num; j++){
				cin >> knw[i][j]
			}
		}
	}
	return 0;
}
