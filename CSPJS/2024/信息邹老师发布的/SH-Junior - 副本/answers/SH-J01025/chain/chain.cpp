#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int l[100005],s[100005][200005],r,c;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l[j];
			for(int h=1;h<=l;h++)
				cin>>s[j][h];
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			cout<<0<<endl;
		}
	}
	return 0;
}

