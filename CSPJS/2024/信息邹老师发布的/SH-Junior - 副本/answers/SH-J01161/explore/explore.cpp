#include<bits/stdc++.h>
using namespace std;
int t,ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
	    ans=1;
		int n,m,k;
		cin>>n>>m>>k;
		char r[n+5][m+5];
		int x[n+5],y[m+5],d[n*m+5];
		cin>>x[0]>>y[0]>>d[0];
		for(int j=1;j<=n;j++){
			for(int f=1;f<=m;f++){
				cin>>r[j][f];
			}
		}
		for(int j=0;j<k;j++){
			if(d[j]==0){
			    x[j+1]=x[j];
				if(r[x[j]][y[j]+1]=='.'){
				    y[j+1]=y[j]+1;
				    d[j+1]=d[j];
				    ans++;
				    r[x[j]][y[j]]=',';
				}else if(r[x[j]][y[j]+1]==','){
					y[j+1]=y[j]+1;
				    d[j+1]=d[j];
				}else{
					d[j+1]=(d[j]+1)%4;
					y[j+1]=y[j];
				}
			}if(d[j]==2){
			    x[j+1]=x[j];
				if(r[x[j]][y[j]-1]=='.'){
				    y[j+1]=y[j]-1;
				    d[j+1]=d[j];
				    ans++;
				    r[x[j]][y[j]]=',';
				}else if(r[x[j]][y[j]-1]==','){
					y[j+1]=y[j]-1;
				    d[j+1]=d[j];
				}else{
					d[j+1]=(d[j]+1)%4;
					y[j+1]=y[j];
				}
			}if(d[j]==1){
			    y[j+1]=y[j];
				if(r[x[j]+1][y[j]]=='.'){
				    x[j+1]=x[j]+1;
				    d[j+1]=d[j];
				    ans++;
				    r[x[j]][y[j]]=',';
				}else if(r[x[j]+1][y[j]]==','){
					x[j+1]=x[j]+1;
				    d[j+1]=d[j];
				}else{
					d[j+1]=(d[j]+1)%4;
					x[j+1]=x[j];
				}
			}if(d[j]==3){
			    y[j+1]=y[j];
				if(r[x[j]-1][y[j]]=='.'){
				    x[j+1]=x[j]-1;
				    d[j+1]=d[j];
				    ans++;
				    r[x[j]][y[j]]=',';
				}else if(r[x[j]-1][y[j]]==','){
					x[j+1]=x[j]-1;
				    d[j+1]=d[j];
				}else{
					d[j+1]=(d[j]+1)%4;
					x[j+1]=x[j];
				}
			}
		}
		cout<<ans;
		
	}
	return 0;
}
