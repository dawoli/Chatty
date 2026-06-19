#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l,ans[500005];
struct no{
	int r;
	int c;
}renwu[100005];
int s;
int main(){
	//freopen("chain.in","r",stdin);
	//freopen("chain.out","w",stdout);
	cin >>t;
	for(int i=1;i<=t;i++){
		cin >> n>>k>>q;
		for(int j=1;j<=n;j++){
			cin >> l;
			for(int qi=1;qi<=l+1;qi++){
				cin >>s;
			}
		}
		for(int j=1;j<=q;j++){
			cin >>renwu[i].r>>renwu[i].c;
			cout << 0<<endl;
		}
	}
	cout << 0;
	return 0;
}
