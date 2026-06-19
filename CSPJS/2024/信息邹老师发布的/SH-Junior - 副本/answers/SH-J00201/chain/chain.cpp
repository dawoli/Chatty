#include <iostream>
#include <cstdio>
using namespace std;

//骗分代码，5分就够了 

int T,n,k,q,s[2048][2048],l[2048],r,c,cod;
bool ok[200048];

int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while (T-->0) {
    	cod=0;
    	cin >> n >> k >> q;
    	for (int i=1;i<=200020;i++) {
    		ok[i]=0;
		}
    	for (int i=1;i<=n;i++) {
			cin >> l[i];
			cod=0;
			for (int j=1;j<=l[i];j++) {
				cin >> s[i][j];
				if (cod>0) {
					ok[s[i][j]]=1;
					cod--;
				}
				if (s[i][j]==1) {
					cod=k-1;
				}
			}
		}
		for (int i=1;i<=q;i++) {
			cin >> r >> c;
			if (ok[c]) {
				cout << 1 << endl;
			}else{
				cout << 0 << endl;
			}
		}
	}
}
