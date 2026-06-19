#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
int P1;
int forcnt,i,j,k1,l;


const int N = 2e4+10,T = 2e4+10;


int p[T][N];
int n,k,q;
bool nexto[N][110];int ju[N][110];
int y,c;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&P1);
	f(forcnt,1,P1+1){
		scanf("%d %d %d",&n,&k,&q);
		nexto[1][0] = forcnt;
		f(i,1,n+1){
			scanf("%d",&p[i][0]);
			f(j,1,p[i][0] + 1){
				scanf(" %d",&p[i][j]);
			}
		}
		f(i,0,110){
			for(j;0;n+1){
				nexto[j][i]=0;
				ju[j][i] = 0;
			}
		}
		f(i,0,110){
			f(j,1,n+1){
				f(k1,1,p[j][0]+1){
					if(nexto[p[j][k1]][i]==forcnt){
						if(ju[p[j][k1]][i]!=j||ju[p[j][k1]][i]==-1)
							f(l,1,k){
								if(k1+l>p[j][0]){
									break;
								}
								nexto[p[j][k1+l]][i+1] = 1;
								if(ju[p[j][k1+l]][i+1]==j || ju[p[j][k1+l]][i+1]==0){
									ju[p[j][k1+l]][i+1]=j;
								}else if(ju[p[j][k1+l]][i+1]!=0){
									ju[p[j][k1+l]][i+1]=-1;
								}
							}
					}
				}
			}
		}
		f(i,0,q){
			scanf("%d %d",&y,&c);
			if(nexto[c][y] == 1){
				printf("%d ",nexto[c][y]);
			}else{
				printf("0 ");
			}
		}
	} 
	return 0;
}
