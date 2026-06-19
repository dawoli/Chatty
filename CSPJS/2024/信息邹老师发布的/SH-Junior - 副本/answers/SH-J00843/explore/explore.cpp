#include<bits/stdc++.h>
using namespace std;
bool goon[1003][1003];
void out(int n,int m){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(goon[i][j]==true){
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	return ;
}
char mapi[1003][1003];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    	int n,m,k,x0,y0,d;
    	cin>>n>>m>>k>>x0>>y0>>d;
    	goon[x0][y0]=true;
    	for(int j=1;j<=n;j++){
    		for(int p=1;p<=m;p++){
    			cin>>mapi[j][p];
			}
		}
		int nx,ny;
		for(int j=1;j<=k;j++){
			nx=x0;ny=y0;
			if(d==0) ny=y0+1;
			else if(d==1) nx=x0+1;
			else if(d==2) ny=y0-1;
			else nx=x0-1;
			if(nx<1 or nx>n or ny<1 or ny>m or mapi[nx][ny]=='x'){
				d=(d+1)%4;
		    	if(d==0) ny=y0+1;
			    else if(d==1) nx=x0+1;
			    else if(d==2) ny=y0-1;
			    else nx=x0-1;
			}
			else{
				goon[nx][ny]=true;
			    x0=nx;y0=ny;
			}
		}
	    out(n,m);
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

