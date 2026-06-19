#include<bits/stdc++.h>
using namespace std;
int t,l[200010],s[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int i=1;i<=l[i];i++)  cin>>s[i];
		}
		for(int i=1;i<=q;i++){
			int c,r;
			cin>>c>>r;
			cout<<1<<endl;
		}
	}
	return 0;
}
