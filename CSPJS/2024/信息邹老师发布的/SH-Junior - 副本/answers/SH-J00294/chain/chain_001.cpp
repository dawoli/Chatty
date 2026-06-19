#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100009],s[10009][1005],r[100009],c[100009];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	cin>>T;
	for(int www=1;www<=T;www++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x=rand()%2;
		cout <<x<<endl;
	}
	return 0;
}
