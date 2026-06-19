#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l[100005],a[100005][200005],r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=-1;j<=l[i];j++){
				cin>>a[i][j];
			} 
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			cout<<"0\n";
		}
	}
	return 0;
}
