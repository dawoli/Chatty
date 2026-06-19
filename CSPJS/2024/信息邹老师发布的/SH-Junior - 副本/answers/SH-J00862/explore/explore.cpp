#include <bits/stdc++.h>
using namespace std;
int n,m,t,xx,yy,dd;
char ditu[1000][1000];
long long k;
int fx[233]={1,0,-1,0};
int fy[233]={0,1,0,-1};
int ans[23333];
int main(){
	freopen("explore.in ","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	int pp=0;
	while(t--){
		cin>>n>>m>>k;
		cin>>xx>>yy>>dd;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>ditu[i][j];
			} 
		}
		ditu[xx][yy]='l';
		for(int i=0;i<k;i++){
			if(ditu[xx+fx[dd]][yy+fy[dd]]=='.'||ditu[xx+fx[dd]][yy+fy[dd]]=='l'){
				xx+=fx[dd];
				yy+=fy[dd];
				ditu[xx][yy]='l';
			}else{
				dd+=1;
				dd%=4;
				i--; 
			} 
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if (ditu[i][j]=='l')cnt++;
			}
		} 
		ans[pp]=k;
		pp++;
	}
	for(int i=0;i<pp;i++)cout<<ans[i]<<endl;
	return 0;
}
