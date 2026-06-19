#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int T;
int n, m, k;
int x, y, d;


int main(int argc, char** argv) {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	char mp[1001][1001];
	cin>>T;
	for(int t = 0; t < T; t++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i = 1; i <= n;i++){
			string l;
			cin>>l;
			for (int j = 1; j <= m; j ++){
				mp[i][j] = l[j - 1];
			}
		}
		mp[x][y]= 'o';
		for (int i = 0;i < k; i++){
			int nx, ny;
			if(d==0){
				nx=x;
				ny=y+1;
			}
			else if(d==1){
				nx=x+1;
				ny=y;
			}
			else if(d==2){
				nx=x;
				ny=y-1;
			}
			else{
				nx=x-1;
				ny=y;
			}
			if (nx>n or ny > m or nx <= 0 or ny <= 0){
				d = (d+1)%4;
				continue;
			}
			else if(mp[nx][ny] == '.' or mp[nx][ny] == 'o'){
				x = nx;
				y = ny;
				mp[x][y]= 'o';
				continue;
			}
			else{
				d = (d+1)%4;
				continue;
			}
		}
		int num = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if(mp[i][j] == 'o'){
					num ++;
				}
			}
		}
		cout<<num<<'\n';
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
