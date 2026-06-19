#include <bits/stdc++.h>
using namespace std;


int t;
int n, k, q;
int knw[114514][250];//第i位人的词库没有字符j
bool book[114514][15]
int main(){
	cin >> t;
	while(t--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++){
			int num;
			cin >> num;
			for(int j = 1; j <= num; j++){
				cin >> knw[i][j];
				book[i][knw[i][j]] = true;
			}
			
		}
		int wave, k;
		while(q--){
			cin >> wave >> k;
			
		}
	}
	return 0;
}
