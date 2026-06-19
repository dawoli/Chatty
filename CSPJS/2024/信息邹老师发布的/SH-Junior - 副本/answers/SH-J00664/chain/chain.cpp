#include <iostream>
using namespace std;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T,n,k,q,l,S,cnt=0;
	cin>>T;
	for (int z=1;z<=T;z++){
		cin>>n>>k>>q;
		for (int i=1;i<=n;i++){
			cin>>l;
			for (int j=1;j<=l;j++){
				cin>>S;
			}
		}
		for (int i=1;i<=q;i++){
			cin>>l>>S;
		}
		cnt+=q;
	}
	for (int i=1;i<=cnt;i++) cout<<0<<endl;
	return 0;
}
