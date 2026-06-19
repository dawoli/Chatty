#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,s[1010][2010],l[20010],r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(k<=5&&r>1){
				cout<<0<<endl;
				continue;
			}
			if(r>1){
				cout<<1<<endl;
				continue;
			}
			if(r==1){
				int ans=0;
				for(int j=1;j<=n;j++){
					for(int jj=1;jj<=l[j]-1;jj++){
						if(s[j][jj]==1)for(int jjj=jj+1;jjj<=l[j]&&jjj<=jj+k-1;jjj++){
							if(s[j][jjj]==c){
								ans=1;
								break;
							}
						}
						if(ans==1)break;
					}
					if(ans==1)break;
				}
				cout<<ans<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
