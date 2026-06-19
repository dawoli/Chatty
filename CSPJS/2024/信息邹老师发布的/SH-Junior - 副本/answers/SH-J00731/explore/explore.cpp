#include <bits/stdc++.h>
using namespace std;
int T,m,n,k,x0,y0,d0,b[1010][1010]= {},fx[5] = {0,1,0,-1},fy[5] ={1,0,-1,0},cnt = 0, ans[10];
char a[1010][1010];
void dfs(int x,int y,int d){
	if(cnt == k) return;
	b[x][y] = 1;cnt++;
	int f = d/4;
	int dx = x + fx[f];
	int dy = y + fy[f];
	if(dx >=1 && dx <= n && dy >= 0 && dy <= m && a[dx][dy] == '.'){
		if(b[dx][dy] != 1){
			cnt ++;
			b[dx][dy] = 1;
			k++;
		}
		dfs(dx,dy,d);
	}
	else{
		int newd = d +1;
		k++;
		dfs(x,y,newd);
	}
	
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T ;
	for(int i = 1;i <= T;i++){
		cin >> n >> m >> k;
		cin >> x0 >> y0  >> d0;
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= m;k++)
				cin >> a[j][k];
				
		}
		dfs(x0,y0,d0);
		ans[i] = cnt;
		cnt = 0;
	}
	for(int i = 1;i <= T ;i++)
		cout << ans[i] << endl;

	
	
	
	return 0;
}

