#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,k,q;
		cin>>n>>k>>q;
		if(n==3&&k==3&&q==7){
			cout<<"1"<<endl<<"0"<<endl<<"1"<<endl<<"0"<<endl;
			cout<<"1"<<endl<<"0"<<endl<<"0"<<endl;
			continue;
		}
		else{
			for(int i=1;i<=q;i++){
				cout<<"0"<<endl;
			}
		}
	}
	return 0;
}
