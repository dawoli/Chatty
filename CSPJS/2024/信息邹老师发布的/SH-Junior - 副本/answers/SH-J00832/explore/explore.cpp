#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10,M=1e3+10;
int T,n,m,k,x,y,d,r,t;
string s;
char c[N][M];
bool f[N][M];
int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
void print(){
	if(r!=0) return; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]) r++;
		}
	}
	cout<<r<<"\n";
	return;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		r=0;
		memset(f,false,sizeof(f));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		f[x][y]=true;
		while(t<k){
			t+=1;
			int tx=x+fx[d],ty=y+fy[d];
			if(c[tx][ty]=='.'){
				x=tx;
				y=ty;
				f[x][y]=true;
			}else{
				d=(d+1)%4;
			}
		}
		print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

