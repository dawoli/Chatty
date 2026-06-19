#include<cstdio>
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int e, n, m, k, x, y, d, o, p, s;
	bool a[1001][1001], b[1001][1001];
	char t;
	scanf("%d", &e);
	while(e--){
		s=1;
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		x--;
		y--;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				a[i][j]=0;
				b[i][j]=0;
				scanf(" %c", &t);
				if(t=='x'){
					b[i][j]=1;
				}
			}
		}
		a[x][y]=1;
		while(k--){
			if(d==0){
				o=x;
				p=y+1;
			}
			else if(d==1){
				o=x+1;
				p=y;
			}
			else if(d==2){
				o=x;
				p=y-1;
			}
			else if(d==3){
				o=x-1;
				p=y;
			}
			if(o>=n||o<0||p>=m||p<0){
				d=(d+1)%4;
			}
			else if(b[o][p]){
				d=(d+1)%4;
			}
			else{
				x=o;
				y=p;
				if(!a[x][y]){
					a[x][y]=1;
					s++;
				}
			}
			//printf("%d %d %d %d %d %d\n", o, p, x, y, d, s);
		}
		printf("%d\n", s);
	}
	return 0;
}
