#include<cstdio>
#include<cstring>
const int N = 1010;
char mp[N][N];
int n,m,k,sx,sy,sd,b[N][N],answer;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		memset(b,0,sizeof(b));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&sx,&sy,&sd);
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
		}
		b[sx][sy]=1;
		while(k>0){
			k--;
			switch(sd){
				case 0:{
					if(sy+1<=m && mp[sx][sy+1]=='.'){
						sy++;
						b[sx][sy]=1;
					}
					else{
						sd=(sd+1)%4;
					}
					break;
				}
				case 1:{
					if(sx+1<=n && mp[sx+1][sy]=='.'){
						sx++;
						b[sx][sy]=1;
					}
					else{
						sd=(sd+1)%4;
					}
					break;
				}
				case 2:{
					if(sy-1>=1 && mp[sx][sy-1]=='.'){
						sy--;
						b[sx][sy]=1;
					}
					else{
						sd=(sd+1)%4;
					}
					break;
				}
				case 3:{
					if(sx-1>=1 && mp[sx-1][sy]=='.'){
						sx--;
						b[sx][sy]=1;
					}
					else{
						sd=(sd+1)%4;
					}
					break;
				}
			}
		}
		answer=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]==1){
					answer++;
				}
			}
		}
		printf("%d\n",answer);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
