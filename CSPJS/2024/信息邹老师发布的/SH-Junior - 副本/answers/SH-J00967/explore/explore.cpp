#include<bits/stdc++.h>
using namespace std;
long long tn;
long long n,m,k;
long long x,y,d;//d0dong-you,d1nan-xia,d2xi-zuo,d3bei-shang
char c[1145][1145]={0};
int curx,cury;
bool bo[1145][1145]={0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&tn);
	while(tn--){
		
		long long cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>c[i][j];
			}
		}
		bo[x][y]=1;
		curx=x;
		cury=y;
		while(k){
			
			if(d==0){
				if(c[curx][cury+1]!='.'){
					d=1;
					k--;
				}else{
					cury+=1;
					bo[curx][cury]=1;
					k--;
				}
			}else if(d==1){
				if(c[curx+1][cury]!='.'){
					d=2;
					k--;
				}else{
					curx+=1;
					bo[curx][cury]=1;
					k--;
				}
			}else if(d==2){
				if(c[curx][cury-1]!='.'){
					d=3;
					k--;
				}else{
					cury-=1;
					bo[curx][cury]=1;
					k--;
				}
			}else if(d==3){
				if(c[curx-1][cury]!='.'){
					d=0;
					k--;
				}else{
					curx-=1;
					bo[curx][cury]=1;
					k--;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(bo[i][j]==1){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				c[i][j]=0;
				bo[i][j]=0;
			}
		}
	}
	return 0;
}

