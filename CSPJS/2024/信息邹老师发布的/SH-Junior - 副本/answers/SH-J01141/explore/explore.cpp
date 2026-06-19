#include<bits/stdc++.h>
using namespace std;
int q;
int n , m , k;
int x0 , y0 , d0;
int visit[1005][1005];
char a[1005][1005];
int aq[1005][1005];
int ans;
int main(){
	scanf("%d" , &q);
	for(int w = 1; w <= q; w ++){
		scanf("%d%d%d" , &n,&m, &k);
		scanf("%d%d%d" , &x0 , &y0 , &d0);
		visit[x0][y0] = 1;
		for(int i = 1; i <= n; i ++){
			scanf("%s" , a[i]);
		}
		for(int i = 1; i <= n; i ++){
			for(int j = 0; j <= m - 1; j ++){
				if(a[i][j] == '.'){
					aq[i][j + 1] = 0;
				}else{
					aq[i][j + 1] = 1;
				}
			}
		}
		for(int i = 1; i <= k ; i ++){
			if(d0 == 0){
				if(aq[x0][y0 + 1] == 0 &&  y0+1 < m + 1){
					visit[x0][y0 + 1] = 1;
					y0 += 1;
				}else{
					d0 = (d0 + 1) % 4;
				}
			}else if(d0 == 1){
				if(aq[x0 + 1][y0] == 0 && x0+1 < n + 1){
					visit[x0 + 1][y0] = 1;
					x0 += 1;
				}else{
					d0 = (d0 + 1) % 4;
				}
			}else if(d0 == 2){
				if(aq[x0][y0 - 1] == 0 && y0-1 > 0){
					visit[x0][y0 - 1] = 1;
					y0 -= 1;
				}else{
					d0 = (d0 + 1) % 4;
				}
			}else if(d0 == 3){
				if(aq[x0 - 1][y0] == 0 && x0-1 > 0){
					visit[x0 - 1][y0] = 1;
					x0 -= 1;
				}else{
					d0 = (d0 + 1) % 4;
				}
			}
		}
		for(int i = 1; i <= n ; i ++){
			for(int j = 1; j <= m ; j ++){
				if(visit[i][j] == 1){
					ans ++;
				}
				visit[i][j] = 0;
				aq[i][j] = 0;
			}
		}
		printf("%d\n" , ans);
		ans = 0;
	}
	return 0;
}
