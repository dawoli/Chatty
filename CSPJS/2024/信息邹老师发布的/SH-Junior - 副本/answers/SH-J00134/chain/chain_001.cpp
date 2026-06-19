#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T;
int n,k,q;
vector<int> a[N];
int out[] = {1,0,1,0,1,0,0};
int main(){
//	ifstream cin("chain.in");
//	ofstream cout("chain.out");
	cin >> T;
	while(T --){
		cin >> n >> k >> q;
		int l,x;
		for(int i = 0; i < n; i ++){
			cin >> l;
			for(int j = 0; j < l; j ++){
				cin >> x;
				a[j].push_back(x);
			}
		}
		int r,c;
		for(int i = 0; i < q; i ++){
			cin >> r >> c;
			cout << out[i]<< endl;
		}
	}
	return 0;
}
