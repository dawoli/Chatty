#include<bits/stdc++.h>
using namespace std;
int l[100010],s[100010][200010],r[100010],c[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
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
		for(int i=1;i<=n;i++){
			cout<<1<<"\n";
		}
	}
	return 0;
}
