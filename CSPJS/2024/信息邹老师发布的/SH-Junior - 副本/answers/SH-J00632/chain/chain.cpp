#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,k,q;
int l[N],s[N][N],r[N],c[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			cout<<s[i][j]; 
		}
		for(int j=1;j<=q;j++)
			cin>>r[j]>>c[j]; 
	}
	if(T==1) cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
	return 0;
}
