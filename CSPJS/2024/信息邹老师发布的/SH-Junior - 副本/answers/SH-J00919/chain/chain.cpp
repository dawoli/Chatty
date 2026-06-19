#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,r,c,l[1001],f[200001],s[1001][2001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,127,sizeof(f));
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
				if(f[s[i][j]]>j)f[s[i][j]]=j;
			}
		}
		for(int k=1;k<=q;k++){
			cin>>r>>c;
			if(r==1&&f[c]<=m){
				cout<<1<<endl;
				continue;
			}
			cout<<0<<endl;
		}
	}
}
