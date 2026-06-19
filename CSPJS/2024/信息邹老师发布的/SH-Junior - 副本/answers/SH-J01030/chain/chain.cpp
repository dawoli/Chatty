#include<iostream>
using namespace std;
const int N=2020;
int t,n,q,k,l;
vector<int> S[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int tes=1;tes<=t;tes++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++) S[i].clear();
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				int a; cin>>a;
				S[i].push_back(a);
			}
		}
		for(int i=1;i<=q;i++){
			int r,c; cin>>r>>c;
			
		}
	}
} 
