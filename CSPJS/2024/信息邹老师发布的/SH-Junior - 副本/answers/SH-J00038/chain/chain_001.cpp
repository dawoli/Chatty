#include<bits/stdc++.h>
using namespace std;
bool s[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,k,q;
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++){
			int l,mem = -1000000;
			cin >> l;
			for(int j = 1;j <= l;j++){
				int num;
				cin >> num;
				if(j - mem < k){
					s[num] = 1;
				}
				if(num == 1){
					mem = j;
				}
			}
		}
		while(q--){
			int r,c;
			cin >> r >> c;
			if(r == 1) cout << s[c] << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
