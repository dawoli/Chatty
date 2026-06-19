#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
void solve(){
	ll n,k,q,l[100009],r[100009],c[100009],S[100009][200009];
	cin>>n>>k>>q;
	for(int i=0;i<=n-1;i++){
		cin>>l[i];
		for(int j=0;j<=l[i]-1;j++){
			cin>>S[i][j];
		}
	}
	for(int i=0;i<=q-1;i++){
		ll r,c,ii=n,cc=1;
		bool b;
		cin>>r>>c;
		for(int j=0;j<=r-1;j++){
			b=0;
			for(int m=0;m<=n-1;m++){
				if(m==ii){
					continue;
				}
				for(int o=0;o<=l[i]-1;o++){
					if(S[m][o]==cc){
						for(int p=2;p<=k;p++){
							ii=m;
							cc=S[m][o+p];
							b=1;
							break;
						}
					}
					if(b==1)
						break;
				}
				if(b==1)
					break;
			}
			if(j==r-1&&cc==c){
				cout<<1<<endl;
				return;
			}
		}
	}
	cout<<0<<endl;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int a=0;a<=T-1;a++)
		solve();
	return 0;
}
