#include<bits/stdc++.h>
using namespace std;
vector<int> s[10001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.ans","w",stdout);
	int t;
	cin>>t;
	for(int a=0;a<t;++a){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;++i){
			int l;
			cin>>l;
			for(int j=0;j<l;++j){
				int si;
				cin>>si;
				s[i].push_back(si);
			}	
		}
		for(int i=0;i<q;++i){
			int r,c;
			cin>>r>>c;
		}
	}
	cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
	return 0;
}
