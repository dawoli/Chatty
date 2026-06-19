#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[10010][10010],c[10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(w,-1,sizeof(w));
	for(int i=0;i<m;i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		w[ui][vi]=wi;
		w[vi][ui]=wi;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>w[i+n][j];
			w[j][i+n]=w[i+n][j];
		}
	}
	int ans=0;
	if(c[0]==0){
		int visited[10010];
		memset(visited,0,sizeof(visited));
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				if(w[i+n][j]==0){
					visited[i+n]++;
					visited[j]++;
				}
			} 
		}
		for(int i=0;i<n+k;i++){
			if(!visited[i]){
				int mn=1000000000,minj;
				for(int j=0;j<n+k;j++){
					if(w[i][j]!=-1&&visited[j]<2&&w[i][j]<mn){
						mn=w[i][j];
						minj=j;
					}
				}
				visited[minj]++;
				ans+=mn;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
