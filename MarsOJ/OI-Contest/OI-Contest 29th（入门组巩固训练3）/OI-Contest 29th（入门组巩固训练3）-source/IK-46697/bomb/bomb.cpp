#include <bits/stdc++.h>

using namespace std;
int t,n,m,fx[]={1,0,-1,0,1};
char a[1005][1005];
int dp[1005][1005][2];
int read();
void write(int n);
void dfs(int deep,int x,int y,int zy);
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
    t=read();
    for(int i=1;i<=t;i++){
	
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j][0]=dp[i][j][1]=2147483647;
				
			}
		}
	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				
				cin>>a[i][j];
			}
		}
		dp[1][1][0]=dp[1][1][1]=0;
		
		dfs(0,1,1,0);
		
		write(dp[n][m][0]);
		putchar(' ');
		write(dp[n][m][1]);
		putchar('\n');
	}
    return 0;
}

int read(){
    int x,y=1;char c;
    while((c=getchar())<'0'||c>'9') if(c=='-') y=-1;
    x=(c^48);
    while((c=getchar())>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48);
    return x*y;
}

void write(int n){
    if(n<0) putchar('-'),n=-n;
    if(n>9) write(n/10);
    putchar(n%10+48);
}

void dfs(int deep,int x,int y,int zy){
	if(x==n&&y==m){
		return;
	}
	for(int i=0;i<4;i++){
		int nx=x+fx[i],ny=y+fx[i+1];
		
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='*'){
			
			int p=(a[nx][ny]=='$')+zy;
			if((p<dp[nx][ny][0])||(p==dp[nx][ny][0]&&deep+1<dp[nx][ny][1])){
				dp[nx][ny][0]=p;
				dp[nx][ny][1]=deep+1;
				dfs(deep+1,nx,ny,p);
			}
		}
	}
}


