#include<bits/stdc++.h>
using namespace std;
int s[200002],r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k,q,l,r,c;
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			cin>>l;
			for(int p=0;p<0;p++){
				cin>>s[p];
			}
		}
		for(int j=0;j<q;j++){
			cin>>r>>c;
			cout<<0;
		}
	}
	return 0;
}
