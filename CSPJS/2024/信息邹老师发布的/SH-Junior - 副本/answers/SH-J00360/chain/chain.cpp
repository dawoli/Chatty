#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
int l[1005];
int s[1005][2005];
int r,c;
int flag;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			cin>>l[j];
			for(int a=1;a<=l[j];a++){
				cin>>s[j][a];
			}
		}
		for(int j=1;j<=q;j++){
			flag=0;
			cin>>r>>c;
			if(r==1){
				for(int a=1;a<=n;a++){
					for(int b=1;b<=l[a];b++){
						if(s[a][b]==1){
							for(int x=1;x<=k;x++){
								if(s[a][b+x]==c){
									flag=1;
								}
							}
						}
					}
				}
				if(flag==0){
					cout<<0<<endl;
				}
				if(flag==1){
					cout<<1<<endl;
				}
			}
			else{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
