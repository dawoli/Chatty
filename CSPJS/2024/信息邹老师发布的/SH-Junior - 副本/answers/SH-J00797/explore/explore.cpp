#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define s(a,b) s[a][b]
int P;
int forcnt,i,j;

int n,m,k;
char s[1005][1005];int ju[1005][1005];
int x,y,d,cnt;


int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&P);
	f(forcnt,0,P){
		cnt = 0;
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		f(i,1,n+1){
			f(j,1,m+1){
				cin>>s[i][j];
				ju[i][j] = 0;
			}
		}
		ju[x][y] = 1;cnt++;
		f(i,0,k){
			if(d == 0){
				if(s(x, ++y)=='x' or y > m){
					y--;
					d = (d+1)%4;
				}
			}
			else if(d == 1){
				if(s(++x, y)=='x' or x > n){
					x--;
					d = (d+1)%4;
				}
			}
			else if(d == 2){
				if(s(x, --y)=='x' or y <= 0){
					y++;
					d = (d+1)%4;
				}
			}
			else if(d == 3){
				if(s(--x, y)=='x' or x <= 0){
					x++;
					d = (d+1)%4;
				}
			}
			if(ju[x][y]==0){
				cnt++;ju[x][y] = 1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
