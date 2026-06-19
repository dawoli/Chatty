#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
bool good[200005][105];
int main(){
	//freopen("chain.in","r",stdin);
	//freopen("chain.out","w",stdout);
	cin >> t;
	while(t--){
		for(int i = 0; i < 200005; i++){
			for(int j = 0; j < 105; j++){
				good[i][j] = false;
			}
		}
		cin >> n >> k >> q;
		vector<int> v[n+5];
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			for(int j = 0; j < a; j++){
				int x;
				cin >> x;
				v[i].push_back(x);
			}
		}
		
	}
}
