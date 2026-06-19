#include<fstream>
#include<string>
std::ifstream fin("explore.in");
std::ofstream fout("explore.out");
bool used[5][1005][1005];
char ma[5][1005][1005];
int main(){
	int t;
	fin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k;
		fin>>n>>m>>k;
		int x,y,d;
		fin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			std::string s;
			fin>>s;
			for(int k=1;k<=m;k++){
				ma[i][j][k]=s[k-1];
			}
		}
		int cnt=1;
		used[i][x][y]=1;
		while(k>0){
			if(d==0) {
				y=y+1;
				if(x>=1&&x<=n&&y>=1&&y<=m&&ma[i][x][y]=='.'){
					if(used[i][x][y]==0) {
						used[i][x][y]=1;
						cnt++;
						//cout<<k;
					}
				}
				else {
					d=(d+1)%4;
					y=y-1;
					//cout<<k<<" ";
				}
				k--;
			}
			else if(d==1){
				x=x+1;
				if(x>=1&&x<=n&&y>=1&&y<=m&&ma[i][x][y]=='.'){
					if(used[i][x][y]==0) {
						used[i][x][y]=1;
						//cout<<k<<"\n";
						cnt++;
					}
				}
				else {
					d=(d+1)%4;
					x=x-1;
					//cout<<k<<" ";
				}
				k--;
			}
			else if(d==2){
				y=y-1;
				if(x>=1&&x<=n&&y>=1&&y<=m&&ma[i][x][y]=='.'){
					if(used[i][x][y]==0) {
						used[i][x][y]=1;
						//cout<<k<<"\n";
						cnt++;
					}
				}
				else {
					d=(d+1)%4;
					y=y+1;
					//cout<<k<<" ";
				}
				k--;
			}
			else{
				x=x-1;
				if(x>=1&&x<=n&&y>=1&&y<=m&&ma[i][x][y]=='.'){
					if(used[i][x][y]==0) {
						used[i][x][y]=1;
						//cout<<k<<"\n";
						cnt++;
					}
				}
				else {
					d=(d+1)%4;
					x=x+1;
					//cout<<k<<" ";
				}
				k--;
			}	
		}
		fout<<cnt<<"\n";
	}
	return 0; 
}
