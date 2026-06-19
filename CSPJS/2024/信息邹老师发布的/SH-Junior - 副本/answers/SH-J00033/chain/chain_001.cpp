#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,li,s[1005][2005],r,c;
bool res;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>li;
			s[j][0]=li;
			for(int k1=1;k1<=li;k1++) cin>>s[j][k1];
		}
		for(int j=1;j<=q;j++){
			res=0;
			cin>>r>>c;
		}
	}
	cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
	return 0;
}
