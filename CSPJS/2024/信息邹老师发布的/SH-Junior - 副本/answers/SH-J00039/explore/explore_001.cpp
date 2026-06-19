#include <bits/stdc++.h>
using namespace std;
    int t,n[6],m[6],k[6],x[6],y[6],d[6],ans[6];
    char fmap[6][1001][1001],h[6][1001][1001];
    int main(){
    	freopen ("explore.in","r",stdin);
    	freopen ("explore.out","w",stdout);
    	cin>>t;
    	for (int i=1;i<=t;i++){
    		cin>>n[i]>>m[i]>>k[i];
    		cin>>x[i]>>y[i]>>d[i];
    		for (int j=1;j<=n[i];j++){
    			for (int q=1;q<=m[i];q++){
    				cin>>fmap[i][j][q];
				}
			}
		}
		for (int i=1;i<=t;i++){
			int a=x[i],b=y[i];
			h[i][a][b]=1;
			ans[i]=1;
    				while (k[i]){
    					if (d[i]==0){
    						if (b+1<=m[i] and fmap[i][a][b+1]=='.'){
    							b++;
    							if (h[i][a][b]==0){
    								ans[i]++;
    								h[i][a][b]=1;
								}
							}
							else d[i]=(d[i]+1)%4;
							k[i]--;
						}
						else if (d[i]==1){
							if (a+1<=n[i] and fmap[i][a+1][b]=='.'){
    							a++;
    							if (h[i][a][b]==0){
    								ans[i]++;
    								h[i][a][b]=1;
								}
							}
							else d[i]=(d[i]+1)%4;
							k[i]--;
						}
						else if (d[i]==2){
							if (b-1>=1 and fmap[i][a][b-1]=='.'){
    							b--;
    							if (h[i][a][b]==0){
    								ans[i]++;
    								h[i][a][b]=1;
								}
							}
							else d[i]=(d[i]+1)%4;
							k[i]--;
						}
						else{
							if (a-1>=1 and fmap[i][a-1][b]=='.'){
    							a--;
    							if (h[i][a][b]==0){
    								ans[i]++;
									h[i][a][b]=1;
								}
								}
							else d[i]=(d[i]+1)%4;
							k[i]--;
						}
						}
					}
		for (int i=1;i<=t;i++){
			cout<<ans[i];
			if (i!=t) cout<<endl;
		}
    	return 0;
	}
