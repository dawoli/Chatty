#include<bits/stdc++.h>
using namespace std;
int l[100005];
vector<int>a;
void solve(){
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			int x;
			cin>>x;
			a.push_back(x);
		}
	}
	for(int i=1;i<=q;i++){
		
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}
