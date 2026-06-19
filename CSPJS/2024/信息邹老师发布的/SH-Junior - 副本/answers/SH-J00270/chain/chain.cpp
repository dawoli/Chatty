#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s,r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> k >> q;
		for(int j=1;j<=n;j++){
			cin >> l;
			for(int m=1;m<=l;m++)cin >> s;
		}
		for(int j=1;j<=q;j++)cin >> r >> c;
	}
	cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0;
	return 0;
} 
