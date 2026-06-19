#include<iostream>
#include<cstdio>
#include<algorithm>
bool a[1000][1000]={false};
char c[1000][1000];
int ans=0;
int dfs(int n,int m,int k){
	std::cin>>n>>m>>k;
	int x,y,d;
	std::cin>>x>>y>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		std::cin>>c[i][j];
	}
	a[x][y]=true;
	for(int i=k;i>0;i--){
		if(d==0&&c[x][y+1]=='.')c[x][y+1]=true;
		else if(d==1&&c[x+1][y]=='.')c[x+1][y]=true;
		else if(d==2&&c[x][y-1]=='.')c[x][y-1]=true;
		else if(d==3&&c[x-1][y]=='.')c[x-1][y]=true;
		else if(d==0&&(c[x][y+1]=='x'||y+1>m))d=(d+1)%4;
		else if(d==1&&(c[x+1][y]=='x'||x+1>n))d=(d+1)%4;
		else if(d==2&&(c[x][y-1]=='x'||y-1<1))d=(d+1)%4;
		else if(d==3&&(c[x-1][y]=='x'||x-1<1))d=(d+1)%4;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j]==true)ans++;
		}
	}
	return ans;
}
int main(){
	freopen("explore.in","r"stdin);
	freopen("explore.out","w",stdout);
	int t;
	std::cin>>t;
	for(int i=0;i<t;i++){
		std::cout<<dfs()<<"\n";
	}
}
