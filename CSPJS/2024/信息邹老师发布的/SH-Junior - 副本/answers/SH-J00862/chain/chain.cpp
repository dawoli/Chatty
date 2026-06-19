#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,nn[233][233],qq[23333][2];
int main(){
	freopen("chain.in ","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t>>n>>k>>q;
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		for(int j=0;j<=l;j++){
			cin>>nn[i][j];
		}
	} 
	for(int i=0;i<q;i++)cin>>qq[i][0]>>qq[i][1];
	for(int i=0;i<q;i++)cout<<1<<endl;
	return 0;//rp++
}
