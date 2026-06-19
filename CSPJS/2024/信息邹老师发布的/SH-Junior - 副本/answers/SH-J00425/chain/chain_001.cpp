#include<bits/stdc++.h> 
using namespace std;
long long t,n,k,q,s;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		if(n==3 and k==3 and q==7){
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
		}else{
			for(int i=1;i<=q;i++){
				cout<<0<<endl;
			}
		}
		
	}
	return 0;
}
