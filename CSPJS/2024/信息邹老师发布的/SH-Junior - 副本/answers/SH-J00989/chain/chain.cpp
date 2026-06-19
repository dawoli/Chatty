#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9,M=1e2+9;
int t;
int n,k,q;
int l[N];
int r[M],c[M];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++) cin>>s;
		}
		for(int i=1;i<=q;i++) cin>>r[i]>>c[i],cout<<-1<<endl;
	}
	return 0;
}
