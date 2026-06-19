#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,r,c;
int l[100005],s[1003][2003];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
			}
		}
		while(q--){
			cin>>r>>c;
			if(r==1){
				int flag=0,pos1=0;
				for(int i=1;i<=n;i++){
					pos1=0;flag=0;
					for(int j=1;j<=l[i];j++){
						if(s[i][j]==1)pos1=j;
						if(s[i][j]==c && pos1 && j-pos1+1<=k){
							cout<<"1\n";flag=1;break;
						}
					}
					if(flag)break;
				}
				if(!flag)cout<<"0\n";
			}else {
				for(int i=1;i<=n;i++){
					for(int j=1;j<=l[i];j++){
						
					}
				}
			}
		}
	}
	return 0;
}
