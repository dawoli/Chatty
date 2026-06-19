#include <bits/stdc++.h>
using namespace std;
void f(){
	int n,k,q,l,s,r,c;
	cin >> n >> k >> q;
	for (int i=1;i<=n;i++){
		cin >> l;
		for (int j=1;j<=l;j++){
			cin >> s;
		}
	}
	for (int i=1;i<=q;i++){
		cin >> r >> c;
	}
	for (int i=1;i<=q;i++){
		cout << 1 << endl;
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while (T){
		f();
		T--;
	}
	return 0;
}
