#include<iostream>
#include<cstdio>
using namespace std;
FILE* fin=freopen("explore.in","r",stdin);
FILE* fout=freopen("explore.out","w",stdout);
bool visited[1001][1001];
bool ground[1001][1001];
int n,m,k,x,y,d;
void movee(){
	for (int i=1;i<=k;i++){
		if (d==0){
			if(y+1<=m&&ground[x][y+1]){
				visited[x][y+1]=true;
				y++;
			}
			else{
				d++;
			}
			continue;
		}
		if (d==1){
			if(x+1<=n&&ground[x+1][y]){
				visited[x+1][y]=true; 
				x++;
			}
			else{
				d++;
			}
			continue;
		}
		if (d==2){
			if(ground[x][y-1]&&y-1>0){
				visited[x][y-1]=true; 
				y--;
			}
			else{
				d++;
			}
			continue;
		}
		if (d==3){
			if(ground[x-1][y]&&x-1>0){
				visited[x-1][y]=true;
				x--;
			}
			else{
				d=0;
			}
			continue;
		}
	}
} 
int main(){
	int T;
	cin>>T;
	int ans;
	for (int i=1;i<=T;i++){
		cin>>n>>m>>k>>x>>y>>d;
		getchar();
		char temp;
		ans=0;
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				temp=getchar();
				if (temp=='.')ground[j][k]=true;
				else ground[j][k]=false;
			}
			getchar();
		} 
		visited[x][y]=true;
		movee();
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				if(visited[j][k]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				visited[j][k]=false;
			}
		}
	}
	return 0;
}
