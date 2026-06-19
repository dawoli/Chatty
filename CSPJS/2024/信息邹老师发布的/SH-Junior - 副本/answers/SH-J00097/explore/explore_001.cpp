#include <bits/stdc++.h>
using namespace std;
//zouguo
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int n,m;
	long long k;
	int x,y,d;
	long long ans;
	for (int q=0;q<t;q++){
		
		
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		bool a[1005][1005]={0};//zhangai
		bool b[1005][1005]={0};

		
		for (int i=1;i<n+1;i++){
			char p[m];
			cin>>p;
			for (int j=1;j<m+1;j++){
				if (p[j-1]=='.'){
					a[i][j]=1;
				}
			}
		}
		
		
		
		ans=1;
		b[x][y]=1;
		for (long long i=0;i<k;i++){
			//cout<<1<<endl;
			if (d==0){
				if ((y+1<=m)&&(a[x][y+1])){
					if(b[x][y+1]==0){
						b[x][y+1]=1;
						ans++;
						//cout<<x<<" "<<y+1<<endl; 
					}y+=1;}
				else{
					d=(d+1)%4;
				}}
			
			else if (d==1){
				if ((x+1<=n)&&(a[x+1][y])){
					if(b[x+1][y]==0){
						b[x+1][y]=1;
						ans++;
						//cout<<x+1<<" "<<y<<endl; 
					}x+=1;}
				else{
					d=(d+1)%4;
				}}	
			
			else if (d==2){
				if ((y-1>=0)&&(a[x][y-1])){
					if(b[x][y-1]==0){
						b[x][y-1]=1;
						ans++;
						//cout<<x<<" "<<y-1<<endl; 
					}y-=1;}
				else{
					d=(d+1)%4;
				}	
			}
			else if (d==3){
				if ((x-1>=0)&&(a[x-1][y])){
					if(b[x-1][y]==0){
						b[x-1][y]=1;
						ans++;
						//cout<<x-1<<" "<<y<<endl; 
					}x-=1;}
				else{
					d=(d+1)%4;
				}	
			}
			
		}
		
		cout<<ans<<endl;	
	} 
	
	return 0;
}
