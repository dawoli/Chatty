#include <bits/stdc++.h>
using namespace std;
struct node {
	char name;
	bool f;
};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","W",stdout);
	int n;
	cin >> n;
	for(int ii = 1;ii <= n;ii++){
		node a[1010][1010] = {};
		int n,m,k,x,y,z,ans = 1;
		cin >> n >> m >> k >> x >> y >> z;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> a[i][j].name;
				a[i][j].f = 0;
			}
		}
		while(k > 0){
			k--;
			if(z == 0){
				if(y+1 <= m && a[x][y+1].name != 'x'){
					if(a[x][y+1].f == 0){
						ans++;
						a[x][y+1].f = 1;
					}
					y++;
				}
				else z = (z+1) % 4;
			}
			else if(z == 2){
				if(y-1 >= 1 && a[x][y-1].name != 'x'){
					if(a[x][y-1].f == 0){
						ans++;
						a[x][y-1].f = 1;
					}
					y--;
				}
				else z = (z+1) % 4;
			}
			else if(z == 3){
				if(x-1 >= 1 && a[x-1][y].name != 'x'){
					if(a[x-1][y].f == 0){
						ans++;
						a[x-1][y].f = 1;
					}
					x--;
				}
				else z = (z+1) % 4;
			}
			else{
				if(x+1 <= n && a[x+1][y].name != 'x'){
					if(a[x+1][y].f == 0){
						ans++;
						a[x+1][y].f = 1;
					}
					x++;
				}
				else z = (z+1) % 4;
			}
		}
		cout << ans << endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
