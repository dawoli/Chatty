#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,r,c,l[1010];
int s[1010][200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>k>>q;
		for(int j=1;i<=n;i++){
			cin>>l[j];
			for(int m=1;m<=l[j];m++){
				cin>>s[j][m];
			}
		}
		for(int j=1;j<=q;j++){
			bool flag=0;
			cin>>r>>c;
			for(int m=1;m<=n;m++){
				for(int x=1;x<=l[m];x++){
					for(int y=x;y<=l[m];y++){
						if(s[m][x]==1&&s[m][y]==c&&y-x+1){
							flag=1;
						}
					}
				}
			}
			if(flag){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
