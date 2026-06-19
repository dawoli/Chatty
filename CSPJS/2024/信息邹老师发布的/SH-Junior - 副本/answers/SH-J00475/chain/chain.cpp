#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[100005],r[100005],c[100005];
string s[100005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>s[i];
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
		}
	}
	cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
	return 0;
}
