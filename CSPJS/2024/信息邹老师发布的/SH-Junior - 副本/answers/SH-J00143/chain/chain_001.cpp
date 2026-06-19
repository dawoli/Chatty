#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,k,q,r,c,len,x;
vector<int> s[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>len;
			for(int i=0;i<len;i++){
				cin>>x;
				s[i].push_back(x);
			}
		}
		for(int i=0;i<q;i++){
			cin>>r>>c;
		}
	}
	return 0;
}
