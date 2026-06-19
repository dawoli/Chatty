#include<bits/stdc++.h>
using namespace std;
int mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
int a[1001][1001]={};
int visited[1001][1001]={};
int n,m,k,t,x,y,d,ans=0;
char mystr;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		visited[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mystr;
				if(mystr=='.'){
					a[i][j]=0;
				}
				else{
					a[i][j]=1;
				}
			}
		}
		for(int i=1;i<=k;i++){
			if(a[x+mx[d]][y+my[d]]==0&&x+mx[d]>=1&&x+mx[d]<=n&&y+my[d]>=1&&y+my[d]<=m){
				x=x+mx[d];
				y=y+my[d];
				visited[x][y]=1;
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(visited[i][j]==1){
					ans++;
				}
				visited[i][j]=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
