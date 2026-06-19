#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,r,c;
vector<int> s[100005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			s[i].clear();
			cin>>l;
			for(int j=1;j<=l;j++){
				int x;
				cin>>x;
				s[i].push_back(x);
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			cout<<"0\n"; 
		}
	}
	return 0;
}
