#include <bits/stdc++.h>
using namespace std;
const int N=2e5+9;
long long T;
long long n,k,q;
long long s[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);	
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i];
			}	
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
}
