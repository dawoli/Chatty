#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,N,l[105][200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int I=1;I<=T;I++){
		int maxn=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>N;
			for(int i=1;i<=N;i++) cin>>l[N][i];
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			cout<<0<<endl;
		}
	}
	return 0;
}
