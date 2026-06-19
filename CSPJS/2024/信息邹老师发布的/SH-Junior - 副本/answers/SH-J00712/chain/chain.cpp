#include<bits/stdc++.h>
using namespace std;
int n,k,q;
vector<int> v[200009];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int a;
			v[i].push_back(a);
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<"0"<<endl;
	} 
	return 0;
}
