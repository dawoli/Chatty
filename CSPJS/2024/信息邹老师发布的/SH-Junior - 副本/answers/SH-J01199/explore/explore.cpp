#include<cstring>
#include<cstdio>
const int N=1010;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int _,n,m,k,res,x,y,dir;
// g[i][j]=true: the robot can get to (i,j)
// g[i][j]=false: the robot can not get to (i,j)
bool g[N][N],st[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&_);
	while(_--){
		memset(g,false,sizeof g);
		memset(st,false,sizeof st);
		res=0;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&dir);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char ch=getchar();
				while((ch!='x')&&(ch!='.'))
					ch=getchar();
				g[i][j]=(ch=='.');
			}
		st[x][y]=true;
		while(k--){
			int a=x+dx[dir],b=y+dy[dir];
			bool flag=true;
			if((a<1)||(a>n)||(b<1)||(b>m))
				flag=false;
			if(!g[a][b])
				flag=false;
			if(flag){
				x=a;
				y=b;
			}
			if(!flag)
				dir=(dir+1)%4;
			st[x][y]=true;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(st[i][j])
					res++;
		printf("%d\n",res);
	}
	return 0;
}
