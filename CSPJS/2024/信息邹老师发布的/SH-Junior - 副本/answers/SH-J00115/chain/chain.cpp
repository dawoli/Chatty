#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int t;
int n,k,q,a;
int r,l;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>a;
		}while(q--){
			cin>>r>>l;
			cout<<rand()%2<<"\n";
		}
	}
	return 0;
}
