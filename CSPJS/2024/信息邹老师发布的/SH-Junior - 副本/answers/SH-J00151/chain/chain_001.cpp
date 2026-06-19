#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q,a[1009];
		memset(a,0,sizeof(a));
		cin>>n>>k>>q;
		while(n--){
			int l;
			cin>>l;
			while(l--){
				int x;
				cin>>x;
				a[x]++;
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			if(a[c]!=0)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	return 0;
}
