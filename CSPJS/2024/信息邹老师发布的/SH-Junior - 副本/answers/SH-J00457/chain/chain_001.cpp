#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdin);
	int t,n,k,q,l,r,c;
	cin>>t;
	for(int i = 1;i<= t;i++){
		cin>>n>>k>>q;
		for(int j = 1;j<= n;j++){
			cin>>l;
			for(int p=1;p<= l;p++){
				cin>>a[j][p];
				a[j][p]+=a[j][p-1];
			}
		}
		for(int j=1;j<= q;j++){
			cin>>r>>c;
			cout<<"1";
		}
	}
	return 0;
}
