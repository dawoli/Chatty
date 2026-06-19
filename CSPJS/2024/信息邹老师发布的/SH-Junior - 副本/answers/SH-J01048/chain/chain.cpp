#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,q,l[100010],s[1010][2010],r,c,ans[200010];
signed main(){
	freopen("chian.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		memset(ans,0,sizeof(ans));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			int it=0;
			for(int j=1;j<=l[i];j++){
				it--;
				cin>>s[i][j];
				if(s[i][j]==1)it=k;
				if(it>0)ans[s[i][j]]=1;
			}
		}
		while(q--){
			cin>>r>>c;
			if(ans[c])cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
