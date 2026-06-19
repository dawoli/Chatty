#include<bits/stdc++.h>
using namespace std;

int t,n,k,q,s[1010][2010],l[100010],r,c,f;

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
		for(int i=1;i<=n;i++){
			cin>>r>>c;
			if(r==1){
				f=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=l[i];j++){
						if(s[i][j]==1){
							for(int z=j+1;z<=l[i];z++){
								if(s[i][z]==c && z-j+1<=k){
									f=1;
									break;
								}
							}
							if(f==1){
								break;
							}
						}
					}
					if(f==1){
						break;
					}
				}
				cout<<f<<endl;
			}
		}
	}
	return 0;
}
