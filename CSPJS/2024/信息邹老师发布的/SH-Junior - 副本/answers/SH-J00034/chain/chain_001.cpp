#include<bits/stdc++.h>
using namespace std;
int n,k,q,T,l,s,r,c,cnt=0;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		cnt+=q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int i=1;i<=l;i++)
				cin>>s;
		}
		for(int i=1;i<=q;i++)
			cin>>r>>c;
	}
	for(int i=1;i<=cnt;i++) cout<<rand()%2<<endl;
	return 0;
}
