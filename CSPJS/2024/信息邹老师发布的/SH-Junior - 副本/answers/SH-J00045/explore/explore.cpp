#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int Q[6];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int q=1;q<=T;q++){
		int n,m,k,x,y,d,b=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		a[x][y]='1';
		for(int i=1;i<=k;i++){
			if(d==0&&(a[x][y+1]=='1'||a[x][y+1]=='.')){
				y+=1;
				if(a[x][y]=='.') b++;
				a[x][y]='1';
			}
			else if(d==1&&(a[x+1][y]=='1'||a[x+1][y]=='.')){
				x+=1;
				if(a[x][y]=='.') b++;
				a[x][y]='1';
			}
			else if(d==2&&(a[x][y-1]=='1'||a[x][y-1]=='.')){
				y-=1;
				if(a[x][y]=='.') b++;
				a[x][y]='1';
			}
			else if(d==3&&(a[x-1][y]=='1'||a[x-1][y]=='.')){
				x-=1;
				if(a[x][y]=='.') b++;
				a[x][y]='1';
			}
			else d=(d+1)%4;
		}
		Q[q]=b;
	}
	for(int i=1;i<=T;i++){
		cout<<Q[i]<<endl;
	}
	return 0;
}
