#include<bits/stdc++.h>
using namespace std;
//vector<int> a[100010];
int a[1010][2010],l[1010];
int tr[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T; cin>>T;
	for(int x=1;x<=T;x++){
		memset(tr,0,sizeof(tr));
		int n,k,q; cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			int jyes;
			bool t=0;
			for(int j=1;j<=l[i];j++){
				cin>>a[i][j];
				if(t&&j-jyes<=k-1) tr[a[i][j]]++;
				if(a[i][j]==1) t=1,jyes=j;
			}
		}
		while(q>0){
			int r,c; cin>>r>>c;
			if(r==1){
				if(tr[c]) cout<<1;
				else cout<<0;
			}
			else{
				if(tr[c]>=r) cout<<1;
				else cout<<0;
			}
			cout<<endl;
			q--;
		}
	}
	return 0;
}

