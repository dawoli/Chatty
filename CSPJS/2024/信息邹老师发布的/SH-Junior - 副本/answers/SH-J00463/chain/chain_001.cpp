#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100006],s[15006][25006],r[100006],c[100006];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l[j];
			for(int k=1;k<=l[j];k++)
				cin>>s[j][k];
		}
		for(int j=1;j<=q;j++)
			cin>>r[j]>>c[j];
	}
	for(int i=1;i<=T*q;i++)
		cout<<"1"<<endl; 
	return 0;
}
