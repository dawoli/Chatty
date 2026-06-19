#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
bool a[1003][1003],yet[1003][1003];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t){
		cin>>n>>m>>k>>x>>y>>d;
		
		int ans=1;
		yet[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
		    	char l;
		    	cin>>l;
			    if(l=='x')a[i][j]=1;
		    	else a[i][j]=0;
		    }	
		}
		int nx,ny;
		while(k){
			if(d==0){
				nx=x;ny=y+1;
			} 
			else if(d==1){
				nx=x+1;ny=y;
			} 
			else if(d==2){
				nx=x;ny=y-1;
			}
			else{
				nx=x-1;ny=y;
			} 
		    if(!a[nx][ny]&&nx<=n&&nx>=1&&ny<=m&&ny>=1){
		    	x=nx;y=ny;
		    	if(yet[x][y]==0){
		        	ans++;
		        //	cout<<x<<" "<<y<<"k="<<k<<endl;
					yet[x][y]=1;	
				}k--;
		    //	cout<<x<<" "<<y<<"k="<<k<<endl;
			}else{
				d=(d+1)%4;
				k--;
			//	cout<<d<<"k="<<k<<endl;
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
