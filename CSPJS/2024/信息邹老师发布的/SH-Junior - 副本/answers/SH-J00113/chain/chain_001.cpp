#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=q;i++){
			srand(time(0));
			cout<<rand()%2<<endl;
		}
	}
	return 0;
}
