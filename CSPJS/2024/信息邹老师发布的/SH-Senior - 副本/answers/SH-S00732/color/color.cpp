#include<bits/stdc++.h>
using namespace std;
long long T,x,n,col[1000002]={},vis[1000002],last;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(vis,0,sizeof(vis));
		long long rr=0,br=0,rrindex=0,brindex=0;
		cin>>n;
		long long lianxu;
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x==rr){
				rrindex=j;
				col[j]=col[j-1]+x;
			}else if(x==br){
				brindex=j;
				col[j]=col[j-1]+x;
			}else if(vis[x]){
				if(vis[x]>rrindex||vis[x]>brindex){
					col[j]=col[j-1]+x;
					if(rrindex>brindex){
						brindex=j;
						br=x;
					}else{
					    rrindex=x;	
					    rr=x;
					} 
				}else if(vis[x]==rrindex-1){
					col[j]=col[j-1]+x;
					rr=x;
					rrindex=j;
				}else if(vis[x]==brindex-1){
					col[j]=col[j-1]+x;
					br=x;
					brindex=j;
				}else if(x>col[j-1]-col[vis[x]]){
					col[j]=col[j-1]-col[vis[x]]+x;
					if(rrindex>brindex){
						brindex=j;
						br=x;
					}else{
					    rrindex=j;
					    rr=x;
					} 
				}
			}else{
				col[j]=col[j-1];
			}
			vis[x]=j;
			cout<<col[j]<<endl;
		}
		cout<<col[n]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
