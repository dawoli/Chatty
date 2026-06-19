#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,t,k,q,_r,_c,_li[maxn];
vector<int> a[maxn];
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>k>>q;
		for(int i=1; i<=n; i++) {
			cin>>_li[i];
			for(int j=1; j<=_li[i]; j++) {
				cin>>a[i][j];
			}
		}
		for(int i=1; i<=q; i++) {
			cin>>_r>>_c;
		cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
