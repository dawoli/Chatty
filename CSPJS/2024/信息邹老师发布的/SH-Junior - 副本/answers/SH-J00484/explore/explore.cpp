#include<iostream>
#include<cstring>
using namespace std;
char l[1000][1000];
bool zou[1000][1000];
int ji=0,k; 
void g(){
	for(int i=0;i<=999;i++){
		for(int j=0;j<=999;j++){
			l[i][j]='x';
			zou[i][j]=true;
		}
	}
}
void suan(int a,int b,int c,int d){
	if(d>=k)return;
	if(c==0&&l[a][b+1]=='.'){
		if(zou[a][b+1]==false){
			ji++;
			zou[a][b+1]=true;
		}
		suan(a,b+1,c,d+1);
		return;
	}
	else if(c==1&&l[a+1][b]=='.'){
		if(zou[a+1][b]==false){
			ji++;
			zou[a+1][b]=true;
		}
		suan(a+1,b,c,d+1);
		return;
	}
	else if(c==2&&l[a][b-1]=='.'){
		if(zou[a][b-1]==false){
			ji++;
			zou[a][b-1]=true;
		}
		suan(a,b-1,c,d+1);
		return;
	}
	else if(c==3&&l[a-1][b]=='.'){
		if(zou[a-1][b]==false){
			ji++;
			zou[a-1][b]=true;
		}
		suan(a-1,b,c,d+1);
		return;
	}
	else{
		suan(a,b,(c+1)%4,d+1);
		return;	
	}
}
int main(){
	int n,m,x,y,d,t;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		g();
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>l[i][j];
				zou[i][j]=false;
			}
		}
		zou[x-1][y-1]=true;
		suan(x-1,y-1,d,0);
		ji++;
		cout<<ji<<endl;	
		ji=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
