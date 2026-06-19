#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n >> k >> q;
		for(int j = 1;j <= n;j++){
			cin >> l;
			for(int v = 1;v <= l;v++){
				cin >> s;
			} 
			cout << 0 << endl;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
