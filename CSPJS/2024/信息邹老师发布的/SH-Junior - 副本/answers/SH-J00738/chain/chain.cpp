#include<bits/stdc++.h>
using namespace std;
int T,n,q,k,s[2001][2001];
bool book[2000001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i][j];
				book[s[i][j]]=1;
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			if(x==1){
				if(book[y]==1) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	return 0;
}
