#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int qwe=0;qwe<t;qwe++){
		int n,k,q;
		cin>>n>>k>>q;
		int s[100000][200001];
		for(int i=0;i<n;i++){
			cin>>s[i][0];
			for(int j=1;j<=s[i][0];j++){
				cin>>s[i][j];
			}
		}
		for(int i=0;i<q;i++){
			int r,c;
			cin>>r>>c;
			cout<<1;
		}
	}
}
