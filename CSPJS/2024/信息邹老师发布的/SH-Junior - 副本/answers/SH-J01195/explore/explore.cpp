#include<iostream>
#include<fstream>
std::ifstream fin("explore.in");
std::ofstream fout("explore.out");
int main(){
	int t;
	fin>>t;
	int sum[t];
	int n[t],m[t],d[t],x[t],y[t],k[t];
	char map[t][1001][1001];
	for(int i=1;i<=t;i++){
		fin>>n[i]>>m[i]>>k[i];
		fin>>x[i]>>y[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			for(int f=1;f<=m[i];f++){
				std::cin>>map[i][j][f];
			}
		}
	}for(int i=1;i<=t;i++){
		for(int j=1;j<=m[i];j++){
			for(int f=1;f<=n[i];f++){
			    if(map[i][j+1][f]=='x' || map[i][j][f+1]=='x' || map[i][j-1][f]=='x' || map[i][j][f-1]=='x' )break;
				if((map[i][j+1][f]=='.' || map[i][j][f+1]=='.' || map[i][j-1][f]=='.' || map[i][j][f-1]=='.' ) && k[i]!=0){
					if(map[i][j+1][f]=='.'){
						if(d[i]=1){
						sum[i]++;
						k[i]--;
						}
						else if(d[i]==0){
							sum[i]++;
							k[i]-=2;
						}
						else{
							sum[i]++;
							k[i]-=d[i];
						} 
						d[i]=1;
						j=j+1;
					}
					else if(map[i][j][f+1]=='.'){
						if(d[i]=0){
							sum[i]++;
							k[i]--;
						}
						else{
							sum[i]++;
							k[i]-=d[i];
						} 
						d[i]=0;
						f=f+1;
					}
					else if(map[i][j-1][f]=='.'){
						if(d[i]=3){
							sum[i]++;
							k[i]--;
						}
						else{
							sum[i]++;
							k[i]-=4-d[i];
						} 
						d[i]=3;
						j=j-1;
					}
					else if(map[i][j][f-1]=='.'){
						if(d[i]=2){
							sum[i]++;
							k[i]--;
						}
						else if(d[i]<2){
							sum[i]++;
							k[i]-=3-d[i];
						}
						else{
						    sum[i]++;
						    k[i]-=1;
						} 
						d[i]=2;
						f=f-1;
					}
				}
				
			}
		}
	
	}
	for(int i=1;i<=t;i++){
		fout<<sum[i]-1<<"\n";
	}	
} 
