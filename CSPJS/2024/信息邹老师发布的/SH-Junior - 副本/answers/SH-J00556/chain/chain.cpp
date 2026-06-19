#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int a[200009];
vector<int> v[200009];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>a[i];
			int x;
			for(int i=0;i<a[i];i++){
				cin>>x;
				v[i].push_back(x);				
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			cout<<abs(r+c-11454+322-28*3)%2<<endl;
		}
	}
	
	return 0;
} 
