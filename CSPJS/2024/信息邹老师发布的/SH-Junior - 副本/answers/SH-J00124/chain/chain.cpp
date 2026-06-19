#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10,inf=1e7+10;
int t,n,k,q,l[inf],r,c;
int a[maxn][maxn];
bool flag,flag2;
inline void solve(){
	flag2=0;
	for(register int i=1;i<=n;i++){
		if(l[i]>=k&&l[i]>=1){
			flag2=1;
		}
	}
	if(!flag2){
		cout<<"0\n";
	}
	else{
		cout<<"1\n";
	}
	return ;
}
signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		flag=0;
		for(register int i=1;i<=n;i++){
			cin>>l[i];
			if(l[i]>=maxn||n>=maxn){
				flag=1;
			}
			for(register int j=1;j<=l[i];j++){
				cin>>a[i][j];
			}
		}
		for(register int i=1;i<=q;i++){
			cin>>r>>c;
			if(flag){
				cout<<"0\n";
				continue;
			}
			solve();
		}
	}
	return 0;
}
