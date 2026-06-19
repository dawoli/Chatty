#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t,n,m,k;
	int x,y,d,zh;
    int d1[4]={0,1,0,-1},d2[4]={1,0,-1,0};
    char a[1003][1003]={};
	bool b[1003][1003]={};
    cin>>t;
    for(int ii=0;ii<t;ii++){
    	cin>>n>>m>>k;
    	cin>>x>>y>>d;
    	zh=0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cin>>a[i][j];
    			b[i][j]=0;
			}
		}b[x][y]=1;
		for(int i=0;i<k;i++){
			if(x+d1[d]>n||x+d1[d]<1){
				d=(d+1)%4;
				continue;
			}if(y+d2[d]>m||y+d2[d]<1){
				d=(d+1)%4;
				continue;
			}if(a[x+d1[d]][y+d2[d]]=='x'){
				d=(d+1)%4;
				continue;
			}else{
				b[x+d1[d]][y+d2[d]]=1;
				x=x+d1[d];
				y=y+d2[d];
			}
		}for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			if(b[i][j]==1){
    				zh++;
				}
			}
		}cout<<zh<<endl;
	}
    
	return 0;
}
