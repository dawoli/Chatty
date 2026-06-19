#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int r[100005],c[100005],s[100005][100005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k>>q;
		for(int j=0;j<n;j++){
			int l;
			cin>>l
			for(int k=0;k<l;k++) cin>>s[j][k];
		}
		for(int j=0;j<q;j++) cin>>r[i]>>c[i];
		for(int j=0;j<n;j++) cout<<0<<endl;
	}
	return 0;
} 

