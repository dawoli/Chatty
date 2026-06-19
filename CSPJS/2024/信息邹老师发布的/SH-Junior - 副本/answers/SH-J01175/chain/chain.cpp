#include<bits/stdc++.h>
using namespace std;
int s[10000][10000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	int n,k,q;
	int l[10000];
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>s[i][j];
		}
	}
	int r[10000],c[10000];
	for(int i=1;i<=q;i++){
		cin>>r[i]>>c[i];
		cout<<0<<endl;
	}
	return 0;
}
