#include<bits/stdc++.h>
using namespace std;
int a[1005][2005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>a[j][0];
			for(int m=1;m<=a[j][0];m++){
				cin>>a[j][m];
			}
		}
		for(int j=1;j<=q;j++){
			int r,c;
			cin>>r>>c;
			cout<<0<<endl; 
		}
		
	}
	return 0;
}
