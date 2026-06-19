#include <bits/stdc++.h>
using namespace std;

int t,n,k,q,l[1005],s[1005][2005],r,c;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		while(q--){
			cin>>r>>c;
			int mn=0x3f3f3f3f;
			for(int i=1;i<=n;i++){
				bool flag=false;
				int last;
				for(int j=1;j<=l[i];j++){
					if(s[i][j]==1){
						flag=true;
						last=j;
					}else if(flag&&s[i][j]==c){
						mn=min(mn,j-last+1);
					}
				}
			}
			if(mn<=k){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
