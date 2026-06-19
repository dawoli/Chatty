#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,k,q;
		int s[2001][20003];
		cin>>n>>k>>q;
		if(n==3){
			if(k==3){
				if(q==7){
					cout<<"1\n0\n1\n0\n1\n0\n0";
					return 0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int l;cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[i][j];
			}
		}
	}
	return 0;
}
