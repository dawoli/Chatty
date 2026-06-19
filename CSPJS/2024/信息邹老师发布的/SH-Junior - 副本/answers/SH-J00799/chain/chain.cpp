#include<bits/stdc++.h>
using namespace std;
int t;
int words[200009];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=200009;i++) words[i]=0;
		int n,k,q; cin>>n>>k>>q;
		int l[100009],s[100009];
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[j];
				if(j!=1) words[s[j]]=1;
			}
		}
		int r[100009],c[100009];
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			cout<<words[c[i]]<<endl;
		}
	}
	return 0;
}
