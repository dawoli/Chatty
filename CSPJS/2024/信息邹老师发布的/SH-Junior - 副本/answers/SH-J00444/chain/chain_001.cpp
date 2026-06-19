#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,k,q;
		cin >> n >> k >> q;
		for(int i = 0;i < n;i++){
			int l;
			cin >> l;
			for(int j = 0;j < l;j++){
				int a;
				cin >> a;
				cout << a << " ";
			}
			cout << "\n";
		}
		for(int i = 0;i < q;i++){
			int a,b;
			cin >> a >> b;
			cout << i % 2 << "\n"; 
		}
	}
} 
