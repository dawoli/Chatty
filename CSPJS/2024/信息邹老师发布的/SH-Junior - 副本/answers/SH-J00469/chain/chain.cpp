#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=0;i<q;i++){
			cout<<rand()%2<<"\n";
		}
	}
	return 0;
}
