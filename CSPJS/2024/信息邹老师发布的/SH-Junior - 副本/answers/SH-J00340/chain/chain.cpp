#include<bits/stdc++.h>
using namespace std;
int T; 
int n,k,q;
int r,c;
const int N=1e5+10;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		int l[N],S[1010][1010],tj[N];
		for(int j=1;j<=n;j++){
			cin>>l[j];
			for(int k=1;k<=l[j];k++){
				cin>>S[j][k];
				tj[S[j][k]]++;
			}
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			if(tj[c]==0){
				cout<<0<<'\n';
				continue;
			}
			else if(r==1){
				int cnt=0,f=0;
				for(int k=1;k<=l[1];k++){
					if(S[k]==c){
						cnt++;
						break;
					}
					if(S[k]==1) f=1;
					if(f==1) cnt++;
				}
				if(cnt>k||cnt==1) cout<<0<<'\n';
			}
			else cout<<1<<'\n';
		}
	}
	return 0;
}
