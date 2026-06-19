#include <bits/stdc++.h>
using namespace std;
int T,n,q,k=0;
int s[1000005];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for (int i=0;i<T;i++) {
		cin>>n>>k>>q;
		for (int j=0;j<n;j++) {
			cin>>s[j];
		}
	}
	return 0;
} 

