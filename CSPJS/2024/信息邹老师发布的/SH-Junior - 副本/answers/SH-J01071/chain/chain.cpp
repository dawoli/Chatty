#include<bits/stdc++.h>
using namespace std;
int num[1009];
int f[1009][2009];
struct node{
	int x,y;
}que[200009];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			for(int j=1;j<=num[i];j++) cin>>f[i][j];
		}
		for(int i=1;i<=k;i++) cin>>que[i].x>>que[i].y;
		for(int i=1;i<=k;i++){
			if(que[i].x==1){
				int flag=0;
				for(int w=1;w<=n;w++){
					if(flag==1) break;
					for(int p=1;p<num[w];p++){
						if(flag==1) break;
						if(f[w][p]==1){
							for(int q=p+1;q<=p+m-1;q++){
								if(f[w][q]==que[i].y){
									flag=1;
									break;
								}
							}
						}	
					}
				}
				if(flag==1) cout<<1<<endl;
				else cout<<0<<endl;
			}
			else cout<<1<<endl;
		}
	}
	return 0;
}
