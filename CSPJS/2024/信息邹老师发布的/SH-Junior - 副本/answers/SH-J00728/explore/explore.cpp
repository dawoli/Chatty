#include<iostream>
using namespace std;
int t;
int ans;
int Map[1009][1009];
int vis[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int f=0;f<t;f++){
		long long k;
		ans=1;
		int n,m;
		cin>>n>>m>>k;
		
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=1;j<=m;j++){
				Map[i][j]=s[j-1];
			}
		}
		int nx=x0;
		int ny=y0;
		for(int i=0;i<k;i++){
			if(d0==0){
				ny++;
				if(Map[nx][ny]=='.'){
				
						ans++;
					
				}else{
					ny--;
					d0=(d0+1)%4;
				}
			}else if(d0==1){
				nx++;
				if(Map[nx][ny]=='.'){
					
				
						ans++;
					
				}else{
					nx--;
					d0=(d0+1)%4;
				}
			}else if(d0==2){
				ny--;
				if(Map[nx][ny]=='.'){
					
				
						ans++;
					
				}else{
					ny++;
					d0=(d0+1)%4;
				}
			}else if(d0==3){
				nx--;
				if(Map[nx][ny]=='.'){
					
					
					
						ans++;
					
				}else{
					nx++;
					d0=(d0+1)%4;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
