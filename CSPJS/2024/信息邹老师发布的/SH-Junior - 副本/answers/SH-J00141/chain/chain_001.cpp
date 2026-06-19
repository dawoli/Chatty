#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l,x,r,c,flag;
bool vis[200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			flag=0;
			for(int j=1;j<=l;j++){
				cin>>x;
				if(x==1){
					if(flag>0)
						vis[1]=1;
					flag=k-1;
				}
					
				else if(flag>0){
					vis[x]=1;
					flag--;
				}
					
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			cout<<vis[c]<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
