#include<bits/stdc++.h>
using namespace std;
int T;
int Move[5][3]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,k,x,y,d;
bool Map[10005][10005];
bool visited[10005][10005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int p=0;p<T;p++){
		int res=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char t;
				visited[i][j]=0;
				cin>>t;
				if(t=='.'){Map[i][j]=0;}
				if(t=='x'){Map[i][j]=1;}}}
		visited[x][y]=1,res++;
		for(int i=0;i<k;i++){
			int dx=Move[d][0];
			int dy=Move[d][1];
			if((1<=(x+dx)&&(x+dx)<=n)&&(1<=(y+dy)&&(y+dy)<=m)){
				if(Map[x+dx][y+dy]!=1){x+=dx,y+=dy;}
				else{d=(d+1)%4;}}
			else{d=(d+1)%4;}
			if(!visited[x][y]){
				visited[x][y]=1,res++;}}
		cout<<res<<endl;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
