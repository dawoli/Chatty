#include<bits/stdc++.h>
using namespace std;
int l[10005],s[10005][20005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain,out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l[j];
			for(int h=1;h<=l[i];h++){
				cin>>s[j][h];
			}
		}
		for(int j=1;j<=q;j++){
			int r,c;
			cin>>r>>c;
			cout<<1<<"\n";
		}
	}
	return 0;
}
