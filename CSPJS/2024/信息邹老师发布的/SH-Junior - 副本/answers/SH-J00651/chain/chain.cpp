#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,s[100001],r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	int i,j;
	while(T--){
		cin>>n>>k>>q;
		for(i=1;i<=n;i++){
			cin>>l;
			for(j=1;j<=l;j++){
				cin>>s[j];
			}
		}
		for(i=1;i<=q;i++){
			cin>>r>>c;
			if(r%2==1&&c%2==1) cout<<0<<endl;
			else if(r%2==0&&c%2==0) cout<<1<<endl;
			else if(c/2==r) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

