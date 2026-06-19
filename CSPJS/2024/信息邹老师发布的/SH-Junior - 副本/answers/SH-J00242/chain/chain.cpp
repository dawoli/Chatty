#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int l[1003][1003],T;
int r,c,ans;
int dfs(int num,int lst,int c2){
	if (c2==r+1){
		if (num==c)ans=1;
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (i!=lst){
			for (int j=1;j<=l[i][0];j++){
				if (l[i][j]==num){
					for (int k2=1;k2<=k-1;k2++){
						if (j+k2<=l[i][0])dfs(l[i][j+k2],i,c2+1);
					}
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	memset(l,0,sizeof(l));
	cin>>T;
	for (int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for (int j=1;j<=n;j++){
			int m;
			cin>>m;
			l[j][0]=m;
			for (int k=1;k<=m;k++){
				cin>>l[j][k];
			}
		}
		for (int j=1;j<=q;j++){
			ans=0;
			cin>>r>>c;
			dfs(1,0,1);
			cout<<ans<<endl;
		}	
	}
	return 0;
}
