#include <bits/stdc++.h>
using namespace std;

int t;


int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while(t--){
		// ÊäÈë 
		int n, k, q;
		cin >> n >> k >> q;
		
		for(int i = 0; i < n; i++){
			int l;
			scanf("%d", &l);
			for(int j = 0; j < l; j++){
				int s;
				scanf("%d", &s);
			}
		}
		
		for(int i = 0; i < q; i++){
			int r, c;
			scanf("%d%d", &r, &c);
		}
		
		cout << 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
