#include<bits/stdc++.h>
using namespace std;
char ex[1005][1005]={};
bool qg[1005][1005]={};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);	
	int t;
	long long sum=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long sum=0;
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		char ex[1005][1005]={};
		bool qg[1005][1005]={};
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>ex[j][l];
			}
		}
		int xx,yy,fx;
		xx=x,yy=y,fx=d;
		qg[xx][yy]=1;
		sum++;
		for(int f=1;f<=k;f++){
			if(fx==0){
				if(xx>=1 && xx<=n && yy+1>=1 && yy+1<=m && ex[xx][yy+1]=='.'){
					xx=xx;
					yy=yy+1;
					if(qg[xx][yy]==0){
						sum++;
					    qg[xx][yy]=1;						
					}
				}
				else{
					fx=(fx+1)%4;
				}				
			}
			if(fx==1){
				if(xx+1>=1 && xx+1<=n && yy>=1 && yy<=m && ex[xx+1][yy]=='.'){
					xx=xx+1;
					yy=yy;
					if(qg[xx][yy]==0){
						sum++;
					    qg[xx][yy]=1;											
					}
				}
				else{
					fx=(fx+1)%4;
				}				
			}
			if(fx==2){
				if(xx>=1 && xx<=n && yy-1>=1 && yy-1<=m && ex[xx][yy-1]=='.'){
					xx=xx;
					yy=yy-1;
					if(qg[xx][yy]==0){
						sum++;
					    qg[xx][yy]=1;												
					}
				}
				else{
					fx=(fx+1)%4;
				}					
			}
			if(fx==3){
				if(xx-1>=1 && xx-1<=n && yy>=1 && yy<=m && ex[xx-1][yy]=='.'){
					xx=xx-1;
					yy=yy;
					if(qg[xx][yy]==0){
						sum++;
					    qg[xx][yy]=1;												
					}
				}
				else{
					fx=(fx+1)%4;
				}					
			}									
		}
		cout<<sum<<endl;
	}
	return 0;
}
