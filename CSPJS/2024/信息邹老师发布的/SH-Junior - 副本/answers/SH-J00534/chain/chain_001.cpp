#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l;
long long a[100000][200000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>l;
			for(int j=0;j<l;j++){
				cin>>a[i][j];
			}
		}
		const int Q=q;
		int r[Q][2];
		for(int i=0;i<q;i++){
			cin>>r[i][0]>>r[i][1];
		}
	}
	return 0;
}
